//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.


#include "sonia/config.hpp"
#include "parser.hpp"

#include "sonia/small_vector.hpp"

#include "sonia/utility/parsers/utility.hpp"
#include "sonia/utility/scope_exit.hpp"

#include "numetron/integer_view.hpp"
#include "numetron/limbs_from_string.hpp"
#include "numetron/limbs_from_decimal_string.hpp"

using namespace annium;

#include "annium.tab.hpp"

using YYSTYPE = annium_lang::parser::semantic_type;
using YYLTYPE = annium_lang::parser::location_type;

#include "annium.yy.hpp"

#include "annium/utility/linked_list.ipp"

#include "annium/ast/ast_resource.hpp"

namespace annium {

identifier parser_context::new_identifier() const
{
    return environment_.new_identifier();
}

identifier parser_context::make_identifier(string_view&& str) const
{
    return environment_.slregistry().resolve(str);
}

annotated_identifier parser_context::make_identifier(annotated_string_view && astr) const
{
    return { make_identifier(std::move(astr.value)), std::move(astr.location) };
}

qname_view parser_context::make_qname_view(qname && qn) const
{
    auto sp = make_array<identifier>(qn.parts());
    return qname_view{ sp, qn.is_absolute() };
}

annotated_qname_view parser_context::make_qname_view(annotated_qname && aqn) const
{
    return annotated_qname_view{ make_qname_view(std::move(aqn.value)), std::move(aqn.location) };
}

annotated_qname_view parser_context::make_qname_view(annotated_string_view && astr) const
{
    identifier strid = environment_.slregistry().resolve(astr.value);
    auto sp = make_array<identifier>(span(&strid, 1));
    return annotated_qname_view{ qname_view{ sp, false }, std::move(astr.location) };
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

annotated_string_view parser_context::make_string_view(annotated_string_view str) const
{
    return { make_string_view(str.value), std::move(str.location) };
}

string_view parser_context::make_string_view(string_view str) const
{
    small_vector<char, 128> buff;
    parsers::normilize_json_string(str.begin(), str.end(), std::back_inserter(buff));
    auto sp = make_array<char>(buff);
    return string_view{ sp.data(), sp.size() };
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

template <typename LimbT>
struct inplace_allocator_type
{
    using value_type = LimbT;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using propagate_on_container_move_assignment = std::true_type;

    arena& arena_;
    span<LimbT> inplace_limbs_;
    bool inplace_allocation_ = false;
    inplace_allocator_type(arena& a, span<LimbT> inplace) : arena_{ a }, inplace_limbs_{ inplace } {}

    LimbT* allocate(size_t cnt)
    {
        if (cnt <= inplace_limbs_.size() && !inplace_allocation_) {
            inplace_allocation_ = true;
            return inplace_limbs_.data();
        } else {
            return arena_.make_array<LimbT>(cnt).data();
        }
    }

    void deallocate(LimbT* ptr, size_t /* sz */)
    {
        if (std::equal_to<LimbT*>{}(ptr, inplace_limbs_.data())) {
            inplace_allocation_ = false;
        }
    }
};

numetron::integer_view parser_context::make_integer_view(string_view str) const
{
    using limb_t = numetron::integer_view::limb_type;
    limb_t inplace_limbs[1];
    auto limbs = numetron::to_limbs<uint64_t>(str, inplace_allocator_type<limb_t>{ *arena_, inplace_limbs });
    if (!limbs) {
        std::rethrow_exception(limbs.error());
    }
    auto [ls, sz, _, sign] = *limbs;
    if (sz == 1) {
        return numetron::integer_view::make_inplace(span{ ls, sz }, sign);
    }
    return numetron::integer_view(span{ ls, sz }, sign);
}
//
numetron::decimal_view parser_context::make_decimal_view(string_view str) const
{
    using limb_t = numetron::integer_view::limb_type;
    numetron::decimal tmpdec{ str };
    auto sign_part= tmpdec.significand();
    auto exp_part = tmpdec.exponent();

    if (!sign_part.is_inplace()) {
        auto [sign_limbs, mask, sgn] = sign_part.decompose();
        auto arena_sign_limbs = arena_->make_array<limb_t>(sign_limbs);
        arena_sign_limbs.back() &= mask;
        sign_part = numetron::integer_view::make_inplace(arena_sign_limbs, sgn);
    }

    if (!exp_part.is_inplace()) {
        auto [exp_limbs, mask, sgn] = exp_part.decompose();
        auto arena_exp_limbs = arena_->make_array<limb_t>(exp_limbs);
        arena_exp_limbs.back() &= mask;
        exp_part = numetron::integer_view::make_inplace(arena_exp_limbs, sgn);
    }
    return numetron::decimal_view{ sign_part, exp_part };
}

entity_identifier parser_context::make_entity_identifier(builtin_eid beid) const
{
    return environment_.get(beid);
}

void parser_context::append_error(int line_begin, int col_begin, int line_end, int col_end, string_view tok)
{
    (void)line_end;
    (void)col_end;
    std::ostringstream ress;
    resource_->print_to(ress, ""sv, line_begin, col_begin, resource_print_mode_t::default_mode);
    //resource_->print_description(ress) << ':' << line_begin << '.' << col_begin << '-' << line_end << '.' << col_end;
    ress << ": error: " << tok;
    append_error(ress.str());
    //"%1%(%2%,%3%-%4%,%5%): error: %6%"
    //"%1%:%2%.%3%-%4%.%5%: error: %6%"_fmt % resource_->print_description() % line_begin % col_begin % line_end % col_end % tok;
    //ctx.append_error(("%1%:%2%.%3%-%4%.%5%: error: %6%"_fmt
    //    % ctx.get_resource()
    //    % yylloc->begin.line % yylloc->begin.column % yylloc->end.line % yylloc->end.column % string_view{ yytext, (size_t)yyleng }).str());
}

void parser_context::append_error(std::string errmsg)
{
    error_messages_.push_back(std::move(errmsg));
}

//managed_statement_list parser_context::new_statement_list() const
//{
//    return managed_statement_list{ environment_ };
//}
//
//statement_span parser_context::push(managed_statement_list&& msl)
//{
//    statement_span result = msl;
//    statements_.splice_back(msl);
//    BOOST_ASSERT(!msl);
//    return result;
//}

void parser_context::set_root_statements(statement_list_t&& sts)
{
    root_statements_ = make_array<statement>(sts);
}

std::expected<span<const statement>, std::string> parser_context::parse(fs::path const& f, fs::path const* base_path)
{
    resource_ = &environment_.get_resource(f, base_path);
    return parse(resource_->get_source());
}

std::expected<span<const statement>, std::string> parser_context::parse_string(string_view code)
{
    resource_ = &environment_.get_resource(code);
    return parse(code);
}

std::expected<span<const statement>, std::string> parser_context::parse(string_view code)
{
    arena_ = environment_.acquire_arena();
    SCOPE_EXIT([this]() { environment_.release_arena(std::move(arena_)); });

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
