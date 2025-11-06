//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include <variant>

#include "sonia/string.hpp"
#include "sonia/shared_ptr.hpp"

#include "annium/terms.hpp"

namespace annium {

class environment;

class ast_resource : public code_resource
{
protected:
    mutable std::variant<std::string, std::vector<char>> src_;
    mutable std::vector<string_view> lines;
    size_t hash_;

    virtual void prepare_lines() const;
    void rebuild_hash() noexcept;

public:
    explicit ast_resource(std::vector<char> src) noexcept;
    explicit ast_resource(std::string src = {}) noexcept;

    std::ostream& print_to(std::ostream& s, string_view indent, int line, int column, resource_print_mode_t mode) const override;
    
    size_t hash() const noexcept override { return hash_; }

    bool equal(code_resource const& rhs) const noexcept override;

    string_view get_source() const noexcept;
};

}
