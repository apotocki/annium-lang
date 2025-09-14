//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once
#include "sonia/small_vector.hpp"
#include "annium/semantic.hpp"
#include "annium/errors.hpp"

#include <boost/container/flat_map.hpp>

#include "functional.hpp"

namespace annium {

class fn_compiler_context;

class prepared_call
{
public:
    fn_compiler_context& caller_ctx;
    functional const* pfnl;
    semantic::expression_list_t& expressions;
    resource_location location;
    small_vector<named_expression_t, 8> args;
    functional_binding_set bound_temporaries;
    small_vector<std::tuple<identifier, local_variable*, semantic::expression_span>, 4> temporaries;
    semantic::expression_span arguments_auxiliary_expressions;

    // cache
    using cache_key_t = std::tuple<entity_identifier, value_modifier_t>;
    struct argument_cache
    {
        syntax_expression_t expression;
        boost::container::small_flat_map<cache_key_t, std::expected<std::pair<syntax_expression_result_t, bool>, error_storage>, 8> cache;

        inline explicit argument_cache(syntax_expression_t e) noexcept
            : expression{ std::move(e) }
        {}
    };

    mutable small_vector<std::tuple<identifier, resource_location, argument_cache>, 8> argument_caches_;
    uint64_t named_map_, positioned_map_; // bitmasks of named and positional arguments

    prepared_call(fn_compiler_context&, functional const*, span<const named_expression_t>, resource_location call_loc, semantic::expression_list_t&);
    prepared_call(prepared_call const&) = delete;
    ~prepared_call();

    prepared_call& operator=(prepared_call const&) = delete;

    error_storage prepare();

    using argument_descriptor_t = std::pair<syntax_expression_t const*, size_t>;
    using next_argument_descriptor_t = std::tuple<annotated_identifier, syntax_expression_t const*, size_t>;

    struct session
    {
        session(session const&) = delete;
        session(session&&) = default;
        session& operator=(session const&) = delete;
        session& operator=(session&&) = delete;
        ~session() noexcept = default;
    
        fn_compiler_context& ctx;
        
        prepared_call const& call;
        uint64_t named_usage_map_, positioned_usage_map_; // bitmasks of unused named and positional arguments

        session(fn_compiler_context&, prepared_call const&);

        bool has_more_positioned_arguments() const noexcept;
        std::expected<std::pair<syntax_expression_result_t, bool>, error_storage> use_next_positioned_argument(argument_descriptor_t* = nullptr);
        std::expected<std::pair<syntax_expression_result_t, bool>, error_storage> use_next_positioned_argument(expected_result_t const& exp, argument_descriptor_t* = nullptr);

        std::expected<std::pair<syntax_expression_result_t, bool>, error_storage> use_named_argument(identifier name, expected_result_t const& exp, argument_descriptor_t* = nullptr);

        std::expected<std::pair<syntax_expression_result_t, bool>, error_storage> use_next_argument(expected_result_t const& exp, next_argument_descriptor_t* pe);
        named_expression_t unused_argument();

        void reuse_argument(size_t argindex);

    private:
        std::expected<std::pair<syntax_expression_result_t, bool>, error_storage>
        do_resolve(argument_cache& arg_cache, expected_result_t const& exp);
    };

    session new_session(fn_compiler_context&) const;

    local_variable& new_temporary(environment&, identifier, entity_identifier type, semantic::expression_span);
    void export_auxiliaries(syntax_expression_result&);

    qname_view functional_name() const noexcept;
    qname_identifier functional_id() const noexcept;

private:
    void init_bindings();
};

}
