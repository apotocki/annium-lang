//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium/semantic.hpp"

namespace annium { class unit; }

namespace annium::semantic {

class value_printer_visitor : public static_visitor<void>
{
    environment const& e_;
    std::ostream& ss;

public:
    explicit value_printer_visitor(environment const& e, std::ostream& s)
        : e_{ e }, ss{ s } {}

    void operator()(null_t const&) const;
    void operator()(bool) const;
    void operator()(entity_identifier) const;
    void operator()(function_value const& fval) const;
    //void operator()(uint64_t) const;
    //void operator()(mp::integer) const;
    //void operator()(mp::decimal) const;
    //void operator()(small_string) const;

    template <typename T>
    void operator()(std::vector<T> const& vec) const
    {
        ss << '[';
        bool first = true;
        for (T const& v : vec) {
            if (first) first = false;
            else { ss << ", "sv; }
            apply_visitor(*this, v);
        }
        ss << ']';
    }

    template <typename T>
    void operator()(T const& val) const
    {
        ss << val;
    }
};

class expression_printer_visitor : public static_visitor<void>
{
    environment const& e_;
    std::ostream& ss;
    string_view indent;
    mutable size_t indent_cnt;

public:
    explicit expression_printer_visitor(environment const& e, std::ostream& s, string_view indentstr = "  "sv, size_t icnt = 0)
        : e_{ e }, ss{ s }, indent{ indentstr }, indent_cnt{ icnt } {}

    void operator()(empty_t const&) const;
    void operator()(expression_span) const;
    void operator()(expression_list_t const&) const;
    void operator()(push_value const&) const;
    void operator()(push_local_variable const&) const;
    void operator()(push_special_value const&) const;
    void operator()(push_by_offset const&) const;
    void operator()(set_local_variable const&) const;
    void operator()(invoke_function const&) const;
    void operator()(return_statement const&) const;
    void operator()(truncate_values const&) const;

    void operator()(conditional_t const&) const;
    void operator()(loop_scope_t const&) const;
    void operator()(loop_continuer const&) const;
    void operator()(loop_breaker const&) const;

    template <typename T>
    void operator()(T const& se) const
    {
        (void)se; // suppress unused warning
        THROW_NOT_IMPLEMENTED_ERROR();
    }

private:
    void do_indent() const;
};

}
