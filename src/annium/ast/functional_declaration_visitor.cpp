//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "functional_declaration_visitor.hpp"

#include "fn_compiler_context.hpp"

namespace annium {

inline environment& functional_declaration_visitor::env() const noexcept { return ctx.env(); }

error_storage functional_declaration_visitor::apply(span<const statement> initial_decls) const
{
    decl_stack_.clear();
    decl_stack_.emplace_back(initial_decls);
    for (; !decl_stack_.empty(); ) {
        if (decl_stack_.back().empty()) {
            decl_stack_.pop_back();
            continue;
        }
        size_t index = decl_stack_.size() - 1;
        if (auto err = apply_visitor(*this, decl_stack_.back().front()); err) return err;
        decl_stack_[index] = decl_stack_[index].subspan(1);
    }
    return {};
}

}
