//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "errors.hpp"

#include "errors/utility.hpp"

namespace annium {

void error::rethrow(environment& e) const
{
    throw exception{ e.print(*this) };
}

error::string_t binary_relation_error::left_object(environment const& e) const noexcept
{
    return apply_visitor(printer_resolver_visitor{ e }, left_);
}

error::string_t binary_relation_error::right_object(environment const& e) const noexcept
{
    return apply_visitor(printer_resolver_visitor{ e }, right_);
}

general_error::string_t basic_general_error::object(environment const& e) const noexcept
{ 
    return apply_visitor(printer_resolver_visitor{e}, object_);
}

#if 0
general_error::string_t cast_error::object(environment const& e) const noexcept
{
    if (expr_) return e.print(*expr_);
    return ""sv;
}

general_error::string_t cast_error::description(environment const& e) const noexcept
{
    if (from_) {
        return ("cannot convert from `%1%` to `%2%`"_fmt 
            % e.print(from_)
            % e.print(to_)
        ).str();
    } else {
        return ("cannot convert to `%1%`"_fmt 
            % e.print(to_)
        ).str();
    }
}


general_error::string_t unknown_case_error::object(environment const& e) const noexcept
{
    return e.print(ci_.name.value);
}

general_error::string_t unknown_case_error::description(environment const& e) const noexcept
{
    return ("is not a case of the enumerration %1%"_fmt % e.print(enum_name_)).str();
}
#endif

general_error::string_t undeclared_identifier_error::object(environment const& e) const noexcept
{
    return e.print(idname_.value);
}

general_error::string_t left_not_an_object_error::description(environment const& e) const noexcept
{
    return ("left of `.%1%` must be object, type is `%2%`"_fmt %
        e.print(right_) % e.print(type_)).str();
}

general_error::string_t wrong_lvalue_error::object(environment const& e) const noexcept
{
    return e.print(expr_);
}

std::string ambiguity_error::object(environment const& e) const noexcept
{
    return e.print(functional_.value);
}

std::ostream& error_printer_visitor::print_general(error::location_t const& loc, string_view errstr, string_view object, resource_location const* optseeloc)
{
    bool need_indent = true;
    apply_visitor(make_functional_visitor<void>([this, &need_indent](auto const& l) {
        if constexpr (std::is_same_v<resource_location, std::decay_t<decltype(l)>>) {
            if (!l) return;
            e_.print_to(s_, l, indent());
        } else {
            s_ << indent() << l;
        }
        need_indent = false;
    }), loc);

    if (!object.empty()) {
        if (need_indent) {
            s_ << indent();
            need_indent = false;
        }
        s_ << '`' << object << "`: "sv;
    }
    if (need_indent) s_ << indent();
    s_ << errstr;
    if (optseeloc) {
        s_ << '\n' << indent() << ": see "sv;
        optseeloc->print_to(s_, indent(), resource_print_mode_t::just_pointer);
    }

    return s_;
}

void error_printer_visitor::operator()(general_error const& err)
{
    print_general(
        err.location(),
        apply_visitor(string_resolver_visitor{}, err.description(e_)),
        apply_visitor(string_resolver_visitor{}, err.object(e_)),
        err.ref_location()
    );
    
    if (auto cause = err.cause()) {
        s_ << '\n' << indent() << "caused by: \n"sv;
        inc_indent();
        cause->visit(*this);
        dec_indent();
    }
}

void error_printer_visitor::operator()(binary_relation_error const& err)
{
    if (err.location()) {
        e_.print_to(s_, err.location(), indent()) << ": "sv;
    }
    s_ << '`' <<
        apply_visitor(string_resolver_visitor{}, err.left_object(e_)) <<
        "` and `"sv <<
        apply_visitor(string_resolver_visitor{}, err.right_object(e_)) <<
        "` : "sv;
    
    s_ << apply_visitor(string_resolver_visitor{}, err.description(e_));
    if (auto* ploc = err.ref_location()) {
        e_.print_to(s_ << ", see declaration at "sv, *ploc, indent());
    }
}

void error_printer_visitor::operator()(alt_error const& err)
{
    bool first = true;
    for (auto const& e : err.alternatives) {
        if (!first) {
            s_ << '\n' << indent() << " and \n"sv;
        }
        else { first = false; }
        e->visit(*this);
    }
}

void error_printer_visitor::operator()(ambiguity_error const& err)
{
    print_general(err.location(), "ambiguity call error"sv, err.object(e_));
    s_ << '\n' << indent() << "could be:\n"sv;
    bool first = true;
    for (auto const& e : err.alternatives()) {
        if (!first) {
            s_ << '\n' << indent() << " or \n"sv;
        }
        else { first = false; }
        if (e.location) {
            e_.print_to(s_, e.location, indent()) << ": ";
        }
        e_.print_to(s_, e.sig);
        if (!e.location) {
            s_ << ", aka "sv << e.description;
        }
    }
}


general_error::string_t parameter_not_found_error::description(environment const& e) const noexcept
{
    return ("parameter `%1%` of `%2%` is not found"_fmt %
        e.print(param.value) % e.print(entity_name)).str();
}

//void error_printer_visitor::operator()(parameter_not_found_error const& err)
//{
//    s_ << ("parameter `%1%` of `%2%` is not found"_fmt % e_.print(err.param.value) % e_.print(err.entity_name)).str();
//}

}
