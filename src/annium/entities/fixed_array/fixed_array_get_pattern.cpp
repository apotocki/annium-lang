//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "fixed_array_get_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

#include "sonia/utility/scope_exit.hpp"

namespace annium {

namespace {

// Recursively folds a compile-time-known composite constant (nested fixed arrays,
// tuples, or a structure - which currently reduces to its underlying tuple - down
// to literal scalars) into a single self-contained runtime blob.
//
// Every entity reachable from here is, by construction, one whose constant-ness
// was established by some other pattern's `apply()` (fixed_array_make_pattern,
// tuple_make_pattern, ...). A *constexpr union value* can likewise never be one
// of them - to_union_implicit_cast_pattern::apply always yields a runtime
// (non-const) result (see FUTURE_WORK.md) - but fixed_array_make_pattern now
// deliberately does *not* route a heterogeneous array's constant elements
// through that cast at all: it stores each element under its own narrower
// native type in the `data` composite, leaving the array's declared element
// type (`of`) as the union. So a constant array element here is never itself
// "a union value" - it can, however, need to be *presented* as one, when the
// array's declared element type is a union: reshaped into `[value, which]`
// for a type case, or (mirroring to_union_implicit_cast_pattern::apply's
// `exact_case` branch) into `[nil, which]` for an exact const case in a union
// that also has type cases, or into a bare `which` with no payload at all
// when *every* case in the union is a fixed const value (an enum-style
// union, same as to_union_implicit_cast_pattern::apply's `enum_union`
// branch) - there's no constexpr union entity to recurse into or cast
// through, so this reshaping is done inline below, directly at the blob level.
// Anything else this function fails to recognize signals a real bug - either
// a new kind of compile-time constant was introduced elsewhere without
// teaching this function about it, or one of the invariants above no longer
// holds - and must be fixed at the source, not papered over here.
smart_blob materialize_const_blob(environment& env, entity_identifier eid)
{
    entity const& ent = get_entity(env, eid);
    if (auto const* lit = dynamic_cast<generic_literal_entity const*>(&ent)) {
        return lit->value();
    }

    entity_signature const* psig = ent.signature();
    if (!psig) {
        // A fully-const tuple (and, currently, a fully-const structure, which
        // reduces to its underlying tuple) is represented as an `empty_entity`
        // whose *type* carries the field values, not the value entity itself.
        entity const& type_ent = get_entity(env, ent.get_type());
        psig = type_ent.signature();
    }
    if (!psig || (psig->name != env.get(builtin_qnid::data) && psig->name != env.get(builtin_qnid::tuple))) {
        THROW_NOT_IMPLEMENTED_ERROR("fixed_array_get_pattern: unrecognized constant array element kind"sv);
    }

    // If this is a fixed array's `data` composite and its declared element type
    // is a union, individual elements may be stored under a narrower concrete
    // type (or, for an explicit enum-style union, under one of its exact const
    // case values) than that union - fetch the union's signature once, up
    // front, so each element below can be reshaped into the matching runtime
    // union layout.
    entity_signature const* union_sig = nullptr;
    bool is_enum_union = false; // every case is a fixed const value - see to_union_implicit_cast_pattern
    if (psig->name == env.get(builtin_qnid::data)) {
        BOOST_ASSERT(psig->result);
        entity_signature const* arr_sig = get_entity(env, psig->result->entity_id()).signature();
        BOOST_ASSERT(arr_sig && arr_sig->name == env.get(builtin_qnid::array));
        field_descriptor const* elem_of_fd = arr_sig->find_field(env.get(builtin_id::of));
        BOOST_ASSERT(elem_of_fd);
        entity_signature const* maybe_union_sig = get_entity(env, elem_of_fd->entity_id()).signature();
        if (maybe_union_sig && maybe_union_sig->name == env.get(builtin_qnid::union_)) {
            union_sig = maybe_union_sig;
            is_enum_union = std::ranges::all_of(union_sig->fields(), [](field_descriptor const& ufd) { return ufd.is_const(); });
        }
    }

    small_vector<blob_result, 16> elem_blobs;
    elem_blobs.reserve(psig->fields().size());
    SCOPE_EXIT([&elem_blobs] {
        for (blob_result& br : elem_blobs) {
            blob_result_unpin(&br);
        }
    });
    for (field_descriptor const& fld : psig->fields()) {
        BOOST_ASSERT(fld.is_const());
        if (!union_sig) {
            elem_blobs.push_back(materialize_const_blob(env, fld.entity_id()).detach());
            continue;
        }

        // Mirror to_union_implicit_cast_pattern::try_match's two-phase match:
        // first an exact case (a const union field whose value equals this
        // element's own value), then a type case (a non-const union field
        // whose type equals this element's own type).
        auto const_it = std::ranges::find_if(union_sig->fields(), [val = fld.entity_id()](field_descriptor const& ufd) {
            return ufd.is_const() && ufd.entity_id() == val;
        });
        if (const_it != union_sig->fields().end()) {
            size_t which = static_cast<size_t>(std::distance(union_sig->fields().begin(), const_it));
            if (is_enum_union) {
                // No other case in this union carries a payload either, so the
                // runtime shape is uniformly just the case index - no pair.
                elem_blobs.push_back(ui64_blob_result(which));
            } else {
                // Some other case in this union *does* carry a payload, so the
                // runtime shape must stay uniformly `[value, which]` - this
                // element's own value is redundant with `which` here (its
                // matched case is itself a fixed const value), so a nil
                // placeholder is pushed instead, matching
                // to_union_implicit_cast_pattern::apply's `exact_case` branch.
                small_vector<blob_result, 2> pair{ smart_blob{}.detach(), ui64_blob_result(which) };
                SCOPE_EXIT([&pair] {
                    for (blob_result& br : pair) {
                        blob_result_unpin(&br);
                    }
                });
                smart_blob wrapped{ array_blob_result(span{ pair }, true) };
                pair.clear(); // ownership moved into `wrapped`
                elem_blobs.push_back(wrapped.detach());
            }
            continue;
        }

        entity_identifier elem_native_type = get_entity(env, fld.entity_id()).get_type();
        auto type_it = std::ranges::find_if(union_sig->fields(), [elem_native_type](field_descriptor const& ufd) {
            return !ufd.is_const() && ufd.entity_id() == elem_native_type;
        });
        if (type_it == union_sig->fields().end()) {
            THROW_NOT_IMPLEMENTED_ERROR("fixed_array_get_pattern: constant array element's type is not one of the array's declared union element cases"sv);
        }
        size_t which = static_cast<size_t>(std::distance(union_sig->fields().begin(), type_it));
        BOOST_ASSERT(!is_enum_union); // an all-const union has no non-const (type) cases to land here

        small_vector<blob_result, 2> pair{ materialize_const_blob(env, fld.entity_id()).detach(), ui64_blob_result(which) };
        SCOPE_EXIT([&pair] {
            for (blob_result& br : pair) {
                blob_result_unpin(&br);
            }
        });
        smart_blob wrapped{ array_blob_result(span{ pair }, true) };
        pair.clear(); // ownership moved into `wrapped`
        elem_blobs.push_back(wrapped.detach());
    }
    smart_blob result{ array_blob_result(span{ elem_blobs }, true) };
    elem_blobs.clear(); // SCOPE_EXIT will no longer unpin them, since the array blob now owns them
    return result;
}

} // namespace

class fixed_array_get_match_descriptor : public functional_match_descriptor
{
public:
    inline fixed_array_get_match_descriptor(prepared_call const& call, entity_signature const& arr_type_sig_val) noexcept
        : functional_match_descriptor{ call }
        , arr_type_sig{ arr_type_sig_val }
    {
    }

    entity_signature const& arr_type_sig;
};

std::expected<functional_match_descriptor_ptr, error_storage> fixed_array_get_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    auto call_session = call.new_session(ctx);

    auto slf_arg_descr = call_session.get_named_argument(builtin_id::self);
    if (!slf_arg_descr) return std::unexpected(std::move(slf_arg_descr.error()));

    resource_location const& slfargloc = slf_arg_descr->expression->location;
    syntax_expression_result& slf_arg_er = slf_arg_descr->result;
    entity_identifier slftype = get_result_type(env, slf_arg_er);
    
    entity const& slf_type_entity = get_entity(env, slftype);
    entity_signature const* psig = slf_type_entity.signature();
    if (!psig || psig->name != env.get(builtin_qnid::array)) {
        return std::unexpected(make_error<type_mismatch_error>(slfargloc, slftype, "an array"sv));
    }

    auto prop_arg_descr = call_session.get_named_argument(builtin_id::property, builtin_eid::integer);
    if (!prop_arg_descr) return std::unexpected(std::move(prop_arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    shared_ptr<fixed_array_get_match_descriptor> pmd = make_shared<fixed_array_get_match_descriptor>(call, *psig);
    
    pmd->append_arg(env.get(builtin_id::self), slf_arg_er, slfargloc);
    pmd->append_arg(env.get(builtin_id::property), prop_arg_descr->result, prop_arg_descr->expression->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage> fixed_array_get_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& env = ctx.env();
    auto& amd = static_cast<fixed_array_get_match_descriptor&>(md);
    auto& slfer = get<1>(md.matches[0]);
    auto& proper = get<1>(md.matches[1]);

    entity_signature const& sig = amd.arr_type_sig;
    field_descriptor const* of_fd = sig.find_field(env.get(builtin_id::of));
    BOOST_ASSERT(of_fd);
    field_descriptor const* size_fd = sig.find_field(env.get(builtin_id::size));
    size_t array_size = (std::numeric_limits<size_t>::max)();
    if (size_fd) {
        generic_literal_entity const& sz_ent = static_cast<generic_literal_entity const&>(get_entity(env, size_fd->entity_id()));
        array_size = sz_ent.value().as<size_t>();
    }

    optional<size_t> index;
    if (proper.is_const_result) {
        generic_literal_entity const& index_ent = static_cast<generic_literal_entity const&>(get_entity(env, proper.value()));
        index.emplace(index_ent.value().as<size_t>());
        if (*index >= array_size) {
            return std::unexpected(make_error<basic_general_error>(amd.call_location, "array index out of range"sv, proper.value()));
        }
    }

    entity_signature const* datasig = nullptr;
    if (slfer.is_const_result) {
        entity const& slf_data_entity = get_entity(env, slfer.value());
        datasig = slf_data_entity.signature();
        BOOST_ASSERT(datasig && datasig->name == env.get(builtin_qnid::data));
        BOOST_ASSERT(datasig->fields().size() == array_size);
    }

    // Case 1: Both self and property are constant
    if (slfer.is_const_result && proper.is_const_result) {
        return syntax_expression_result{
            .temporaries = {},
            .expressions = {},
            .value_or_type = datasig->field(*index).entity_id(),
            .is_const_result = true
        };
    }
    // Case 2: self is not constant, property is constant
    if (!slfer.is_const_result && proper.is_const_result) {
        syntax_expression_result result{ 
            .value_or_type = of_fd->entity_id(),
            .is_const_result = false
        };
        append_semantic_result(el, slfer, result);

        if (array_size > 1) {
            env.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(*index) } });
            env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::array_at)));
        }

        return result;
    }

    // Case 4: Both self and property are not constant
    if (!slfer.is_const_result && !proper.is_const_result) {
        syntax_expression_result result = slfer;
        if (array_size > 1) {
            append_semantic_result(el, proper, result);
            // Add runtime array access
            env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::array_at)));
        }
        result.value_or_type = of_fd->entity_id();
        return result;
    }

    // Case 3: self is constant, property is not constant
    BOOST_ASSERT(slfer.is_const_result && !proper.is_const_result);

    if (array_size == 1) {
        // A single-element array's only valid index is 0, regardless of the
        // (unevaluated) runtime property value - matches Case 4's rule above.
        return syntax_expression_result{
            .value_or_type = datasig->field(0).entity_id(),
            .is_const_result = true
        };
    }

    {
        syntax_expression_result result{ .value_or_type = of_fd->entity_id(), .is_const_result = false };

        // The array structure is known at compile time, but the index is dynamic:
        // fold the whole (possibly nested) constant array into a single runtime
        // blob and push it once, rather than rebuilding it element by element.
        env.push_back_expression(el, result.expressions, semantic::push_value{ materialize_const_blob(env, slfer.value()) });

        append_semantic_result(el, proper, result);
        env.push_back_expression(el, result.expressions, semantic::invoke_function(env.get(builtin_eid::array_at)));

        return result;
    }
}

}