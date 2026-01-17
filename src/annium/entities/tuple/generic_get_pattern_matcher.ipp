//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/entities/functional.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/entities/prepared_call.hpp"
#include "annium/auxiliary.hpp"

namespace annium {

template <typename DerivedT>
class generic_get_pattern_matcher
{
    inline DerivedT & derived() noexcept { return static_cast<DerivedT&>(*this); }

protected:
    fn_compiler_context& ctx;
    prepared_call const& call;
    expected_result_t const& exp;

public:
    inline generic_get_pattern_matcher(
        fn_compiler_context& ctx_val,
        prepared_call const& call_val,
        expected_result_t const& exp_val) noexcept
        : ctx{ ctx_val }, call{ call_val }, exp{ exp_val }
    {}

    std::expected<functional_match_descriptor_ptr, error_storage> try_match();
    
    inline error_storage check_type_compatibility() const { return {}; }
    
    prepared_call::argument_descriptor_t slf_arg_descr;
    prepared_call::argument_descriptor_t property_arg_descr;
    entity_identifier slftype;
};

template <typename DerivedT>
std::expected<functional_match_descriptor_ptr, error_storage> generic_get_pattern_matcher<DerivedT>::try_match()
{
    environment& e = ctx.env();
    auto call_session = call.new_session(ctx);

    auto slf_arg = call_session.get_named_argument(e.get(builtin_id::self), expected_result_t{});
    if (!slf_arg) return std::unexpected(std::move(slf_arg.error()));
    slf_arg_descr = std::move(*slf_arg);

    syntax_expression_result& slf_arg_er = slf_arg_descr.result;
    if (slf_arg_er.is_const_result) {
        entity const& slf_entity = get_entity(e, slf_arg_er.value());
        slftype = slf_entity.get_type();
    } else {
        slftype = slf_arg_er.type();
    }
    if (auto err = derived().check_type_compatibility(); err) {
        return std::unexpected(std::move(err));
    }

    alt_error prop_errors;
    auto property_arg = call_session.use_named_argument(e.get(builtin_id::property), expected_result_t{ e.get(builtin_eid::integer) }, &property_arg_descr);
    if (!property_arg) {
        prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
        call_session.reuse_argument(property_arg_descr.arg_index);
        property_arg = call_session.use_named_argument(e.get(builtin_id::property), expected_result_t{ e.get(builtin_eid::identifier) }, &property_arg_descr);
    }
    if (property_arg && !*property_arg) {
        return std::unexpected(make_error<basic_general_error>(call.location, "missing required argument: `property`"sv));
    }
    if (!property_arg) {
        if (prop_errors.alternatives.empty()) {
            return std::unexpected(std::move(property_arg.error()));
        } else {
            prop_errors.alternatives.emplace_back(std::move(property_arg.error()));
            return std::unexpected(make_error<alt_error>(std::move(prop_errors)));
        }
    }

    if (auto argterm = call_session.unused_argument(); argterm) {
        return std::unexpected(make_error<basic_general_error>(argterm.location(), "argument mismatch"sv, std::move(argterm.value())));
    }

    auto optpmd = derived().create_match_descriptor();
    if (optpmd) {
        functional_match_descriptor& md = **optpmd;
        md.emplace_back(0, slf_arg_er);
        md.emplace_back(1, property_arg_descr.result);
    }
    return std::move(optpmd);
}

}
