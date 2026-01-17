//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_set_pattern.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/auxiliary.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

class tuple_set_match_descriptor : public functional_match_descriptor
{
    size_t property_index_;

public:
    using functional_match_descriptor::functional_match_descriptor;

    inline size_t property_index() const noexcept { return property_index_; }
    inline void set_property_index(size_t index) noexcept { property_index_ = index; }
};

/**
    inline fn::set(self: tuple(), property: const __identifier @has_property($T), _) -> typeof(self) => implementation defined
*/

std::expected<functional_match_descriptor_ptr, error_storage> tuple_set_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    
    auto call_session = call.new_session(ctx);

    auto slf_arg_descr = call_session.get_named_argument(builtin_id::self);
    if (!slf_arg_descr) return std::unexpected(std::move(slf_arg_descr.error()));

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

    auto prop_val_arg_descr = call_session.get_next_positioned_argument();
    if (!prop_val_arg_descr) return std::unexpected(std::move(prop_val_arg_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    shared_ptr<tuple_set_match_descriptor> pmd = make_shared<tuple_set_match_descriptor>(call);
    auto& ser = slf_arg_descr->result;
    if (ser.is_const_result) {
        return std::unexpected(make_error<basic_general_error>(slf_arg_descr->expression->location, "argument mismatch, expected a mutable tuple"sv, ser.value()));
    }

    entity const& some_entity = get_entity(e, ser.type());
    auto psig = some_entity.signature();
    if (!psig || psig->name != e.get(builtin_qnid::tuple)) {
        return std::unexpected(make_error<type_mismatch_error>(slf_arg_descr->expression->location, ctx.context_type, e.get(builtin_qnid::tuple)));
    }

    pmd->append_arg(e.get(builtin_id::self), ser, slf_arg_descr->expression->location);
    pmd->append_arg(e.get(builtin_id::self), prop_arg_descr.result, prop_arg_descr.expression->location);
    pmd->append_arg(prop_val_arg_descr->result, prop_val_arg_descr->expression->location);
    
    THROW_NOT_IMPLEMENTED_ERROR("tuple_set_pattern::try_match");
#if 0
    entity_signature const* pes = pte->signature();
    BOOST_ASSERT(pes);
    size_t index;
    field_descriptor const* fd;
    if (identifier_entity const* pie = dynamic_cast<identifier_entity const*>(ppname); pie) {
        fd = pes->find_field(pie->value(), &index);
    } else if (integer_literal_entity const* pile = dynamic_cast<integer_literal_entity const*>(ppname); pile) {
        fd = pes->find_field((size_t)pile->value(), &index);
    } else {
        return std::unexpected(make_error<basic_general_error>(ppname->location(), "argument mismatch, expected an identifier or index"sv, ppname->id()));
    }
    
    if (!fd) {
        return std::unexpected(make_error<basic_general_error>(call.location(), "no such field"sv, ppname->id()));
    }

    pmd->set_property_index(index);
    BOOST_ASSERT(pes->field_count() > 1 || !index);

    pmd->result = fd->entity_id();
    return pmd;
#endif
}

std::expected<syntax_expression_result, error_storage> tuple_set_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();

    // push call expressions in the right order
    //semantic::managed_expression_list exprs{ e };
    syntax_expression_result result{ .value_or_type = md.signature.result->entity_id(), .is_const_result = false };

    // only one named argument is expected
    result.expressions = el.concat(result.expressions, get<1>(md.matches.front()).expressions);

    if (size_t propindex = static_cast<tuple_set_match_descriptor&>(md).property_index(); propindex) {
        e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(propindex) } });
        e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::array_at)));
    }

    return result;
}

}
