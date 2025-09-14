//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <unordered_map>
//#include <boost/multi_index_container.hpp>
//#include <boost/multi_index/random_access_index.hpp>
//#include <boost/multi_index/ordered_index.hpp>
//#include <boost/multi_index/member.hpp>
#include "function_entity.hpp"

//#define ANNIUM_NO_INLINE_FUNCTIONS 1

namespace annium {

class internal_function_entity : public function_entity
{
    //struct varibale
    //{
    //    variable_identifier id;
    //    intptr_t index;
    //    // to do: metadata
    //};

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

public:
    semantic::expression_span body;
    functional_binding_set bindings;
    functional_binding_set captured_bindings;

    internal_function_entity(qname&& name, entity_signature&& sig, statement_span bd);

    void push_argument(variable_identifier);
    void push_variable(variable_identifier varid, intptr_t index);
    void push_capture(environment&, identifier name, entity_identifier type, intptr_t index);
    //void push_argument(annotated_identifier, local_variable &&);
    //void push_variable(variable_identifier, intptr_t);
    [[nodiscard]] intptr_t resolve_variable_index(variable_identifier) const;

    void visit(entity_visitor const& v) const override { v(*this); }

    inline void set_arg_count(uint64_t count) noexcept { arg_count_ = count; }
    [[nodiscard]] inline uint64_t arg_count() const noexcept { return arg_count_; }

    inline void set_captured_var_count(uint64_t count) noexcept { captured_var_count_ = count; }
    [[nodiscard]] inline uint64_t captured_var_count() const noexcept { return captured_var_count_; }

#ifdef ANNIUM_NO_INLINE_FUNCTIONS
    [[nodiscard]] inline bool is_inline() const noexcept { return false; }
#else
    [[nodiscard]] inline bool is_inline() const noexcept { return !!is_inline_; }
#endif // ANNIUM_NO_INLINE_FUNCTIONS

    inline void set_inline(bool val = true) noexcept { is_inline_ = val ? 1 : 0; }

    [[nodiscard]] inline bool is_built() const noexcept { return !!is_built_; }

    [[nodiscard]] inline bool is_empty() const noexcept { return !!is_empty_; }

    inline std::ostream& print_to(std::ostream& os, environment const& e) const override
    {
        os << "fn "sv;
        return signatured_entity::print_to(os, e);
    }

    [[nodiscard]] error_storage build(environment&);
    [[nodiscard]] error_storage build(fn_compiler_context&);

    bool is_const_eval(environment&) const noexcept;

    inline size_t variables_count() const noexcept { return variables_.size(); }

    inline size_t scope_offset() const noexcept { return variables_count() - captured_var_count_; }

private:
    var_set_t variables_;
    //qname_view ns_;
    statement_span sts_;
    uint64_t arg_count_ : 16; // number of runtime arguments
    uint64_t captured_var_count_ : 16; // number of runtime captured variables
    uint64_t is_built_ : 1;
    uint64_t is_inline_ : 1;
    uint64_t is_empty_ : 1;
    //uint64_t is_void_ : 1;
};

}
