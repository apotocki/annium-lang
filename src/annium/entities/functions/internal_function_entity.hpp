//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <unordered_map>
#include <atomic>
#include <bit>

#include "annium/semantic.hpp"
#include "annium/entities/signatured_entity.hpp"
#include "annium/functional/functional.hpp"

namespace annium {

class fn_compiler_context;

class indirect_internal_function_entity : public tagged_signatured_entity<resource_location>
{
    entity_signature const& sig_;

protected:
    resource_location const& get_tag() const noexcept override final { return location; }
    entity_signature const* signature() const noexcept override final { return &sig_; }

public:
    inline indirect_internal_function_entity(entity_signature const& sig, resource_location const& loc) noexcept
        : sig_{ sig }
    {
        location = loc;
    }
};

class internal_function_entity : public tagged_signatured_entity<resource_location>
{
    using var_set_t = std::unordered_map<variable_identifier, intptr_t, sonia::hash<variable_identifier>>;
    /*
    using var_set_t = boost::multi_index::multi_index_container<
        varibale,
        boost::multi_index::indexed_by<
            boost::multi_index::random_access<>,
            boost::multi_index::ordered_unique<
                boost::multi_index::member<varibale, variable_identifier, &varibale::id>
            >
        >
    >;
    */
    //small_vector<intptr_t, 16> scope_thresholds_;

protected:
    qname name_;
    entity_signature sig_;
    shared_ptr<fn_compiler_context> context_;

public:
    semantic::expression_span body;
    basic_functional_binding bindings;
    //layered_binding_set captured_bindings;
    error_storage build_errors;
    field_descriptor result;

    internal_function_entity(environment& env, qname&& name, entity_signature&& sig, resource_location loc, field_descriptor r);

    inline fn_compiler_context& context() noexcept { return *context_; }
    void set_captured_end_offset() noexcept;
    void set_argument_variables() noexcept;
    void set_body(span<const statement> bd) noexcept { sts_ = std::move(bd); }

    //void push_argument(variable_identifier);
    void push_variable(variable_identifier varid, intptr_t index);
    //void push_capture(environment&, identifier name, entity_identifier type, intptr_t index);
    //void push_argument(annotated_identifier, local_variable &&);
    //void push_variable(variable_identifier, intptr_t);
    [[nodiscard]] intptr_t resolve_variable_index(variable_identifier) const;

    void visit(entity_visitor const& v) const override { v(*this); }

    //size_t hash() const noexcept override final;
    //bool equal(entity const& rhs) const noexcept override final;
    
    //inline void set_captured_var_count(uint64_t count) noexcept { captured_var_count_ = count; }
    //[[nodiscard]] inline uint64_t captured_var_count() const noexcept { return captured_var_count_; }

    [[nodiscard]] bool is_inline() const noexcept;

private:
    struct state_fields {
        uint64_t arg_count : 16; // number of runtime arguments
        uint64_t variable_count : 16;
        uint64_t captured_offset : 16;
        uint64_t is_provision : 1;
        uint64_t is_built : 1;
        uint64_t is_inline : 1;
        uint64_t is_empty : 1;
        uint64_t force_fp : 1;
        //uint64_t is_void_ : 1;
    };

    static constexpr uint64_t mask_is_provision = 1ull << 48;
    static constexpr uint64_t mask_is_built     = 1ull << 49;
    static constexpr uint64_t mask_is_inline    = 1ull << 50;
    static constexpr uint64_t mask_is_empty     = 1ull << 51;
    static constexpr uint64_t mask_force_fp     = 1ull << 52;

    inline uint64_t load_state(std::memory_order mo = std::memory_order_relaxed) const noexcept
    {
        return state_.load(mo);
    }

    inline void update_state(uint64_t v, std::memory_order mo = std::memory_order_relaxed) noexcept
    {
        state_.store(v, mo);
    }

    template <class F>
    inline void update_state_cas(F&& f, std::memory_order success = std::memory_order_relaxed, std::memory_order fail = std::memory_order_relaxed) noexcept
    {
        uint64_t cur = state_.load(fail);
        for (;;) {
            uint64_t next = f(cur);
            if (state_.compare_exchange_weak(cur, next, success, fail)) return;
        }
    }

    inline bool get_flag(uint64_t mask, std::memory_order mo = std::memory_order_relaxed) const noexcept
    {
        return (state_.load(mo) & mask) != 0;
    }

    inline void set_flag(uint64_t mask, bool val, std::memory_order mo = std::memory_order_relaxed) noexcept
    {
        update_state_cas([&](uint64_t cur) {
            return val ? (cur | mask) : (cur & ~mask);
        }, mo, std::memory_order_relaxed);
    }

public:
    inline void set_inline(bool val = true) noexcept
    {
        set_flag(mask_is_inline, val, std::memory_order_relaxed);
    }

    inline void set_provision(bool val = true) noexcept
    {
        set_flag(mask_is_provision, val, std::memory_order_relaxed);
    }

    [[nodiscard]] inline bool is_provision() const noexcept { return get_flag(mask_is_provision, std::memory_order_relaxed); }

    // publish/consume barrier for build results (body/result/etc.)
    [[nodiscard]] inline bool is_built() const noexcept { return get_flag(mask_is_built, std::memory_order_acquire); }

    [[nodiscard]] inline bool is_empty() const noexcept { return get_flag(mask_is_empty, std::memory_order_relaxed); }

    inline void set_built(bool val = true) noexcept
    {
        // if other code ever resets `is_built` to false, keep it relaxed.
        // the important part is the `true` publication.
        set_flag(mask_is_built, val, val ? std::memory_order_release : std::memory_order_relaxed);
    }

    inline void set_arg_count(uint64_t count) noexcept
    {
        update_state_cas([&](uint64_t cur) {
            state_fields flds = std::bit_cast<state_fields>(cur);
            flds.arg_count = count;
            return std::bit_cast<uint64_t>(flds);
        }, std::memory_order_relaxed, std::memory_order_relaxed);
    }

    [[nodiscard]] inline uint64_t arg_count() const noexcept
    {
        return std::bit_cast<state_fields>(load_state(std::memory_order_relaxed)).arg_count;
    }

    std::ostream& print_to(std::ostream& os, environment const& e) const override;

    [[nodiscard]] error_storage build();
    [[nodiscard]] error_storage build(fn_compiler_context&);

    [[nodiscard]] inline qname_view name() const noexcept { return name_; }

    [[nodiscard]] bool is_const_eval(environment&) const noexcept;

    //[[nodiscard]] inline size_t variables_count() const noexcept { return variables_.size(); }

    //[[nodiscard]] inline size_t scope_offset() const noexcept { return variables_count() - captured_var_count_; }

    entity_signature const* signature() const noexcept override { return &sig_; }
        
    inline void set_need_framepointer(bool val = true) noexcept
    {
        set_flag(mask_force_fp, val, std::memory_order_relaxed);
    }

    [[nodiscard]] bool need_framepointer() const noexcept;

protected:
    resource_location const& get_tag() const noexcept override final { return location; }

private:
    var_set_t variables_;
    span<const statement> sts_;
    std::atomic<uint64_t> state_{ 0 };
};

}
