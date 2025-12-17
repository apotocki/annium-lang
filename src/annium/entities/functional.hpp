//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <variant>
#include <expected>
#include <unordered_set>
#include <boost/container/flat_set.hpp>

#include "sonia/shared_ptr.hpp"
#include "sonia/small_vector.hpp"
#include "sonia/concurrency.hpp"
#include "sonia/utility/lang/qname.hpp"

#include "annium/semantic.hpp"
#include "annium/errors.hpp"

#include "annium/entities/layered_binding_set.hpp"

namespace annium {

class fn_compiler_context;
class prepared_call;

#if 0
class functional_binding_set : public functional_binding
{
    //small_vector<value_type, 16> binding_;
    std::vector<value_type> binding_;
    //small_vector<identifier, 16> binding_names_;
    std::vector<identifier> binding_names_;
    //small_vector<resource_location, 16> binding_locations_;
    std::vector<resource_location> binding_locations_;
    size_t bound_variables_count_{ 0 };

public:
    inline void reset() noexcept;
    
    //value_type const* lookup(identifier) const noexcept override;

    value_type const* lookup(identifier, resource_location const** = nullptr) const noexcept override;

    void emplace_back(annotated_identifier, value_type) override;

    template <typename FT>
    requires std::is_invocable_v<FT, identifier, resource_location const&, value_type&>
    void for_each(FT && ftor)
    {
        for (auto it = binding_names_.begin(), eit = binding_names_.end(); it != eit; ++it) {
            auto pos = it - binding_names_.begin();
            std::forward<FT>(ftor)(*it, binding_locations_[pos], binding_[pos]);
        }
    }

    inline size_t variables_count() const noexcept { return bound_variables_count_; }
    inline size_t size() const noexcept { return binding_.size(); }
    inline bool empty() const noexcept { return binding_.empty(); }
};
#endif

class functional_match_descriptor
{
    // { implementation defined index(e.g. function parameter index), argument expression result }
    using mr_t = std::tuple<intptr_t, syntax_expression_result, resource_location>;

public:
    small_vector<mr_t, 8> matches;
    
    // can not not merge spans before match application
    small_vector<semantic::expression_span, 4> arguments_auxiliary_expressions_spans;

    entity_signature signature;
    layered_binding_set bindings;
    resource_location call_location;

    int weight{ 0 };

    inline functional_match_descriptor() = default;
    inline functional_match_descriptor(qname_identifier fname, resource_location loc) noexcept
        : signature{ std::move(fname) }
        , call_location{ std::move(loc) }
    {}

    explicit functional_match_descriptor(prepared_call const& pcall) noexcept;

    virtual ~functional_match_descriptor() = default;

    inline void emplace_back(syntax_expression_result result, resource_location loc = {})
    {
        intptr_t argindex = matches.size();
        matches.emplace_back(argindex, std::move(result), std::move(loc));
    }

    inline void emplace_back(intptr_t idx, syntax_expression_result result, resource_location loc = {})
    {
        matches.emplace_back(idx, std::move(result), std::move(loc));
    }

    inline void append_arg(identifier name, syntax_expression_result arg_er, resource_location loc = {})
    {
        //intptr_t argindex = signature.fields().size();
        intptr_t argindex = matches.size();
        signature.emplace_back(name, arg_er.value_or_type, arg_er.is_const_result);
        emplace_back(argindex, std::move(arg_er), std::move(loc));
    }

    inline void append_arg(syntax_expression_result arg_er, resource_location loc = {})
    {
        //intptr_t argindex = signature.fields().size();
        intptr_t argindex = matches.size();
        signature.emplace_back(arg_er.value_or_type, arg_er.is_const_result);
        emplace_back(argindex, std::move(arg_er), std::move(loc));
    }

    inline void remove_last_arg()
    {
        BOOST_ASSERT(!matches.empty());
        matches.pop_back();
        BOOST_ASSERT(!signature.empty());
        signature.pop_back();
    }
    //semantic::expression_span merge_void_spans(semantic::expression_list_t&) noexcept;
};

using functional_match_descriptor_ptr = shared_ptr<functional_match_descriptor>;

struct expected_result_t
{
    entity_identifier type;
    resource_location location;
    value_modifier_t modifier = value_modifier_t::constexpr_or_runtime_value;
    
    inline explicit operator bool() const noexcept
    {
        return !!type || !can_be_constexpr_and_runtime(modifier);
    }

    inline bool is_modifier_compatible(syntax_expression_result const& er) const noexcept
    {
        return er.is_const_result ? can_be_constexpr(modifier) : can_be_runtime(modifier);
    }
};

class functional
{
public:
    using identifier_type = qname_identifier;
    using qname_view_type = qname_view;
    
    class pattern
    {
    protected:
        numetron::decimal weight_;
        resource_location location_;

        inline explicit pattern(numetron::decimal w = 1) noexcept : weight_{ w } {}

    public:
        virtual std::expected<functional_match_descriptor_ptr, error_storage> try_match(fn_compiler_context&, prepared_call const&, expected_result_t const&) const = 0;
        virtual std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&, semantic::expression_list_t&, functional_match_descriptor&) const = 0;

        inline numetron::decimal const& get_weight() const noexcept { return weight_; }
        inline resource_location const& location() const noexcept { return location_; }

        virtual std::ostream& print(environment const&, std::ostream& s) const { return s << "some pattern"; }
    };

    class match
    {
    public:
        inline match(pattern const* p, semantic::expression_list_t& exprs, syntax_expression_result && pser, functional_match_descriptor_ptr md) noexcept
            : expressions{ exprs }, pre_ser{ std::move(pser) }
            , ptrn_{ p }, md_{ std::move(md) }
        {
            BOOST_ASSERT(md_);
        }
        
        semantic::expression_list_t& expressions;
        syntax_expression_result pre_ser;

        std::expected<syntax_expression_result, error_storage> apply(fn_compiler_context&);

        inline pattern const& get_pattern() const noexcept { return *ptrn_; }

    private:
        pattern const* ptrn_;
        functional_match_descriptor_ptr md_;
    };

    class entity_resolver
    {
    public:
        virtual ~entity_resolver() = default;
        virtual std::expected<entity_identifier, error_storage> const_resolve(fn_compiler_context&) const = 0;
        virtual resource_location const& location() const = 0;
    };

    functional(qname_identifier idval, qname_view qv)
        : id_{ idval }
        , qnameids_{ qv.begin(), qv.end() }
    {
        BOOST_ASSERT(qv.is_absolute());
    }

    inline qname_identifier id() const noexcept { return id_; }
    inline qname_view name() const noexcept { return qname_view{ qnameids_, true }; }

    // returns empty entity_identifier if not resolved
    // throws on resolving error (e.g. circular_dependency_error)
    std::variant<entity_identifier, functional_variable> default_entity(fn_compiler_context&) const;
    entity_identifier do_resolver(fn_compiler_context&, entity_resolver&) const;

    template <typename RT> void set_default_result(RT, resource_location(*location_retriever)(RT const&));
    void set_default_entity(annotated_entity_identifier); // can throw redefinition_error
    void set_default_entity(shared_ptr<entity_resolver>); // can throw redefinition_error
    void set_default_result(functional_variable); // can throw redefinition_error

    void push(shared_ptr<pattern> p)
    {
        patterns_.push_back(std::move(p));
    }

    // looking by argument expressions (pattern matching)
    std::expected<match, error_storage> find(
        fn_compiler_context&,
        syntax_expression_result* capture_result,
        resource_location const& call_location,
        span<const opt_named_expression_t> const& call_args,
        semantic::expression_list_t&, expected_result_t const& expected_result = expected_result_t{}) const;

private:
    qname_identifier id_;
    small_vector<identifier, 4> qnameids_;
    mutable std::variant<annotated_entity_identifier, functional_variable, shared_ptr<entity_resolver>> default_result_; // corresponds to name without call
    small_vector<shared_ptr<pattern>, 1> patterns_;

    mutable fibers::mutex default_entity_mtx_;
};

//struct pattern_local_variable { size_t var_index; };
//struct pattern_variable { identifier id; };
//using pattern_expression_t = variant<nullptr_t, annotated_qname_identifier, entity_identifier, pattern_local_variable, pattern_variable>;

}
