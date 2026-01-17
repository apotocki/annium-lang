//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "tuple_equal_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/errors/type_mismatch_error.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

class tuple_equal_match_descriptor : public functional_match_descriptor
{
public:
    tuple_equal_match_descriptor(prepared_call const& call, entity const& lhs, entity const& rhs) noexcept
        : functional_match_descriptor{ call }
        , lhs_entity_type{ lhs }
        , rhs_entity_type{ rhs }
    {}

    entity const& lhs_entity_type;
    entity const& rhs_entity_type;
};

std::expected<functional_match_descriptor_ptr, error_storage>
tuple_equal_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    environment& e = ctx.env();

    auto call_session = call.new_session(ctx);

    // Get lhs tuple
    auto lhs_descr = call_session.get_next_positioned_argument("first"sv);
    if (!lhs_descr) return std::unexpected(std::move(lhs_descr.error()));
    
    // Get rhs tuple
    auto rhs_descr = call_session.get_next_positioned_argument("second"sv);
    if (!rhs_descr) return std::unexpected(std::move(rhs_descr.error()));

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "tuple equality comparison accepts exactly two arguments, but more were provided"sv, std::move(argterm.value())));
    }

    syntax_expression_result & lhs_arg_er = lhs_descr->result;
    syntax_expression_result & rhs_arg_er = rhs_descr->result;

    // Both must be tuple types
    entity_identifier lhs_type = lhs_arg_er.is_const_result
        ? get_entity(e, lhs_arg_er.value()).get_type()
        : lhs_arg_er.type();
    entity_identifier rhs_type = rhs_arg_er.is_const_result
        ? get_entity(e, rhs_arg_er.value()).get_type()
        : rhs_arg_er.type();

    entity const& lhs_entity_type = get_entity(e, lhs_type);
    entity const& rhs_entity_type = get_entity(e, rhs_type);

    auto* lhs_sig = lhs_entity_type.signature();
    auto* rhs_sig = rhs_entity_type.signature();

    if (!lhs_sig || lhs_sig->name != e.get(builtin_qnid::tuple)) {
        return std::unexpected(make_error<type_mismatch_error>(lhs_descr->expression->location, lhs_entity_type.id, "a tuple type for equality comparison"sv));
    }
    if (!rhs_sig || rhs_sig->name != e.get(builtin_qnid::tuple)) {
        return std::unexpected(make_error<type_mismatch_error>(rhs_descr->expression->location, rhs_entity_type.id, "a tuple type for equality comparison"sv));
    }

    auto pmd = make_shared<tuple_equal_match_descriptor>(call, lhs_entity_type, rhs_entity_type);
    pmd->append_arg(lhs_arg_er, lhs_descr->expression->location);
    pmd->append_arg(rhs_arg_er, rhs_descr->expression->location);
    return pmd;
}

std::expected<syntax_expression_result, error_storage>
tuple_equal_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    tuple_equal_match_descriptor& eq_md = static_cast<tuple_equal_match_descriptor&>(md);
    auto& lhs_er = get<1>(md.matches[0]);
    auto& rhs_er = get<1>(md.matches[1]);

    entity_signature const& lhs_sig = *eq_md.lhs_entity_type.signature();
    entity_signature const& rhs_sig = *eq_md.rhs_entity_type.signature();

    // Check field count and names
    if (lhs_sig.field_count() != rhs_sig.field_count()) {
        return syntax_expression_result{
            .value_or_type = e.get(builtin_eid::false_),
            .is_const_result = true
        };
    }
    for (size_t i = 0; i < lhs_sig.field_count(); ++i) {
        auto const& lhs_field = *lhs_sig.get_field(i);
        auto const& rhs_field = *rhs_sig.get_field(i);
        if (lhs_field.name() != rhs_field.name()) {
            return syntax_expression_result{
                .value_or_type = e.get(builtin_eid::false_),
                .is_const_result = true
            };
        }
    }

    syntax_expression_result result{ };

    fn_compiler_context_scope fn_scope{ ctx };

    //lhs_er.temporaries.insert(lhs_er.temporaries.end(), rhs_er.temporaries.begin(), rhs_er.temporaries.end());

    //syntax_expression_result result{
    //    .temporaries = std::move(lhs_er.temporaries),
    //    .branches_expressions = el.concat(lhs_er.branches_expressions, rhs_er.branches_expressions),
    //    .value_or_type = e.get(builtin_eid::boolean),
    //    .is_const_result = false
    //};

    optional<local_variable> lhs_tuple_var, rhs_tuple_var;
    identifier lhs_tuple_var_name, rhs_tuple_var_name;

    // Helper lambda to append field value (const or non-const) for tuple fields
    auto append_tuple_field_value = [&](call_builder& call, const auto& field, size_t fidx, optional<local_variable>& tuple_var, identifier& tuple_var_name, entity const& tuple_entity_type) -> error_storage {
        if (field.is_const()) {
            // Use the const entity directly
            if (field.name()) { // get constexpr tuple field implementation
                entity_signature rsig{ e.get(builtin_qnid::tuple), e.get(builtin_eid::typename_) };
                rsig.emplace_back(e.make_identifier_entity(field.name()).id, true);
                rsig.emplace_back(field.entity_id(), true);
                entity_identifier ftype = e.make_basic_signatured_entity(std::move(rsig)).id;
                call.emplace_back(md.call_location, e.make_empty_entity(ftype).id);
            } else {
                call.emplace_back(md.call_location, field.entity_id());
            }
        } else {
            if (!tuple_var_name) {
                tuple_var_name = e.new_identifier();
                tuple_var.emplace(fn_scope.new_temporary(tuple_var_name, tuple_entity_type.id));
            }
            call_builder get_call{ md.call_location };
            get_call.emplace_back(e.get(builtin_id::self), md.call_location, name_reference_expression{ tuple_var_name });
            get_call.emplace_back(e.get(builtin_id::property), md.call_location, numetron::integer_view{ fidx });
            auto match = ctx.find(builtin_qnid::get, get_call, el);
            if (!match) {
                return append_cause(
                    make_error<basic_general_error>(md.call_location, ("failed to access tuple field at index %1% during equality comparison"_fmt % fidx).str(), syntax_expression{ .value = numetron::integer_view{ fidx } }),
                    std::move(match.error()));
            }
            auto res = match->apply(ctx);
            if (!res) {
                return append_cause(
                    make_error<basic_general_error>(md.call_location, ("failed to retrieve tuple field value at index %1% during equality comparison"_fmt % fidx).str(), syntax_expression{ .value = numetron::integer_view{ fidx } }),
                    std::move(res.error()));
            }
            //result.branches_expressions = el.concat(result.branches_expressions, res->branches_expressions);
            call.emplace_back(make_indirect_value(e, el, std::move(*res), md.call_location));
        }
        return {};
    };

    semantic::expression_span* current_branch_owner_code = nullptr;

    // Helper lambda to compare a single tuple field and update result accordingly
    auto compare_tuple_field = [&](size_t i) -> std::expected<bool, error_storage> {
        auto const& lhs_field = lhs_sig.field(i);
        auto const& rhs_field = rhs_sig.field(i);

        // If both fields are the same const entity, skip comparison
        if (lhs_field.entity_id() == rhs_field.entity_id() && lhs_field.is_const() && rhs_field.is_const()) {
            return true;
        }

        call_builder eq_call{ md.call_location };

        // Append lhs field value
        if (auto lhs_err = append_tuple_field_value(eq_call, lhs_field, i, lhs_tuple_var, lhs_tuple_var_name, eq_md.lhs_entity_type)) {
            // Add field name and index to error
            std::string field_desc = lhs_field.name() 
                ? ("named field '%1%' at index %2%"_fmt % e.print(lhs_field.name()) % i).str()
                : ("field at index %1%"_fmt % i).str();
            return std::unexpected(append_cause(
                make_error<basic_general_error>(md.call_location, ("failed to access left tuple %1% for equality comparison"_fmt % field_desc).str(), lhs_field.name()),
                std::move(lhs_err)));
        }

        // Append rhs field value
        if (auto rhs_err = append_tuple_field_value(eq_call, rhs_field, i, rhs_tuple_var, rhs_tuple_var_name, eq_md.rhs_entity_type)) {
            // Add field name and index to error
            std::string field_desc = rhs_field.name() 
                ? ("named field '%1%' at index %2%"_fmt % e.print(rhs_field.name()) % i).str()
                : ("field at index %1%"_fmt % i).str();
            return std::unexpected(append_cause(
                make_error<basic_general_error>(md.call_location, ("failed to access right tuple %1% for equality comparison"_fmt % field_desc).str(), rhs_field.name()),
                std::move(rhs_err)));
        }

        // Compare fields using builtin_qnid::eq
        auto match = ctx.find(builtin_qnid::eq, eq_call, el, expected_result_t{ .type = e.get(builtin_eid::boolean) });
        if (!match) {
            std::string field_desc = lhs_field.name() && rhs_field.name()
                ? ("named fields '%1%' and '%2%' at index %3%"_fmt % e.print(lhs_field.name()) % e.print(rhs_field.name()) % i).str()
                : ("fields at index %1%"_fmt % i).str();
            return std::unexpected(append_cause(
                make_error<binary_relation_error>(md.call_location, ("cannot compare tuple %1%: types are not comparable"_fmt % field_desc).str(), lhs_field.entity_id(), rhs_field.entity_id()),
                std::move(match.error())));
        }
        auto eq_res = match->apply(ctx);
        if (!eq_res) {
            std::string field_desc = lhs_field.name() && rhs_field.name()
                ? ("named fields '%1%' and '%2%' at index %3%"_fmt % e.print(lhs_field.name()) % e.print(rhs_field.name()) % i).str()
                : ("fields at index %1%"_fmt % i).str();
            return std::unexpected(append_cause(
                make_error<binary_relation_error>(md.call_location, ("failed to compare tuple %1% during equality operation"_fmt % field_desc).str(), lhs_field.entity_id(), rhs_field.entity_id()),
                std::move(eq_res.error())));
        }

        // If the result is constant, optimize
        if (eq_res->is_const_result) {
            if (eq_res->value() == e.get(builtin_eid::true_)) {
                return true; // This field is equal, skip it
            } else {
                BOOST_ASSERT(eq_res->value() == e.get(builtin_eid::false_));
                // If any field is not equal, the whole tuple is not equal
                return false;
            }
        }

        // to do: treat eq_res temporaries as temporaries of the current branch
        result.temporaries.insert(result.temporaries.begin(), eq_res->temporaries.begin(), eq_res->temporaries.end());
        result.branches_expressions = el.concat(result.branches_expressions, eq_res->branches_expressions);
        if (current_branch_owner_code) {
            // append conditional branch
            e.push_back_expression(el, *current_branch_owner_code, semantic::conditional_t{});
            semantic::conditional_t& cond = get<semantic::conditional_t>(current_branch_owner_code->back());

            // removing 'true' from previous field equality check
            e.push_back_expression(el, cond.true_branch, semantic::truncate_values{ 1, false });

            // append the result of current field equality check
            cond.true_branch = el.concat(cond.true_branch, eq_res->expressions);

            // store branch expressions as stored expressions if they are not primary branch expressions
            if (&result.expressions != current_branch_owner_code) {
                result.branches_expressions = el.concat(result.branches_expressions, *current_branch_owner_code);
            }

            current_branch_owner_code = &cond.true_branch;
        } else {
            // Otherwise, we need to create a new conditional expression
            result.expressions = el.concat(result.expressions, eq_res->expressions);
            current_branch_owner_code = &result.expressions;
        }
        return true;
    };

    // For each field, compare using builtin_qnid::eq
    // Returns true only if all fields are equal, otherwise returns false at first mismatch
    for (size_t i = 0; i < lhs_sig.field_count(); ++i) {
        auto cmp = compare_tuple_field(i);
        if (!cmp) {
            return std::unexpected(std::move(cmp.error()));
        }
        if (!cmp.value()) {
            // Early exit: a field is not equal
            result.value_or_type = e.get(builtin_eid::false_);
            result.is_const_result = true;
            return result;
        }
    }

    if (!current_branch_owner_code) {
        // If we have no branches, all fields are consts and equal, so we can return true
        result.value_or_type = e.get(builtin_eid::true_);
        result.is_const_result = true;
        return result;
    }

    // Store any remaining branch expressions
    if (&result.expressions != current_branch_owner_code) {
        result.branches_expressions = el.concat(result.branches_expressions, *current_branch_owner_code);
    }

    if (rhs_tuple_var) {
        result.temporaries.insert(result.temporaries.end(), rhs_er.temporaries.begin(), rhs_er.temporaries.end());
        semantic::expression_span reserve_expression;
        e.push_back_expression(el, reserve_expression, semantic::push_value{ smart_blob{} });
        result.temporaries.emplace_back(rhs_tuple_var_name, std::move(*rhs_tuple_var), reserve_expression);

        // Store the rhs tuple variable as a temp local variable
        e.push_back_expression(el, rhs_er.expressions, semantic::set_local_variable{ *rhs_tuple_var });
        e.push_back_expression(el, rhs_er.expressions, semantic::truncate_values{ 1, false });
        result.expressions = el.concat(rhs_er.expressions, result.expressions);
    }

    if (lhs_tuple_var) {
        result.temporaries.insert(result.temporaries.end(), lhs_er.temporaries.begin(), lhs_er.temporaries.end());
        semantic::expression_span reserve_expression;
        e.push_back_expression(el, reserve_expression, semantic::push_value{ smart_blob{} });
        result.temporaries.emplace_back(lhs_tuple_var_name, std::move(*lhs_tuple_var), reserve_expression);

        // Store the lhs tuple variable as a temp local variable
        e.push_back_expression(el, lhs_er.expressions, semantic::set_local_variable{ *lhs_tuple_var });
        e.push_back_expression(el, lhs_er.expressions, semantic::truncate_values{ 1, false });
        result.expressions = el.concat(lhs_er.expressions, result.expressions);
    }

    result.value_or_type = e.get(builtin_eid::boolean);
    result.is_const_result = false;
    return result;
}

} // namespace annium
