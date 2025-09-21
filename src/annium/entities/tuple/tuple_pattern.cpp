//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_pattern.hpp"

#include "sonia/small_vector.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

namespace annium {

class tuple_match_descriptor : public functional_match_descriptor
{
public:
    using functional_match_descriptor::functional_match_descriptor;
    
    small_vector<std::pair<annotated_identifier, entity_identifier>, 8> fields;
};

// tuple($args ... : _ ...)
std::expected<functional_match_descriptor_ptr, error_storage> tuple_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();
    entity_identifier veid = e.get(builtin_eid::void_);
    auto pmd = make_shared<tuple_match_descriptor>();

    for (auto const& arg : call.args) { // { argname, expr }
        annotated_identifier const* pargname = arg.name();
        auto res = apply_visitor(
            base_expression_visitor{ ctx, call.expressions, expected_result_t{.modifier = value_modifier_t::constexpr_value } },
            arg.value());
        if (!res) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(pargname ? pargname->location : get_start_location(arg.value()), "argument error"sv, arg.value()),
                std::move(res.error())
            ));
        }
        
        if (res->first.value() == veid) {
            continue; // ignore argument
        }
        if (res->first.expressions) {
            THROW_NOT_IMPLEMENTED_ERROR("tuple_pattern::try_match: expressions for const value");
        }
        pmd->fields.emplace_back(pargname ? *pargname : annotated_identifier{}, res->first.value());
    }

    return pmd;
}

std::expected<syntax_expression_result, error_storage> tuple_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t&, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    entity_identifier typename_eid = e.get(builtin_eid::typename_);
    auto& tmd = static_cast<tuple_match_descriptor&>(md);
    
    entity_signature result_signature{ e.get(builtin_qnid::tuple), typename_eid };
    
    for (auto const& [name, eid] : tmd.fields) {
        entity const& ent = e.eregistry_get(eid);
        result_signature.emplace_back(name.value, eid, ent.get_type() != typename_eid);
    }
    indirect_signatured_entity smpl{ result_signature };
    entity const& entres = ctx.env().eregistry_find_or_create(smpl, [&result_signature]() {
        return make_shared<basic_signatured_entity>(std::move(result_signature));
    });
    
    return syntax_expression_result{
        .value_or_type = entres.id,
        .is_const_result = true
    };
}

}
