//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/string.hpp"
#include "sonia/filesystem.hpp"
#include "sonia/shared_ptr.hpp"
#include "sonia/span.hpp"
#include "sonia/function.hpp"
#include "sonia/utility/invocation/invocation.hpp"

namespace annium {

using namespace sonia;

namespace detail { class annium_impl; }

class language
{
public:
    language();
    virtual ~language();

    void set_cout_writer(function<void(string_view)>);
    void set_environment(invocation::invocable*);
    void load(fs::path const& srcfile, span<string_view> args = {});
    void load(string_view code, span<string_view> args = {});

    smart_blob invoke(blob_result ftor, span<const blob_result> args);
    smart_blob call(string_view name, span<const std::pair<string_view, const blob_result>> namedargs = {}, span<const blob_result> args = {});

private:
    shared_ptr<detail::annium_impl> impl_;
};

}
