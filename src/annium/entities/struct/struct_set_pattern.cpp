//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "struct_set_pattern.hpp"
#include "struct_entity.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/auxiliary.hpp"
#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

class struct_set_match_descriptor : public functional_match_descriptor
{
public:
    inline struct_set_match_descriptor(prepared_call const& call, entity_signature const& sig) noexcept
        : functional_match_descriptor{ call }
        , utpl_sig{ sig }
    { }

    entity_signature const& utpl_sig;
    optional<size_t> property_index;
};

/**
    inline fn::set(self: $T @structure, property: const __identifier @has_property($T), value) -> $T => 
        set(self: as_tuple(self), property : property, value);
*/

std::expected<functional_match_descriptor_ptr, error_storage> struct_set_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& env = ctx.env();
    
    auto call_session = call.new_session(ctx);
    prepared_call::argument_descriptor_t slf_arg_expr;

    auto slf_arg = call_session.use_named_argument(env.get(builtin_id::self), expected_result_t{}, &slf_arg_expr);
    if (!slf_arg) {
        if (slf_arg.error()) {
            return std::unexpected(append_cause(
                make_error<basic_general_error>(get_start_location(*get<0>(slf_arg_expr)), "invalid `self` argument"sv),
                std::move(slf_arg.error())));
        }
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: `self`"sv));
    }

    auto& slf_er = slf_arg->first;
    resource_location const& slf_loc = get_start_location(*get<0>(slf_arg_expr));
    entity_identifier selftp = get_result_type(env, slf_er);
    struct_entity const* pstruct = dynamic_cast<struct_entity const*>(&get_entity(env, selftp)); // ensure entity exists
    if (!pstruct) {
        return std::unexpected(make_error<type_mismatch_error>(slf_loc, selftp, "a structure type"sv));
    }

    prepared_call::argument_descriptor_t prop_arg_expr;
    alt_error prop_errors;
    auto property_arg = call_session.use_named_argument(env.get(builtin_id::property), expected_result_t{ env.get(builtin_eid::integer) }, &prop_arg_expr);
    if (!property_arg && property_arg.error()) {
        prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
        call_session.reuse_argument(get<1>(prop_arg_expr));
        property_arg = call_session.use_named_argument(env.get(builtin_id::property), expected_result_t{ env.get(builtin_eid::identifier) }, &prop_arg_expr);
    }
    if (!property_arg) {
        if (!property_arg.error()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: `property`"sv));
        }
        prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
        return std::unexpected(append_cause(
            make_error<basic_general_error>(get_start_location(*get<0>(prop_arg_expr)), "invalid `property` argument"sv),
            make_error<alt_error>(std::move(prop_errors))
        ));
    }
    auto& prop_er = property_arg->first;
    resource_location const& prop_loc = get_start_location(*get<0>(prop_arg_expr));

    // Get underlying tuple entity for the struct
    auto uteid = pstruct->underlying_tuple_eid(ctx);
    if (!uteid) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(call.location, "cannot get underlying tuple entity for structure"sv, selftp),
            std::move(uteid.error())
        ));
    }
    entity_signature const* utl_sig = get_entity(env, *uteid).signature();
    BOOST_ASSERT(utl_sig);
    if (prop_er.is_const_result) {
        entity_identifier prop_value_type_eid;
        entity_identifier prop_type_eid = get_result_type(env, prop_er);
        if (prop_type_eid == env.get(builtin_eid::integer)) {
            // integer property
            size_t index = static_cast<generic_literal_entity const&>(get_entity(env, prop_er.value())).value().as<size_t>();
            if (field_descriptor const* pfd = utl_sig->find_field(index); pfd) {
                if (pfd->is_const()) {
                    return std::unexpected(make_error<basic_general_error>(prop_loc, "the property is read-only"sv, prop_er.value()));
                }
                prop_value_type_eid = pfd->entity_id();
            } else {
                return std::unexpected(make_error<basic_general_error>(prop_loc, "the structure does not have such a property"sv, prop_er.value()));
            }
        } else {
            BOOST_ASSERT(prop_type_eid == env.get(builtin_eid::identifier));
            // identifier property
            identifier name = static_cast<identifier_entity const&>(get_entity(env, prop_er.value())).value();
            if (field_descriptor const* pfd = utl_sig->find_field(name); pfd) {
                if (pfd->is_const()) {
                    return std::unexpected(make_error<basic_general_error>(prop_loc, "the property is read-only"sv, prop_er.value()));
                }
                prop_value_type_eid = pfd->entity_id();
            } else {
                return std::unexpected(make_error<basic_general_error>(prop_loc, "the structure does not have such a property"sv, prop_er.value()));
            }
        }

        prepared_call::argument_descriptor_t prop_val_arg_expr;
        auto valarg = call_session.use_next_positioned_argument(expected_result_t{ .type = prop_value_type_eid, .modifier = value_modifier_t::runtime_value }, &prop_val_arg_expr);
        if (!valarg) {
            if (valarg.error()) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(get_start_location(*get<0>(prop_val_arg_expr)), "invalid value argument"sv),
                    std::move(valarg.error())));
            }
            return std::unexpected(make_error<basic_general_error>(call.location, "missing required value argument"sv));
        }

        auto pmd = make_shared<struct_set_match_descriptor>(call, *utl_sig);
        pmd->emplace_back(0, slf_er, slf_loc);
        pmd->emplace_back(1, prop_er, prop_loc);
        pmd->emplace_back(2, valarg->first, get_start_location(*get<0>(prop_val_arg_expr)));

        pmd->signature.emplace_back(env.get(builtin_id::self), pstruct->id, slf_er.is_const_result);
        pmd->signature.emplace_back(env.get(builtin_id::property), prop_er.value_or_type, prop_er.is_const_result);
        pmd->signature.emplace_back(prop_value_type_eid, false);
        pmd->signature.result.emplace(selftp, false);

        return pmd;
    } else {
        THROW_NOT_IMPLEMENTED_ERROR("non-constant property argument handling");
    }
}

std::expected<syntax_expression_result, error_storage> struct_set_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto& smd = static_cast<struct_set_match_descriptor&>(md);
    auto& slfer = get<1>(md.matches[0]);
    auto& proper = get<1>(md.matches[1]);
    auto& valueer = get<1>(md.matches[2]);

    if (smd.property_index) {
        
    }
    THROW_NOT_IMPLEMENTED_ERROR("struct_set_pattern::apply");
#if 0
    local_variable* tuple_var = nullptr, *property_var = nullptr, *value_var = nullptr;
    identifier tuple_var_name, property_var_name, value_var_name;
    fn_compiler_context_scope fn_scope{ ctx };

    pure_call_t set_call{ md.call_location };
    
    // Handle 'self' argument - convert struct to tuple
    if (slfer.is_const_result) {
        // if self is a constant, then we can use it directly (but this shouldn't happen for set operations)
        set_call.emplace_back(
            annotated_identifier{ e.get(builtin_id::self), md.call_location },
            annotated_entity_identifier{ slfer.value(), md.call_location });
    } else {
        tuple_var_name = e.new_identifier();
        tuple_var = &fn_scope.new_temporary(tuple_var_name, smd.tpl_entity.id); // here we substitute the tuple entity id instead of the original struct type id
        set_call.emplace_back(
            annotated_identifier{ e.get(builtin_id::self), md.call_location },
            name_reference{ annotated_identifier{ tuple_var_name } });
    }
    
    // Handle 'property' argument
    if (proper.is_const_result) {
        // if property is a constant, then we can use it directly
        set_call.emplace_back(
            annotated_identifier{ e.get(builtin_id::property) },
            annotated_entity_identifier{ proper.value(), md.call_location });
    } else {
        property_var_name = e.new_identifier();
        property_var = &fn_scope.new_temporary(property_var_name, proper.type());
        set_call.emplace_back(
            annotated_identifier{ e.get(builtin_id::property), md.call_location },
            name_reference{ annotated_identifier{ property_var_name } });
    }
    
    // Handle 'value' argument
    if (valueer.is_const_result) {
        // if value is a constant, then we can use it directly
        set_call.emplace_back(annotated_entity_identifier{ valueer.value(), md.call_location });
    } else {
        value_var_name = e.new_identifier();
        value_var = &fn_scope.new_temporary(value_var_name, valueer.type());
        set_call.emplace_back(name_reference{ annotated_identifier{ value_var_name } });
    }

    auto match = ctx.find(builtin_qnid::set, set_call, el);
    if (!match) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(md.call_location, "cannot find set function for underlying structure tuple"sv, smd.tpl_entity.id),
            std::move(match.error())
        ));
    }
    auto res = match->apply(ctx);
    if (!res) {
        return std::unexpected(std::move(res.error()));
    }

    syntax_expression_result result{
        .temporaries = std::move(slfer.temporaries),
        .branches_expressions = el.concat(slfer.branches_expressions, el.concat(proper.branches_expressions, valueer.branches_expressions)),
        .expressions = res->expressions,
        .value_or_type = md.signature.result->entity_id(), // Return the struct type, not the tuple type
        .is_const_result = false // set operations return mutable results
    };
    
    // Merge temporaries from all arguments
    if (!proper.temporaries.empty()) {
        result.temporaries.insert(
            result.temporaries.end(),
            std::make_move_iterator(proper.temporaries.begin()),
            std::make_move_iterator(proper.temporaries.end()));
    }
    if (!valueer.temporaries.empty()) {
        result.temporaries.insert(
            result.temporaries.end(),
            std::make_move_iterator(valueer.temporaries.begin()),
            std::make_move_iterator(valueer.temporaries.end()));
    }

    if (tuple_var) {
        result.temporaries.emplace_back(tuple_var_name, std::move(*tuple_var), slfer.expressions);
    }
    if (property_var) {
        result.temporaries.emplace_back(property_var_name, std::move(*property_var), proper.expressions);
    }
    if (value_var) {
        result.temporaries.emplace_back(value_var_name, std::move(*value_var), valueer.expressions);
    }

    return result;
#endif
}

}
