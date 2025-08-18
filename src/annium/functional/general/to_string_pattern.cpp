//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "to_string_pattern.hpp"

#include "annium/ast/fn_compiler_context.hpp"

#include "annium/entities/prepared_call.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/functions/function_entity.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

std::expected<functional_match_descriptor_ptr, error_storage> to_string_pattern::try_match(fn_compiler_context& ctx, prepared_call const& call, expected_result_t const&) const
{
    auto call_session = call.new_session(ctx);
    auto arg = call_session.use_next_positioned_argument();
    if (!arg) {
        if (!arg.error()) {
            return std::unexpected(make_error<basic_general_error>(call.location, "missing argument"sv));
        }
        return std::unexpected(arg.error());
    }
    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }
    auto pmd = make_shared<functional_match_descriptor>(call);
    pmd->emplace_back(0, arg->first);
    return std::move(pmd);
}

class to_string_visitor : public entity_visitor
{
    environment& e_;
    std::ostream& oss_;

public:
    inline explicit to_string_visitor(environment& e, std::ostream& os) noexcept 
        : e_{ e }
        , oss_{ os }
    {}

    void operator()(const entity& ent) const override
    {
        ent.print_to(oss_, e_);
    }
    
    // Specialized handlers for literal entities
    void operator()(const generic_literal_entity& ent) const override
    {
        switch (static_cast<builtin_eid>(ent.get_type().value)) {
        case builtin_eid::boolean:
            oss_ << (ent.value().as<bool>() ? "true" : "false");
            return;
        case builtin_eid::integer:
            oss_ << ent.value().as<mp::integer_view>();
            return;
        case builtin_eid::decimal:
            oss_ << ent.value().as<mp::decimal_view>();
            return;
        case builtin_eid::string:
            oss_ << ent.value().as<string_view>();
            return;
        case builtin_eid::i8:
            oss_ << static_cast<int>(ent.value().as<int8_t>());
            return;
        case builtin_eid::u8:
            oss_ << static_cast<unsigned int>(ent.value().as<uint8_t>());
            return;
        case builtin_eid::i16:
            oss_ << ent.value().as<int16_t>();
            return;
        case builtin_eid::u16:
            oss_ << ent.value().as<uint16_t>();
            return;
        case builtin_eid::i32:
            oss_ << ent.value().as<int32_t>();
            return;
        case builtin_eid::u32:
            oss_ << ent.value().as<uint32_t>();
            return;
        case builtin_eid::i64:
            oss_ << ent.value().as<int64_t>();
            return;
        case builtin_eid::u64:
            oss_ << ent.value().as<uint64_t>();
            return;
        case builtin_eid::f16:
            oss_ << ent.value().as<float16>();
            return;
        case builtin_eid::f32:
            oss_ << ent.value().as<float>();
            return;
        case builtin_eid::f64:
            oss_ << ent.value().as<double>();
            return;

        default:
            THROW_INTERNAL_ERROR("to_string_visitor: Unsupported generic literal type for to_string");
        }
    }
    
    void operator()(const identifier_entity& ent) const override
    {
        e_.print_to(oss_, ent.value());
    }
    
    void operator()(const qname_identifier_entity& ent) const override
    {
        e_.print_to(oss_, ent.value());
    }
    
    void operator()(const empty_entity& e) const override
    {
        e.print_to(oss_, e_);
    }
    
    // Other entity types
    void operator()(const function_entity& ent) const override
    {
        ent.print_to(oss_, e_);
    }
    
    void operator()(const external_function_entity& ent) const override
    {
        ent.print_to(oss_, e_);
    }
    
    void operator()(const extern_variable_entity& ent) const override
    {
        ent.print_to(oss_, e_);
    }
    
    //void operator()(const functional_entity& ent) const override
    //{
    //    ent.print_to(oss_, e_);
    //}
};

std::expected<syntax_expression_result_t, error_storage> to_string_pattern::apply(fn_compiler_context& ctx, semantic::expression_list_t& el, functional_match_descriptor& md) const
{
    environment& e = ctx.env();
    auto & [_, er, loc] = md.matches.front();
    
    if (er.is_const_result) {
        entity const& ent = get_entity(e, er.value());
        std::ostringstream oss;
        ent.visit(to_string_visitor(e, oss));
        er.value_or_type = e.make_string_entity(oss.str()).id;
    } else {
        e.push_back_expression(el, er.expressions, semantic::invoke_function(e.get(builtin_eid::to_string)));
        er.value_or_type = e.get(builtin_eid::string);
    }
    return std::move(er);
}

}
