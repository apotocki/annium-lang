//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <vector>
#include <expected>

#include "sonia/type_traits.hpp"
#include "sonia/filesystem.hpp"

#include "ast_terms.hpp"
#include "sonia/logger/logger.hpp"

#include "annium/ast/ast_resource.hpp"
#include "annium/ast/arena.hpp"

#include "annium/environment.hpp"

namespace annium {

class environment;
class syntax_expression_resource;

class parser_context
{
public:
    inline explicit parser_context(environment& e) noexcept
        : environment_{ e }
    {}
    ~parser_context();

    annotated_string_view make_string_view(annotated_string_view) const;
    string_view make_string_view(string_view) const;
    numetron::integer_view make_integer_view(string_view) const;
    numetron::decimal_view make_decimal_view(string_view) const;
    entity_identifier make_entity_identifier(builtin_eid) const;

    identifier new_identifier() const;
    identifier make_identifier(string_view &&) const;
    annotated_identifier make_identifier(annotated_string_view &&) const;

    qname_view make_qname_view(qname &&) const;
    annotated_qname_view make_qname_view(annotated_qname &&) const;
    annotated_qname_view make_qname_view(annotated_string_view &&) const;

    //annotated_qname_identifier make_qname_identifier(annotated_qname) const;
    //annotated_qname_identifier make_qname_identifier(annotated_string_view, bool is_abs) const;

    //managed_statement_list new_statement_list() const;
    //statement_span push(managed_statement_list&&);

    //identifier make_required_identifier(string_view);

    void set_root_statements(statement_list_t&&);
    inline span<const statement> statements() const noexcept { return statements_; }
    //inline managed_statement_list& statements() noexcept { return statements_; }

    void append_error(int line_begin, int col_begin, int line_end, int col_end, string_view tok);
    void append_error(std::string errmsg);

    resource_identifier get_resource_id() const noexcept { return resource_ ? resource_->id : resource_identifier{}; }

    std::expected<span<const statement>, std::string> parse(fs::path const& f, fs::path const* base_path = nullptr);
    std::expected<span<const statement>, std::string> parse_string(string_view);

    // factory methods for AST terms
    template <typename TermT, typename... Args>
    inline TermT const* make(Args&&... args) const
    {
        return arena_->template make<TermT>(std::forward<Args>(args)...);
    }

    template <typename TermT>
    inline span<TermT const*> make_array(span<TermT const*> sv) const
    {
        return sv.empty() ? sv : arena_->template make_array<TermT>(sv);
    }

    template <typename TermT>
    inline span<TermT const> make_array(span<TermT const> sv) const
    {
        return sv.empty() ? sv : arena_->template make_array<TermT>(sv);
    }

    template <typename TermT, typename... Args>
    inline span<TermT const> make_span_for_args(Args&&... args) const
    {
        TermT args_arr[] = { std::forward<Args>(args)... };
        return make_array<opt_named_expression_t>(args_arr);
    }

    template <typename ArgT>
    void debug(ArgT && arg)
    {
        (void)arg;
    }

private:
    std::expected<span<const statement>, std::string> parse(string_view code);

    environment& environment_;

    ast_resource const* resource_ = nullptr;
    
    std::vector<std::string> error_messages_;
    
    span<const statement> root_statements_;
    span<const statement> statements_;

    std::unique_ptr<arena> arena_;
};

}
