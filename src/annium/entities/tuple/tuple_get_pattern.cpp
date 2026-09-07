//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_get_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/errors/type_mismatch_error.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> tuple_get_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    // Always resolve self unconstrained first -- never request a reference speculatively, and
    // never inspect self's raw expression. See IMPLEMENTATION_NOTES.md's `ref(T)` section.
    auto slf_arg_descr = call_session.get_named_argument(e.get(builtin_id::self));
    if (!slf_arg_descr) return std::unexpected(std::move(slf_arg_descr.error()));

    entity const* slf_ent = nullptr;
    entity_identifier slftype = get_result_type(e, slf_arg_descr->result, &slf_ent);
    entity_identifier self_ref_of = try_decompose_ref_of(e, slftype); // non-empty => self already IS a reference

    if (!self_ref_of && slf_ent) {
        // self is a constexpr result -- guard against the const VALUE itself being a typename-tuple
        // entity (get(self: (i32,i32), property: 0) naming the type, not a value of it): that's
        // tuple_typename_get_pattern's job, not ours.
        if (auto psig = slf_ent->signature(); psig && psig->name == e.get(builtin_qnid::tuple)) {
            return std::unexpected(make_error<type_mismatch_error>(slf_arg_descr->expression->location, slf_arg_descr->result.value(), "a tuple value (not typename)"sv));
        }
    }

    entity_identifier tuple_type = self_ref_of ? self_ref_of : slftype;
    entity const& tpl_entity = get_entity(e, tuple_type);
    entity_signature const* psig = tpl_entity.signature();
    if (!psig || psig->name != e.get(builtin_qnid::tuple)) {
        return std::unexpected(make_error<type_mismatch_error>(slf_arg_descr->expression->location, tuple_type, "a tuple"sv));
    }
    if (psig->empty()) {
        return std::unexpected(make_error<type_mismatch_error>(slf_arg_descr->expression->location, tuple_type, "a not empty tuple"sv));
    }

    // The whole ref(of: E) this get() call's own caller wants, if any -- independent of self_ref_of
    // (self can already be a reference while THIS call's result still isn't wanted as one).
    entity_identifier expected_ref_type = (exp.type && can_be_runtime(exp.modifier) && try_decompose_ref_of(e, exp.type)) ? exp.type : entity_identifier{};

    if (!self_ref_of && expected_ref_type) {
        // The caller wants a reference and self isn't one yet -- try once more, now asking for
        // ref(of: tuple_type) specifically (same technique as ref_pattern: re-resolve the same
        // argument through the normal, cached path; try_take_reference fires inside that second,
        // ordinary visit if self is a plain variable, and this fails on its own otherwise).
        entity_identifier ref_type = make_ref_of_type(e, tuple_type);
        call_session.reuse_argument(slf_arg_descr->arg_index);
        auto retry = call_session.get_named_argument(e.get(builtin_id::self), expected_result_t{ .type = ref_type, .modifier = value_modifier_t::runtime_value });
        if (!retry) return std::unexpected(std::move(retry.error()));
        slf_arg_descr = std::move(retry);
        self_ref_of = tuple_type;
    }

    prepared_call::argument_descriptor_t prop_arg_descr;
    alt_error prop_errors;
    auto property_arg = call_session.use_named_argument(e.get(builtin_id::property), expected_result_t{ e.get(builtin_eid::integer) }, &prop_arg_descr);
    if (!property_arg) {
        prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
        call_session.reuse_argument(prop_arg_descr.arg_index);
        property_arg = call_session.use_named_argument(e.get(builtin_id::property), expected_result_t{ e.get(builtin_eid::identifier) }, &prop_arg_descr);
    }
    if (!property_arg) {
        if (prop_errors.alternatives.empty()) {
            return std::unexpected(std::move(property_arg.error()));
        } else {
            prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
            return std::unexpected(make_error<alt_error>(std::move(prop_errors)));
        }
    }
    if (!*property_arg) {
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: `property`"sv));
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto pmd = make_shared<tuple_get_match_descriptor>(call, tpl_entity, *tpl_entity.signature());

    pmd->append_arg(slf_arg_descr->result, slf_arg_descr->expression->location);
    pmd->append_arg(prop_arg_descr.result, prop_arg_descr.expression->location);
    pmd->self_ref_of = self_ref_of;
    pmd->expected_ref_type = expected_ref_type;

    return pmd;
}

std::expected<syntax_expression_result, error_storage> tuple_get_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& tmd = static_cast<tuple_get_match_descriptor&>(md);
    auto& slfer = get<1>(md.matches[0]);
    auto& proper = get<1>(md.matches[1]);

    // Helper to build tuple type (identifier, value)
    auto make_named_tuple_type = [&](field_descriptor const& field) -> entity_identifier {
        entity_signature rsig{ e.get(builtin_qnid::tuple), e.get(builtin_eid::typename_) };
        rsig.emplace_back(e.make_identifier_entity(field.name()).id, true);
        rsig.emplace_back(field.entity_id(), field.is_const());
        return e.make_basic_signatured_entity(std::move(rsig)).id;
    };

    auto make_tuple_project_type = [&](identifier id_name) -> entity_identifier {
        entity_signature project_sig{ e.get(builtin_qnid::tuple_project), e.get(builtin_eid::typename_) };
        project_sig.emplace_back(e.make_identifier_entity(id_name).id, true);
        project_sig.emplace_back(tmd.tpl_entity.id, true);
        return e.make_basic_signatured_entity(std::move(project_sig)).id;
    };

    // Case 1: Both self and property are constant
    if (slfer.is_const_result && proper.is_const_result) {
        // we will return slfer as a result, but with modified expressions and type
        entity const& property_entity = get_entity(e, proper.value());
        if (auto int_lit = dynamic_cast<const generic_literal_entity*>(&property_entity)) {
            size_t idx = int_lit->value().as<size_t>();
            if (auto* field = tmd.arg_sig.get_field(idx)) {
                    entity_identifier result_type = field->name() ? make_named_tuple_type(*field) : field->entity_id();
                    slfer.value_or_type = field->name() ? e.make_empty_entity(result_type).id : result_type;
            } else {
                return std::unexpected(make_error<basic_general_error>(tmd.call_location, "tuple index out of range"sv));
            }
        } else if (auto id_lit = dynamic_cast<const identifier_entity*>(&property_entity)) {
            auto frng = tmd.arg_sig.find_fields(id_lit->value());
            if (frng.first == frng.second) {
                return std::unexpected(make_error<basic_general_error>(tmd.call_location, "no such field in tuple"sv, id_lit->value()));
            }
            
            if (auto second = frng.first; ++second == frng.second) {
                // Single field case - return the field value directly
                field_descriptor const& field = tmd.arg_sig.field(frng.first->second);
                slfer.value_or_type = field.entity_id();
            } else {
                slfer.value_or_type = e.make_empty_entity(make_tuple_project_type(id_lit->value())).id;
            }
        } else {
            return std::unexpected(make_error<type_mismatch_error>(tmd.call_location, proper.value(), "an integer or identifier"sv));
        }
        return std::move(slfer);
    }

    // Case 2: self is not constant, property is constant
    if (!slfer.is_const_result && proper.is_const_result) {
        entity const& property_entity = get_entity(e, proper.value());
        entity_identifier result_type;
        const field_descriptor* field = nullptr;

        if (auto int_lit = dynamic_cast<const generic_literal_entity*>(&property_entity)) {
            size_t idx = int_lit->value().as<size_t>();
            field = tmd.arg_sig.get_field(idx);
            if (!field) {
                return std::unexpected(make_error<basic_general_error>(tmd.call_location, "tuple index out of range"sv, property_entity.id));
            }
            if (field->is_const()) {
                if (field->name()) {
                    // If the field is named, return as a named tuple type
                    return syntax_expression_result{
                        .value_or_type = e.make_empty_entity(make_named_tuple_type(*field)).id,
                        .is_const_result = true
                    };
                } else {
                    // If the field is positional and const, return its value directly
                    return syntax_expression_result{
                        .value_or_type = field->entity_id(),
                        .is_const_result = true
                    };
                }
            }
            result_type = field->name() ? make_named_tuple_type(*field) : field->entity_id();
        } else if (auto id_lit = dynamic_cast<const identifier_entity*>(&property_entity)) {
            // Use find_fields to get all fields with this name
            auto frng = tmd.arg_sig.find_fields(id_lit->value());
            if (frng.first == frng.second) {
                return std::unexpected(make_error<basic_general_error>(tmd.call_location, "no such field in tuple"sv, id_lit->value()));
            }
            
            if (auto second = frng.first; ++second == frng.second) {
                // Only one field with this name
                field = &tmd.arg_sig.field(frng.first->second);
                if (field->is_const()) {
                    // If the field is const, return as a constant result
                    return syntax_expression_result{
                        .value_or_type = field->entity_id(),
                        .is_const_result = true
                    };
                }
                result_type = field->entity_id();
            } else {
                // to do: the case when frng fields are all constexpr
                // More than one field with this name: return tuple_project type
                slfer.value_or_type = make_tuple_project_type(id_lit->value());
                slfer.is_const_result = false;
                return std::move(slfer);
            }
        } else {
            return std::unexpected(make_error<type_mismatch_error>(tmd.call_location, proper.value(), "an integer or identifier"sv));
        }

        BOOST_ASSERT(!field->is_const());

        // we will return slfer as a result, but with modified type
        slfer.value_or_type = result_type;

        // Count non-const fields
        size_t non_const_count = 0; 
        // Compute runtime index among non-const fields
        size_t runtime_index = 0;

        auto sp = tmd.arg_sig.fields();
        for (auto it = sp.begin(), eit = sp.end(); it != eit; ++it) {
            const auto& f = *it;
            if (!f.is_const()) {
                ++non_const_count;
                if (field != &f) {
                    ++runtime_index;
                } else if (non_const_count > 1) {
                    break;
                } else {
                    for(++it; it != eit; ++it) {
                        if (!it->is_const()) {
                            ++non_const_count;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        // Ref mode: self is a genuine reference (self is `ref(of: <this tuple's type>)`, either
        // because the caller wrote `ref(t).0` explicitly or because try_match's own retry produced
        // one) -- ref_at turns self's own-storage-aliasing reference into a reference to this one
        // field, without ever copying the tuple. expected_ref_of below is this field's own --
        // unwrapped -- type; NOT result_type, which for a named field is the tuple(name, E) wrapper,
        // not E itself.
        if (tmd.self_ref_of) {
            entity_identifier expected_ref_of = try_decompose_ref_of(e, tmd.expected_ref_type);
            bool want_ref = expected_ref_of && expected_ref_of == field->entity_id();

            syntax_expression_result r = std::move(slfer);
            if (non_const_count > 1) {
                e.push_back_expression(el, r.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(runtime_index) } });
                e.push_back_expression(el, r.expressions, semantic::invoke_function(e.get(builtin_eid::ref_at)));
            }
            // non_const_count == 1: tuple_make_pattern skips arrayify entirely for a tuple's sole
            // runtime field, so the variable's own slot already directly holds the element's raw
            // value -- self's own reference already points at exactly the right thing.
            if (want_ref) {
                r.value_or_type = tmd.expected_ref_type;
                r.is_const_result = false;
                return r;
            }
            // This call's own caller doesn't want (this field's) reference -- dereference back to a
            // plain value, composing the same way bootstrap.ann's own
            // get(self: ~ref(of $T)) => reinterpret(__ref_get(self)) does.
            e.push_back_expression(el, r.expressions, semantic::invoke_function(e.get(builtin_eid::ref_get)));
            r.value_or_type = result_type;
            r.is_const_result = false;
            return r;
        }

        // Optimization: if only one runtime field, just return 'self' with the requested type
        if (non_const_count > 1) {
            e.push_back_expression(el, slfer.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(runtime_index) } });
            e.push_back_expression(el, slfer.expressions, semantic::invoke_function(e.get(builtin_eid::array_at)));
        }

        return std::move(slfer);
    }

    // Case 3: self is constant, property is not constant
    if (slfer.is_const_result && !proper.is_const_result) {
        // The tuple structure is known, but the property is dynamic.
        // We need to produce a union of all possible result types.
        std::vector<entity_identifier> possible_types;
        //bool any_named = false;
        for (const auto& field : tmd.arg_sig.fields()) {
            if (field.name()) {
                //any_named = true;
                // (identifier, value) tuple type
                entity_signature rsig{ e.get(builtin_qnid::tuple), e.get(builtin_eid::typename_) };
                rsig.emplace_back(e.make_identifier_entity(field.name()).id, true);
                rsig.emplace_back(field.entity_id(), field.is_const());
                possible_types.push_back(e.make_basic_signatured_entity(std::move(rsig)).id);
            } else {
                possible_types.push_back(field.entity_id());
            }
        }

        // For simplicity, use the first type if only one, or create a union otherwise
        entity_identifier result_type;
        if (possible_types.size() == 1) {
            result_type = possible_types.front();
        } else {
            result_type = e.make_union_type_entity(possible_types).id;
        }

        // Merge expressions
        semantic::expression_span exprs = el.concat(slfer.expressions, proper.expressions);

        // TODO: Insert runtime selection logic here if needed
        THROW_NOT_IMPLEMENTED_ERROR("Tuple get pattern with const `self` and non-const `property` is not implemented yet."sv);
        return syntax_expression_result{
            .temporaries = std::move(slfer.temporaries),
            .expressions = std::move(exprs),
            .value_or_type = result_type,
            .is_const_result = false
        };
    }

    THROW_NOT_IMPLEMENTED_ERROR("Tuple get pattern with non-const `self` and non-const `property` is not implemented yet."sv);
}

}
