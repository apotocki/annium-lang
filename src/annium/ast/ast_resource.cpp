//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium/ast/ast_resource.hpp"
#include "annium/ast/arena.hpp"

namespace annium {

ast_resource::ast_resource(std::vector<char> src, shared_ptr<arena> aval) noexcept
    : src_{ std::move(src) }
    , expressions_arena_{ std::move(aval) }
{
    if (!expressions_arena_) {
        expressions_arena_ = make_shared<arena>();
    }
    rebuild_hash();
}

ast_resource::ast_resource(std::string src, shared_ptr<arena> aval) noexcept
    : src_{ std::move(src) }
    , expressions_arena_{ std::move(aval) }
{
    if (!expressions_arena_) {
        expressions_arena_ = make_shared<arena>();
    }
    rebuild_hash();
}

void ast_resource::rebuild_hash() noexcept
{
    hash_ = std::visit([](auto&& srcval)->size_t { return std::hash<string_view>{}(string_view{ srcval.data(), srcval.size() }); }, src_);
}

string_view ast_resource::get_source() const noexcept
{
    return std::visit([](auto&& srcval) { return string_view{ srcval.data(), srcval.size() }; }, src_);
}

bool ast_resource::equal(code_resource const& rhs) const noexcept
{
    if (auto sr = dynamic_cast<ast_resource const*>(&rhs)) {
        return src_ == sr->src_;
    }
    return false;
}

void ast_resource::prepare_lines() const
{
    if (!lines.empty()) return;
    // Split source into lines
    string_view code = get_source();
    size_t start = 0;
    for (size_t i = 0; i <= code.size(); ++i) {
        if (i == code.size() || code[i] == '\n') {
            // Handle both \n and \r\n line endings
            size_t end = i;
            if (end > start && code[end - 1] == '\r') {
                --end;
            }
            lines.emplace_back(code.data() + start, end - start);
            start = i + 1;
        }
    }
}

std::ostream& ast_resource::print_to(std::ostream& s, string_view indent, int line, int column, resource_print_mode_t mode) const
{
    prepare_lines();

    // Adjust for 1-based line numbering
    const int target_line = line - 1;
    const int target_column = column - 1;

    // Determine range of lines to show (2-3 lines before + target line)
    const int context_lines = 0;
    const int start_line = (std::max)(0, target_line - context_lines);
    const int end_line = (std::min)(static_cast<int>(lines.size()) - 1, target_line);

    // Print description and location
    print_description(s << indent) << " at " << line << ':' << column << '\n';

    // Calculate the width needed for line numbers
    const size_t max_line_num = (std::max)(end_line + 1, 1);
    const size_t line_num_width = std::to_string(max_line_num).length();

    // Print context lines and target line
    for (int i = start_line; i <= end_line; ++i) {
        // Print line number with padding
        s << indent << std::setw(line_num_width) << std::right << (i + 1) << " | ";

        if (i < static_cast<int>(lines.size())) {
            s << lines[i];
        }
        s << '\n';

        // Print caret pointer for the target line
        if (i == target_line) {
            // Print spaces for line number and separator
            s << indent << std::string(line_num_width, ' ') << " | ";

            // Print spaces up to the target column, then caret
            const int safe_column = (std::max)(0, (std::min)(target_column, static_cast<int>(lines[i].size())));
            if (mode == resource_print_mode_t::just_pointer) {
                s << std::string(safe_column, ' ') << '^';
            }
            else {
                s << std::string(safe_column, ' ') << "^----- ";
            }
            //s << '\n';
        }
    }

    return s;
}

}
