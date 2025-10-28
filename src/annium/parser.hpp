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

namespace annium {

class environment;
class syntax_expression_resource;

class parser_context
{
public:
    inline explicit parser_context(environment& e) noexcept
        : environment_{ e }
        , statements_{ e }
    {}
    ~parser_context();

    annotated_string make_string(annotated_string_view) const;
    numetron::integer make_integer(string_view) const;
    numetron::decimal make_decimal(string_view) const;
    annotated_entity_identifier make_void(resource_location) const;

    identifier new_identifier() const;
    annotated_identifier make_identifier(annotated_string_view) const;
    
    annotated_qname make_qname(annotated_string_view) const;

    //annotated_qname_identifier make_qname_identifier(annotated_qname) const;
    //annotated_qname_identifier make_qname_identifier(annotated_string_view, bool is_abs) const;

    managed_statement_list new_statement_list() const;
    statement_span push(managed_statement_list&&);

    //identifier make_required_identifier(string_view);

    void set_root_statements(managed_statement_list&&);
    inline managed_statement_list const& statements() const noexcept { return statements_; }
    inline managed_statement_list& statements() noexcept { return statements_; }

    void append_error(int line_begin, int col_begin, int line_end, int col_end, string_view tok);
    void append_error(std::string errmsg);

    resource_identifier get_resource_id() const noexcept { return resource_ ? resource_->id : resource_identifier{}; }

    std::expected<statement_span, std::string> parse(fs::path const& f, fs::path const* base_path = nullptr);
    std::expected<statement_span, std::string> parse_string(string_view);

private:
    std::expected<statement_span, std::string> parse(string_view code);

    environment& environment_;

    ast_resource const* resource_ = nullptr;
    
    std::vector<std::string> error_messages_;
    
    statement_span root_statements_;
    managed_statement_list statements_;
};

}
