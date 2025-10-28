//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.


#include "sonia/config.hpp"
#include "parser.hpp"

#include "sonia/small_vector.hpp"

#include "sonia/utility/parsers/utility.hpp"
#include "sonia/utility/scope_exit.hpp"

#include "numetron/integer_view.hpp"

using namespace annium;

#include "annium.tab.hpp"

using YYSTYPE = annium_lang::parser::semantic_type;
using YYLTYPE = annium_lang::parser::location_type;

#include "annium.yy.hpp"

#include "environment.hpp"
#include "annium/utility/linked_list.ipp"

#include "annium/ast/ast_resource.hpp"
#include "annium/ast/arena.hpp"

namespace annium {

identifier parser_context::new_identifier() const
{
    return environment_.new_identifier();
}

annotated_identifier parser_context::make_identifier(annotated_string_view astr) const
{
    return { environment_.slregistry().resolve(astr.value), astr.location };
}

annotated_qname parser_context::make_qname(annotated_string_view astr) const
{
    return annotated_qname{ qname{environment_.slregistry().resolve(astr.value), false}, std::move(astr.location) };
}

//annotated_qname_identifier parser_context::make_qname_identifier(annotated_qname aqn) const
//{
//    return annotated_qname_identifier{ environment_.fregistry().resolve(aqn.value).id(), aqn.location };
//}
//
//annotated_qname_identifier parser_context::make_qname_identifier(annotated_string_view asv, bool is_abs) const
//{
//    return annotated_qname_identifier{ environment_.fregistry().resolve(qname{environment_.slregistry().resolve(asv.value), is_abs}).id(), asv.location };
//}

//identifier parser_context::make_required_identifier(string_view str)
//{
//    return identifier{ env_.iregistry().resolve(str).value, true};
//}

annotated_string parser_context::make_string(annotated_string_view str) const
{
    small_vector<char, 128> buff;
    parsers::normilize_json_string(str.value.begin(), str.value.end(), std::back_inserter(buff));
    return { small_string{ buff.data(), buff.size()}, str.location };
}

//integer_literal parser_context::make_integer_literal(string_view str)
//{
//    auto it = std::find(str.begin(), str.end(), '_');
//    BOOST_ASSERT(it != str.end());
//    return integer_literal{ 
//        sonia::decimal::parse(string_view(str.begin(), it)),
//        qname{make_identifier(string_view(it + 1, str.end()))}
//    };
//}

numetron::integer parser_context::make_integer(string_view str) const
{
    return numetron::integer(str);
}
//
numetron::decimal parser_context::make_decimal(string_view str) const
{
    return numetron::decimal(str);
}

annotated_entity_identifier parser_context::make_void(resource_location loc) const
{
    return annotated_entity_identifier{ environment_.get(builtin_eid::void_), std::move(loc) };
}

void parser_context::append_error(int line_begin, int col_begin, int line_end, int col_end, string_view tok)
{
    std::ostringstream ress;
    resource_->print_description(ress) << ':' << line_begin << '.' << col_begin << '-' << line_end << '.' << col_end;
    ress << ": error: " << tok;
    append_error(ress.str());
    //"%1%(%2%,%3%-%4%,%5%): error: %6%"
    //"%1%:%2%.%3%-%4%.%5%: error: %6%"_fmt % resource_->print_description() % line_begin % col_begin % line_end % col_end % tok;
    //ctx.append_error(("%1%:%2%.%3%-%4%.%5%: error: %6%"_fmt \
    //    % ctx.get_resource() \
    //    % yylloc->begin.line % yylloc->begin.column % yylloc->end.line % yylloc->end.column % string_view{ yytext, (size_t)yyleng }).str());
}

void parser_context::append_error(std::string errmsg)
{
    error_messages_.push_back(std::move(errmsg));
}

managed_statement_list parser_context::new_statement_list() const
{
    return managed_statement_list{ environment_ };
}

statement_span parser_context::push(managed_statement_list&& msl)
{
    statement_span result = msl;
    statements_.splice_back(msl);
    BOOST_ASSERT(!msl);
    return result;
}

void parser_context::set_root_statements(managed_statement_list&& sts)
{
    root_statements_ = push(std::move(sts));
}

std::expected<statement_span, std::string> parser_context::parse(fs::path const& f, fs::path const* base_path)
{
    resource_ = &environment_.get_resource(f, base_path);
    return parse(resource_->get_source());
}

std::expected<statement_span, std::string> parser_context::parse_string(string_view code)
{
    resource_ = &environment_.get_resource(code);
    return parse(code);
}

std::expected<statement_span, std::string> parser_context::parse(string_view code)
{
    auto sc_data = std::make_unique<sonia::lang::lex::scanner_data>();

    void* scanner;
    annium_langlex_init_extra(sc_data.get(), &scanner);
    SCOPE_EXIT([scanner]() { annium_langlex_destroy(scanner); });

    size_t buffsz = code.size() + 2; // +2 for null terminators
    std::unique_ptr<char[]> buffer(new char[buffsz]);
    std::copy(code.begin(), code.end(), buffer.get());
    buffer[code.size()] = 0;
    buffer[code.size() + 1] = 0;

    YY_BUFFER_STATE st = annium_lang_scan_buffer(&buffer[0], buffsz, scanner);
    SCOPE_EXIT([st, scanner]() { annium_lang_delete_buffer(st, scanner); });

    annium_langset_lineno(1, scanner);
    annium_langset_column(1, scanner);

    annium_lang::parser p(scanner, *this);

    bool parse_result = true;
    try {
        parse_result = p.parse();
    } catch (std::exception const& e) {
        append_error(e.what());
    }
    if (parse_result || !error_messages_.empty()) {
        std::ostringstream ress{};
        resource_->print_description(ress);
        for (auto const& l : sc_data->loc_stack) {
            append_error(("%1%:%2%.%3%: error: unterminated /* comment"_fmt
                % ress.str()
                % l.line % l.column).str());
        }

        std::ostringstream ss;
        for (auto const& err : error_messages_) {
            if (&err != &error_messages_.front()) ss << '\n';
            ss << err;
        }
        return std::unexpected(ss.str());
    }
    return root_statements_;
}

parser_context::~parser_context()
{
    //statements_.clear();
}

}
