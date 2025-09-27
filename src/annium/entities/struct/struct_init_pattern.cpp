//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "struct_init_pattern.hpp"
#include "struct_entity.hpp"

#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/base_expression_visitor.ipp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/literals/literal_entity.hpp"
//#include "annium/errors/circular_dependency_error.hpp"

#include "annium/errors/type_mismatch_error.hpp"

namespace annium {

std::ostream& struct_init_pattern::print(environment const&, std::ostream& s) const
{
    return s << "init(...) -> @structure"sv;
}

std::expected<functional_match_descriptor_ptr, error_storage> struct_init_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    environment& env = ctx.env();
    if (!exp.type) {
        return std::unexpected(make_error<basic_general_error>(call.location, "expected a structure result"sv));
    }
    entity const& struct_ent = get_entity(env, exp.type);
    struct_entity const* pstruct = dynamic_cast<struct_entity const*>(&struct_ent);
    if (!pstruct) {
        return std::unexpected(make_error<type_mismatch_error>(exp.location, exp.type, "a structure type"sv));
    }
    auto struct_fields = pstruct->fields(ctx);
    if (!struct_fields) {
        return std::unexpected(append_cause(
            make_error<basic_general_error>(exp.location, "unable to retrieve structure fields"sv),
            std::move(struct_fields.error())
        ));
    }

    auto call_session = call.new_session(ctx);
    functional_match_descriptor_ptr pmd = make_shared<functional_match_descriptor>(call);

    auto const& fields_span = *struct_fields;
    for (auto const& field : fields_span) {
        prepared_call::argument_descriptor_t arg_expr;
        expected_result_t argexp{ .type = field.type, .location = field.name.location, .modifier = value_modifier_t::runtime_value };
        auto res = field.name ?
            call_session.use_named_argument(field.name.value, argexp, &arg_expr) :
            call_session.use_next_positioned_argument(argexp, &arg_expr);
        resource_location const* pargloc;
        if (res) {
            pargloc = &get_start_location(*get<0>(arg_expr));
        } else {
            if (res.error()) {
                return std::unexpected(append_cause(
                    make_error<basic_general_error>(get_start_location(*get<0>(arg_expr)), "invalid argument"sv),
                    std::move(res.error())
                ));
            }
            if (syntax_expression_t const* default_expr = get<syntax_expression_t>(&field.default_value)) {
                base_expression_visitor bev(ctx, call.expressions, argexp);
                res = apply_visitor(bev, *default_expr);
                if (!res) {
                    return std::unexpected(append_cause(
                        make_error<basic_general_error>(get_start_location(*default_expr), "unable to evaluate default value expression"sv),
                        std::move(res.error())
                    ));
                }
                pargloc = &get_start_location(*default_expr);
            } else {
                return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument"sv));
            }
        }
        pmd->emplace_back(static_cast<intptr_t>(&field - fields_span.data()), std::move(res->first), *pargloc);
        if (field.name) {
            pmd->signature.emplace_back(field.name.value, field.type, false);
        } else {
            pmd->signature.emplace_back(field.type, false);
        }
    }
    pmd->signature.result.emplace(exp.type, false);
    return std::move(pmd);
}

#if 0
struct_init_pattern::struct_init_pattern(variant<field_list_t, statement_span> const& body)
{
    apply_visitor(make_functional_visitor<void>([this](auto const& body) {
        if constexpr (std::is_same_v<std::decay_t<decltype(body)>, field_list_t>) {
            field_list_t const& fl = body;
            for (field_t const& f : fl) {
                body_parameters_.emplace_back(
                     named_parameter_name{ f.name }, f.type_or_value, f.value, f.modifier
                );
            }
        } else {
            THROW_NOT_IMPLEMENTED_ERROR("struct_init_pattern::struct_init_pattern(statement_span)");
        }
    }), body);
}

error_storage struct_init_pattern::init(fn_compiler_context& ctx, annotated_entity_identifier result)
{
    fn_pure_t init_fn{ .location = result.location };
    init_fn.parameters = std::move(body_parameters_);
    init_fn.result = result;
    return basic_fn_pattern::init(ctx, init_fn);
}

error_storage struct_init_pattern::init(fn_compiler_context& ctx, annotated_qname name, parameter_list_t const& fparameters)
{
    pattern_t::signature_descriptor sigdesc{ .name = name };
    for (parameter_t const& param : fparameters) {
        auto [external_name, internal_name] = apply_visitor(param_name_retriever{}, param.name);
        if (external_name) {
            if (internal_name) {
                sigdesc.fields.emplace_back(*external_name, annotated_identifier{ internal_name->value, internal_name->location }, pattern_t{ .descriptor = placeholder{} });
            } else {
                // to do: prepare and use replacement
                sigdesc.fields.emplace_back(*external_name, annotated_identifier{ external_name->value, external_name->location }, pattern_t{ .descriptor = placeholder{} });
            }
        } else if (internal_name) {
            BOOST_ASSERT(*internal_name);
            sigdesc.fields.emplace_back(nullptr, annotated_identifier{ internal_name->value, internal_name->location }, pattern_t{ .descriptor = placeholder{} });
        } else {
            sigdesc.fields.emplace_back(nullptr, annotated_identifier{}, pattern_t{ .descriptor = placeholder{} });
        }
    }

    fn_pure_t init_fn{ .location = name.location };
    init_fn.parameters = std::move(body_parameters_);
    init_fn.result = pattern_t{ .descriptor = std::move(sigdesc) };
    
    return basic_fn_pattern::init(ctx, init_fn);
}

std::expected<functional_match_descriptor_ptr, error_storage> struct_init_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const& exp) const
{
    auto res = basic_fn_pattern::try_match(ctx, call, exp);
    //if (!res) {
    //    GLOBAL_LOG_WARN() << ctx.env().print(*res.error());
    //}
    return res;
}

#endif

std::expected<syntax_expression_result, error_storage> struct_init_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    // create tuple instance
    environment& e = ctx.env();

    size_t argcount = 0;
    syntax_expression_result result{ };
    for (auto& [_, mr, loc] : md.matches) {
        append_semantic_result(el, mr, result);
        if (!mr.is_const_result) ++argcount;
    }
    result.is_const_result = !argcount;

    if (argcount > 1) {
        e.push_back_expression(el, result.expressions, semantic::push_value{ smart_blob{ ui64_blob_result(argcount) } });
        e.push_back_expression(el, result.expressions, semantic::invoke_function(e.get(builtin_eid::arrayify)));
    }

    BOOST_ASSERT(md.signature.result && md.signature.result->entity_id());
    result.value_or_type = result.is_const_result ? e.make_empty_entity(md.signature.result->entity_id()).id : md.signature.result->entity_id();
    return std::move(result);
}

}
