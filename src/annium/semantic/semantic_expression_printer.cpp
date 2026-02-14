//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "expression_printer.hpp"

#include "annium/environment.hpp"
#include "annium/utility/linked_list.ipp"

namespace annium::semantic {

void expression_printer_visitor::do_indent() const
{
    for (size_t i = 0; i < indent_cnt; ++i) ss << indent;
}

void expression_printer_visitor::operator()(empty_t const&) const
{
    do_indent();
    ss << "noop\n"sv;
}

void expression_printer_visitor::operator()(expression_span esp) const
{
    ++indent_cnt;
    while (esp) {
        visit(*this, esp.front());
        esp.pop_front();
    }
    --indent_cnt;
}

void expression_printer_visitor::operator()(expression_list_t const& evec) const
{
    ++indent_cnt;
    for (expression const& e : evec) {
        visit(*this, e);
    }
    --indent_cnt;
}

void expression_printer_visitor::operator()(conditional_t const& c) const
{
    if (c.true_branch) {
        do_indent();
        ss << "if true\n"sv;
        this->operator()(c.true_branch);
    }
    if (c.false_branch) {
        do_indent();
        ss << "if false\n"sv;
        this->operator()(c.false_branch);
    }
}

void expression_printer_visitor::operator()(loop_scope_t const& ls) const
{
    do_indent();
    ss << "loop\n"sv;
    if (ls.branch) {
        ++indent_cnt;
        do_indent();
        ss << "loop branch\n"sv;
        this->operator()(ls.branch);
        do_indent();
        ss << "endloop branch\n"sv;
        --indent_cnt;
    }
    if (ls.continue_branch) {
        ++indent_cnt;
        do_indent();
        ss << "loop continue branch\n"sv;
        this->operator()(ls.continue_branch);
        do_indent();
        ss << "endloop continue branch\n"sv;
        --indent_cnt;
    }
    do_indent();
    ss << "endloop\n"sv;
}

void expression_printer_visitor::operator()(loop_continuer const&) const
{
    do_indent();
    ss << "continue\n"sv;
}

void expression_printer_visitor::operator()(loop_breaker const&) const
{
    do_indent();
    ss << "break\n"sv;
}

void expression_printer_visitor::operator()(push_special_value const& psv) const
{
    do_indent();
    ss << "push special_value: "sv;
    switch (psv.kind) {
    case push_special_value::kind_type::stack_size:
        ss << "stack_size\n"sv;
        break;
    default:
        ss << "unknown\n"sv;
        break;
    }
}

void expression_printer_visitor::operator()(push_value const& v) const
{
    do_indent();
    ss << "push "sv;
    visit(value_printer_visitor { e_, ss }, v.value);
    ss << '\n';
}

void expression_printer_visitor::operator()(push_by_offset const& v) const
{
    do_indent();
    ss << "push OFFSET("sv << v.offset << ")\n"sv;
}

void expression_printer_visitor::operator()(push_local_variable const& lv) const
{
    do_indent();
    ss << "push VAR("sv << lv.varid.value;
#ifdef SONIA_LANG_DEBUG
    e_.print_to(ss << ") "sv, lv.varid.debug_name) << '\n';
#else
    ss << ")\n"sv;
#endif
}

void expression_printer_visitor::operator()(push_variable const& v) const
{
    do_indent();
    e_.print_to(ss << "get EXT_VAR("sv, v.var.name) << ")\n"sv;
}

void expression_printer_visitor::operator()(dup_stack_top const&) const
{
    do_indent();
    ss << "dup\n"sv;
}

void expression_printer_visitor::operator()(set_variable const& v) const
{
    do_indent();
    e_.print_to(ss << "set EXT_VAR("sv, v.var.name) << ")\n"sv;
}

void expression_printer_visitor::operator()(set_local_variable const& lv) const
{
    do_indent();
    ss << "set VAR("sv << lv.varid.value;
#ifdef SONIA_LANG_DEBUG
    e_.print_to(ss << ") "sv, lv.varid.debug_name) << '\n';
#else
    ss << ")\n"sv;
#endif
}

void expression_printer_visitor::operator()(invoke_function const& f) const
{
    do_indent();
    ss << "invoke "sv << f.fn;
#ifdef SONIA_LANG_DEBUG
    ss << "\t; "sv << f.fn.debug_name;
#endif
    ss << '\n';
}

void expression_printer_visitor::operator()(return_statement const&) const
{
    do_indent();
    ss << "return\n"sv;
}

void expression_printer_visitor::operator()(truncate_values const& tv) const
{
    do_indent();
    ss << "truncate count: "sv << tv.count << ", keep back: "sv << tv.keep_back << '\n';
}

void value_printer_visitor::operator()(null_t const&) const
{
    ss << "nil"sv;
}

void value_printer_visitor::operator()(bool v) const
{
    ss << (v ? "true"sv : "false"sv);
}

void value_printer_visitor::operator()(entity_identifier eid) const
{
    e_.print_to(ss, eid);
}

void value_printer_visitor::operator()(function_value const& fval) const
{
    e_.print_to(ss << "fn "sv, fval.mangled_name);
}

}
