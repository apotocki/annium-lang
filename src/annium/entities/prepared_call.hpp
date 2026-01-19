//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once
#include "sonia/small_vector.hpp"
#include "annium/semantic.hpp"
#include "annium/errors.hpp"

#include <boost/container/flat_map.hpp>

#include "annium/functional/functional.hpp"

#include "annium/environment.hpp"

namespace annium {

class fn_compiler_context;

class prepared_call
{
public:
    fn_compiler_context& caller_ctx;
    functional const* pfnl;
    semantic::expression_list_t& expressions;
    resource_location location;

    using args_type = small_vector<opt_named_expression_t, 8>;
    //using args_type = span<const opt_named_expression_t>;
    args_type args;

    layered_binding_set bound_temporaries;
    //small_vector<std::tuple<identifier, local_variable*, semantic::expression_span>, 4> temporaries;
    std::vector<std::tuple<identifier, local_variable, semantic::expression_span>> temporaries;
    semantic::expression_span arguments_auxiliary_expressions;

    // cache
    using cache_key_t = std::tuple<entity_identifier, value_modifier_t>;
    struct argument_cache
    {
        syntax_expression expression;
        boost::container::small_flat_map<cache_key_t, std::expected<std::pair<syntax_expression_result, bool>, error_storage>, 8> cache;

        inline explicit argument_cache(syntax_expression e) noexcept
            : expression{ std::move(e) }
        {}
    };

    //using argument_caches_type = small_vector<std::tuple<identifier, resource_location, argument_cache>, 8>;
    using argument_caches_type = std::vector<std::tuple<identifier, resource_location, argument_cache>>;
    mutable argument_caches_type argument_caches_;
    uint64_t named_map_, positioned_map_; // bitmasks of named and positional arguments

    prepared_call(fn_compiler_context&, functional const*, span<const opt_named_expression_t>, resource_location call_loc, semantic::expression_list_t&);
    prepared_call(prepared_call const&) = delete;
    ~prepared_call();

    prepared_call& operator=(prepared_call const&) = delete;

    error_storage prepare();

    //struct argument_descriptor_t
    //{
    //    annotated_identifier name;
    //    syntax_expression const* expression;
    //    size_t arg_index;
    //};

    struct argument_descriptor_t
    {
        annotated_identifier name;
        syntax_expression const* expression;
        syntax_expression_result result;
        size_t arg_index : 31;
        size_t has_been_casted : 1;
    };

    //using argument_descriptor_t = std::pair<syntax_expression const*, size_t>;
    //using next_argument_descriptor_t = std::tuple<annotated_identifier, syntax_expression const*, size_t>;

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
        std::expected<bool, error_storage> use_next_positioned_argument(argument_descriptor_t *);
        std::expected<bool, error_storage> use_next_positioned_argument(expected_result_t const&, argument_descriptor_t*);
        std::expected<bool, error_storage> use_named_argument(identifier name, expected_result_t const&, argument_descriptor_t*);

        std::expected<bool, error_storage> use_next_argument(expected_result_t const&, argument_descriptor_t*);
        opt_named_expression_t unused_argument();

        void reuse_argument(size_t argindex);

        // auxiliary: raising error if argument not found 
        std::expected<argument_descriptor_t, error_storage> get_named_argument(identifier name, expected_result_t const& = {});
        std::expected<argument_descriptor_t, error_storage> get_named_argument(builtin_id name, expected_result_t const& = {});
        std::expected<argument_descriptor_t, error_storage> get_named_argument(builtin_id name, builtin_eid type, value_modifier_t = value_modifier_t::constexpr_or_runtime_value);
        std::expected<argument_descriptor_t, error_storage> get_next_positioned_argument(expected_result_t const&, string_view arg_hint = ""sv);
        std::expected<argument_descriptor_t, error_storage> get_next_positioned_argument(builtin_eid type, value_modifier_t = value_modifier_t::constexpr_or_runtime_value, string_view arg_hint = ""sv);
        std::expected<argument_descriptor_t, error_storage> get_next_positioned_argument(string_view arg_hint = ""sv);

    private:
        std::expected<std::pair<syntax_expression_result, bool>, error_storage>
        do_resolve(argument_cache& arg_cache, expected_result_t const& exp);
    };

    session new_session(fn_compiler_context&) const;

    local_variable new_temporary(environment&, identifier, entity_identifier type, semantic::expression_span);
    void export_auxiliaries(syntax_expression_result&);

    qname_view functional_name() const noexcept;
    qname_identifier functional_id() const noexcept;

private:
    void init_bindings();
};

}
