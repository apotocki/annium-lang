//  Annium programming language (c) by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "library.hpp"
#include "sonia/logger/logger.hpp"
#include "sonia/utility/scope_exit.hpp"
#include "numetron/basic_integer.hpp"
#include "numetron/basic_decimal.hpp"

#include "annium/entities/literals/numeric_promotion.hpp"

#include <cmath>
#include <limits>
#include <optional>
#include <sstream>
#include <utility>

namespace annium {

void annium_error(vm::context& ctx)
{
    std::string err = ctx.stack_back().as<std::string>();
    std::string loc = ctx.stack_back(1).as<std::string>();
    throw exception((std::ostringstream{} << loc << ": "sv << err).str());
}

void annium_assert(vm::context& ctx)
{
    if (!ctx.stack_back(1).as<bool>()) {
        std::string err = ctx.stack_back().as<std::string>();
        throw exception(err);
    }
    ctx.stack_pop(2);
}

void annium_get_frame_stack_height(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ ui64_blob_result(ctx.stack().size() - ctx.frame_stack_back()) });
}

namespace {

// blob_type_dispatch instantiates its callback for every blob_type (string, bool, tuple, error, ...),
// not just numeric ones -- annium_any_equal's runtime guard (::is_numeric(l->type)/::is_numeric(r->type))
// only ensures the *values actually reached* are numeric, it doesn't stop the compiler from instantiating
// the numeric-only logic below (static_cast<double>, numetron::decimal{...}, ...) for e.g. LDT=std::string_view
// too. Every branch that does real numeric work must be gated on this trait first, mirroring how
// blob_result_strict_equal_to (this header's invocation.hpp counterpart) gates its own branches on
// std::is_same_v<LDT, RDT> before touching either operand.
//
// is_integral_not_bool_v<T> alone isn't quite enough here: blob_type::c8 (a character, not a number --
// ::is_numeric(blob_type::c8) is false, same as string/tuple/error) dispatches to a plain `char`, and
// std::is_integral_v<char> is true, so it would otherwise slip through this gate as if it were numeric.
// That went unnoticed while every branch below happened to compile for `char` too (static_cast<double>,
// plain ==, ...), but std::cmp_equal (used for the native-vs-native integral comparison further down)
// static_asserts its arguments are "standard integer types" -- a category that, per the standard,
// specifically excludes plain `char` (its signedness is unspecified, unlike signed/unsigned char) --
// so instantiating this lambda for LDT/RDT = char, which ::is_numeric already guarantees never actually
// happens at runtime, stopped compiling. Excluded explicitly rather than narrowing is_integral_not_bool_v
// itself, since that trait is shared sonia-prime infrastructure used well beyond this one dispatch gate.
template <typename T>
constexpr bool is_numeric_dispatch_type_v =
    (is_integral_not_bool_v<T> && !std::is_same_v<T, char>) || std::is_floating_point_v<T> || std::is_same_v<T, numetron::float16> ||
    numetron::is_basic_integer_view_v<T> || numetron::is_basic_decimal_view_v<T>;

// `<` between a value that's always finite in this language (integral, bigint, or decimal -- none of
// those have a NaN/infinity state) and a native floating value that might not be (f16/f32/f64, now
// that bootstrap.ann's .nan/.inf properties can actually produce one). Returns the ordering result if
// the floating side is non-finite; nullopt if it's finite, meaning the caller should fall through to
// its own finite-case comparison (numetron::decimal construction) -- numetron::decimal's
// floating-point constructor throws for a non-finite input rather than reporting "doesn't fit" (see
// BUGFIXES.md), so non-finite values must be intercepted before ever reaching that constructor. NaN
// compares false against everything, including itself; +-infinity compares as wider than any finite
// value, in the direction its sign says.
inline std::optional<bool> less_involving_nonfinite(double floating_side, bool floating_is_lhs) noexcept
{
    if (std::isnan(floating_side)) return false;
    if (std::isinf(floating_side)) return floating_is_lhs ? (floating_side < 0) : (floating_side > 0);
    return std::nullopt;
}

}

void annium_any_equal(vm::context& ctx)
{
    smart_blob const& l = ctx.stack_back(1);
    smart_blob const& r = ctx.stack_back();
    bool result;
    // blob_result::operator== is intentionally an exact/strict comparison within one numeric "family"
    // (integral vs floating/decimal -- see sonia-prime's invocation.hpp); it's already correct AND cheap
    // for same-family pairs (any integer width vs any integer width or bigint; any float width vs any
    // float width or decimal), so only cross-family numeric pairs need help here.
    if (::is_numeric(l->type) && ::is_numeric(r->type) && ::is_integral(l->type) != ::is_integral(r->type)) {
        result = blob_type_dispatch(*l, [&r]<typename LDT>(LDT lv) -> bool {
            if constexpr (!is_numeric_dispatch_type_v<LDT>) {
                return false; // unreachable at runtime
            } else {
                return blob_type_dispatch(*r, [&lv]<typename RDT>(RDT rv) -> bool {
                    // Gate on both operand types actually being numeric dispatch types
                    // before doing anything arithmetic with them -- see
                    // is_numeric_dispatch_type_v's comment above; the runtime
                    // ::is_numeric checks in annium_any_equal only guarantee this for the
                    // *values* that reach here, not for every LDT/RDT the compiler must
                    // instantiate this lambda for.
                    if constexpr (!is_numeric_dispatch_type_v<RDT>) {
                        return false; // unreachable at runtime
                    } else {
                        // same-family pairs are already handled by
                        // blob_result::operator== above Exactly one of LDT/RDT is
                        // integral-ish (fixed-width int or bigint) and the other
                        // is floating-ish (f16/f32/f64/decimal) here (see the
                        // is_integral(l) != is_integral(r) guard above). Nothing
                        // in this dispatch ever throws for a comparison between
                        // two well-formed numeric values, regardless of magnitude
                        // -- only for genuinely exceptional circumstances (e.g.
                        // allocation failure) unrelated to the values themselves,
                        // same as everywhere else.
                        if constexpr (numetron::is_basic_decimal_view_v<LDT>) {
                            // numetron::decimal{ rv } picks whichever constructor
                            // overload matches rv's concrete type (native int,
                            // bigint, float, float16) via ordinary overload
                            // resolution -- no manual dispatch needed here. Unlike
                            // decimal_view, the OWNING numetron::decimal can always
                            // normalize (strip trailing decimal zeros) even from a
                            // bigint too wide for inline storage, since it can
                            // reallocate; its basic_integer_view constructor does
                            // exactly that now (basic_decimal.hpp, BUGFIXES.md), so
                            // plain operator== is correct and needs no extra logic
                            // here.
                            return numetron::decimal{rv} == lv;
                        } else if constexpr (numetron::is_basic_decimal_view_v<RDT>) {
                            return numetron::decimal{lv} == rv;
                        } else if constexpr (is_integral_not_bool_v<LDT> || numetron::is_basic_integer_view_v<LDT>) {
                            if constexpr (is_integral_not_bool_v<RDT> || numetron::is_basic_integer_view_v<RDT>) {
                                // Both are integral-ish, but different widths (e.g.
                                // i32 vs bigint) -- exact comparison is correct.
                                // Native-vs-native (e.g. i8 vs u32) needs
                                // std::cmp_equal rather than a plain ==: the usual
                                // arithmetic conversions would silently convert the
                                // signed side to unsigned before comparing (GCC's
                                // "-Wsign-compare" warning is flagging exactly this),
                                // which is wrong whenever the signed value is
                                // negative. Whenever a bigint (basic_integer_view) is
                                // on either side, plain == already compares exactly
                                // regardless of the native side's signedness --
                                // std::cmp_equal only accepts std::integral operands,
                                // so it doesn't apply there anyway.
                                if constexpr (is_integral_not_bool_v<LDT> && is_integral_not_bool_v<RDT>) {
                                    return std::cmp_equal(lv, rv);
                                } else {
                                    return lv == rv;
                                }
                            } else if constexpr (std::is_floating_point_v<RDT> || std::is_same_v<RDT, numetron::float16>) {
                                // numetron::operator==(basic_integer_view, floating)
                                // already checks finiteness and wholeness internally
                                // before decomposing rvdbl into an exact bigint -- no
                                // need to duplicate that check here.
                                if constexpr (numetron::is_basic_integer_view_v<LDT>) {
                                    return lv == static_cast<double>(rv);
                                } else {
                                    return numetron::integer_view{lv} == static_cast<double>(rv);
                                }
                            }
                        } else if constexpr (is_integral_not_bool_v<RDT> || numetron::is_basic_integer_view_v<RDT>) {
                            if constexpr (std::is_floating_point_v<LDT> || std::is_same_v<LDT, numetron::float16>) {
                                if constexpr (numetron::is_basic_integer_view_v<RDT>) {
                                    return rv == static_cast<double>(lv);
                                } else {
                                    return numetron::integer_view{rv} == static_cast<double>(lv);
                                }
                            }
                        } else if constexpr (std::is_floating_point_v<LDT> || std::is_same_v<LDT, numetron::float16>) {
                            if constexpr (std::is_floating_point_v<RDT> || std::is_same_v<RDT, numetron::float16>) {
                                return static_cast<double>(lv) == static_cast<double>(rv);
                            }
                        }
                    }
                });
            }
        });
    } else {
        result = l == r;
    }
    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ bool_blob_result(result) });
}

void annium_decimal_equal(vm::context& ctx)
{
    numetron::decimal r = ctx.stack_back().as<numetron::decimal>();
    numetron::decimal l = ctx.stack_back(1).as<numetron::decimal>();
    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ bool_blob_result(l == r) });
}

void annium_numeric_less(vm::context& ctx)
{
    smart_blob const& l = ctx.stack_back(1);
    smart_blob const& r = ctx.stack_back();
    // Unlike annium_any_equal, there's no blob_result::operator< to fall back on for
    // same-family pairs (sonia-prime's invocation.hpp only defines operator== for
    // blob_result), so every pairing -- same-family and cross-family alike -- is handled
    // by hand here via blob_type_dispatch. bootstrap.ann's `less(runtime @numeric, runtime
    // @numeric)` signature guarantees both operands are numeric by the time __less runs;
    // the is_numeric_dispatch_type_v gate below exists only because blob_type_dispatch
    // still instantiates this lambda for every blob_type at compile time (see the comment
    // above is_numeric_dispatch_type_v's definition).
    bool result = blob_type_dispatch(*l, [&r]<typename LDT>(LDT lv) -> bool {
        if constexpr (!is_numeric_dispatch_type_v<LDT>) {
            return false; // unreachable at runtime
        } else {
            return blob_type_dispatch(*r, [&lv]<typename RDT>(RDT rv) -> bool {
                if constexpr (!is_numeric_dispatch_type_v<RDT>) {
                    return false; // unreachable at runtime
                } else if constexpr (numetron::is_basic_decimal_view_v<LDT> && numetron::is_basic_decimal_view_v<RDT>) {
                    return lv < rv;
                } else if constexpr (numetron::is_basic_decimal_view_v<LDT> || numetron::is_basic_decimal_view_v<RDT>) {
                    // decimal vs. integral or floating: neither basic_integer_view nor the
                    // native floating types have an operator<=> against basic_decimal(_view),
                    // so route both operands through the owning numetron::decimal, which is
                    // exactly constructible from every numeric dispatch type (native int,
                    // bigint, float, float16, decimal_view -- basic_decimal.hpp's constructor
                    // set) and compares exactly against another numetron::decimal. decimal
                    // itself is always finite, so only the non-decimal side can be a
                    // non-finite floating value -- intercept that before it ever reaches
                    // numetron::decimal's throwing floating constructor.
                    if constexpr (numetron::is_basic_decimal_view_v<LDT> &&
                                  (std::is_floating_point_v<RDT> || std::is_same_v<RDT, numetron::float16>)) {
                        if (auto nf = less_involving_nonfinite(static_cast<double>(rv), false)) return *nf;
                    } else if constexpr (numetron::is_basic_decimal_view_v<RDT> &&
                                         (std::is_floating_point_v<LDT> || std::is_same_v<LDT, numetron::float16>)) {
                        if (auto nf = less_involving_nonfinite(static_cast<double>(lv), true)) return *nf;
                    }
                    return numetron::decimal{lv} < numetron::decimal{rv};
                } else if constexpr ((is_integral_not_bool_v<LDT> || numetron::is_basic_integer_view_v<LDT>) &&
                                      (is_integral_not_bool_v<RDT> || numetron::is_basic_integer_view_v<RDT>)) {
                    if constexpr (is_integral_not_bool_v<LDT> && is_integral_not_bool_v<RDT>) {
                        // Native-vs-native needs std::cmp_less rather than a plain <: the usual
                        // arithmetic conversions would silently convert the signed side to
                        // unsigned before comparing, same reasoning as annium_any_equal's
                        // std::cmp_equal.
                        return std::cmp_less(lv, rv);
                    } else {
                        // At least one side is a bigint (basic_integer_view); its operator<=>
                        // against basic_integer_view or std::integral, together with C++20's
                        // reversed-candidate synthesis, covers native-vs-bigint in either order
                        // as well as bigint-vs-bigint.
                        return lv < rv;
                    }
                } else if constexpr (is_integral_not_bool_v<LDT> || numetron::is_basic_integer_view_v<LDT> ||
                                      is_integral_not_bool_v<RDT> || numetron::is_basic_integer_view_v<RDT>) {
                    // Integral-ish (native or bigint) vs. native floating (f16/f32/f64): no
                    // operator<=> exists between basic_integer_view and a floating type (unlike
                    // operator==, which has one -- see basic_integer.hpp). The integral-ish side
                    // is always finite, so -- same reasoning as the decimal branch above --
                    // intercept a non-finite floating operand before falling back to the same
                    // numetron::decimal route used for the decimal branches above.
                    if constexpr (std::is_floating_point_v<RDT> || std::is_same_v<RDT, numetron::float16>) {
                        if (auto nf = less_involving_nonfinite(static_cast<double>(rv), false)) return *nf;
                    } else if constexpr (std::is_floating_point_v<LDT> || std::is_same_v<LDT, numetron::float16>) {
                        if (auto nf = less_involving_nonfinite(static_cast<double>(lv), true)) return *nf;
                    }
                    return numetron::decimal{lv} < numetron::decimal{rv};
                } else {
                    // Both native floating (f16/f32/f64 in any combination): casting to double is
                    // exact for all of them and preserves NaN/infinity ordering semantics.
                    return static_cast<double>(lv) < static_cast<double>(rv);
                }
            });
        }
    });
    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ bool_blob_result(result) });
}

// f16/f32/f64 .inf/.nan (bootstrap.ann): these values have no numeric-literal spelling and can't be
// built via constexpr arithmetic either (compile-time float division by zero is rejected, same as
// decimal division by zero -- see arithmetic.ann's `divide` section), so unlike .min/.max (plain
// literals) each needs an actual extern, called via `consteval` from bootstrap.ann to still fold at
// compile time. Zero-argument externs, same shape as annium_get_frame_stack_height above: no operands
// to pop, just push the result. -infinity isn't given its own extern/property -- unary `-` already
// works on f16/f32/f64 (numeric_literal_unary_minus_pattern.cpp's negate_constexpr_numeric), so
// `-f32.inf` covers it without duplicating a property that's just this one's negation.
void annium_f16_infinity(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ f16_blob_result(numetron::float16::infinity()) });
}

void annium_f32_infinity(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ f32_blob_result(std::numeric_limits<float>::infinity()) });
}

void annium_f64_infinity(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ f64_blob_result(std::numeric_limits<double>::infinity()) });
}

void annium_f16_nan(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ f16_blob_result(numetron::float16::quiet_NaN()) });
}

void annium_f32_nan(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ f32_blob_result(std::numeric_limits<float>::quiet_NaN()) });
}

void annium_f64_nan(vm::context& ctx)
{
    ctx.stack_push(smart_blob{ f64_blob_result(std::numeric_limits<double>::quiet_NaN()) });
}

void annium_tostring(vm::context & ctx)
{
    std::ostringstream res;
    print_to_stream(res, *ctx.stack_back(), false);
    ctx.stack_pop(1);
    smart_blob r{ string_blob_result(res.str()) };
    r.allocate();
    ctx.stack_push(std::move(r));
}

void annium_print_string(vm::context& ctx)
{
    size_t argcount = ctx.stack_back().as<size_t>();
    environment & e = ctx.get_environment();
    std::ostringstream res;
    for (size_t i = argcount; i > 0; --i) {
        print_to_stream(res, *ctx.stack_back(i), false);
    }
    e.write_cout(res.str());
    ctx.stack_pop(argcount + 1);
}

void annium_concat(vm::context& ctx)
{
    size_t argcount = ctx.stack_back().as<size_t>();
    std::ostringstream res;
    for (size_t i = argcount; i > 0; --i) {
        print_to_stream(res, *ctx.stack_back(i), false);
    }
    ctx.stack_pop(argcount + 1);
    smart_blob r{ string_blob_result(res.str()) };
    r.allocate();
    ctx.stack_push(std::move(r));
}

void annium_arrayify(vm::context& ctx)
{
    small_vector<blob_result, 4> elements;
    size_t argcount = ctx.stack_back().as<size_t>();
    elements.reserve(argcount);

    SCOPE_EXCEPTIONAL_EXIT([&elements]() {
        for (auto& e : elements) blob_result_unpin(&e);
    });

    bool mixed_types = false;
    
    for (size_t i = argcount; i > 0; --i) {
        auto& elem = ctx.stack_back(i);
        elements.emplace_back(*elem);
        blob_result_pin(&elements.back());
        if (elements.front().type != elem->type) { mixed_types = true; }
    }
    
    smart_blob r;
    if (!mixed_types && argcount) {
        r = blob_type_selector(elements.front(), [&elements](auto ident, blob_result const&)->blob_result {
            using type = typename decltype(ident)::type;
            if constexpr (std::is_integral_v<type> || std::is_floating_point_v<type> || std::is_same_v<type, bool> || std::is_same_v<type, numetron::float16>) {
                using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
                small_vector<fstype, 4> exact_elements;
                exact_elements.reserve(elements.size());
                for (auto& e : elements) {
                    exact_elements.push_back(as<fstype>(e));
                }
                return array_blob_result(span{ exact_elements.data(), exact_elements.size() }, true);
            } else {
                return array_blob_result(span{ elements.data(), elements.size() }, true);
            }
        });
    } else {
        r = array_blob_result(span{ elements.data(), elements.size() }, true);
    }
    
    elements.clear();
    ctx.stack_pop(argcount + 1);
    ctx.stack_push(std::move(r));
}

void annium_unfold(vm::context& ctx)
{
    auto& arg = ctx.stack_back();
    if (!is_array(arg.as<blob_result>())) {
        // considering not an array as the array with one element => do nothing and return
        return;
        //throw exception("expected array, got %1%"_fmt % arg.as<blob_result>());
    }
    smart_blob arr = std::move(arg);
    // Pop the array from stack
    ctx.stack_pop(1);

    blob_type_selector(arr.as<blob_result>(), [&ctx](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_integral_v<type> || std::is_floating_point_v<type> ||
            std::is_same_v<type, numetron::float16> || std::is_same_v<type, blob_result>)
        { 
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t array_size = array_size_of<fstype>(b);
            const fstype* data = data_of<fstype>(b);
            
            // Push each element to the stack
            for (size_t i = 0; i < array_size; ++i) {
                if constexpr (std::is_same_v<fstype, blob_result>) {
                    ctx.stack_push(smart_blob{ std::move(data[i]) });
                } else {
                    ctx.stack_push(smart_blob{ particular_blob_result(data[i]) });
                }
            }
            
            // Push the array size at the end
            //ctx.stack_push(smart_blob{ ui64_blob_result(array_size) });
        } else {
            THROW_INTERNAL_ERROR("unexpected array element type");
        }
    });
}

void annium_array_size(vm::context& ctx)
{
    auto arr = ctx.stack_back(1).as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }
    size_t sz = blob_type_selector(arr, [](auto ident, blob_result b) -> size_t {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t> || std::is_void_v<type>) {
            THROW_INTERNAL_ERROR("unexpected array element type");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            return array_size_of<fstype>(b);
        }
    });
    ctx.stack_back().replace(smart_blob{ ui64_blob_result(sz) });
}

void annium_string_empty(vm::context& ctx)
{
    bool is_empty = ctx.stack_back().as<string_view>().empty();
    ctx.stack_back().replace(smart_blob{ bool_blob_result(is_empty) });
}

void annium_string_size(vm::context& ctx)
{
    // to do: count characters, not bytes
    size_t size = ctx.stack_back().as<string_view>().size();
    ctx.stack_back().replace(smart_blob{ ui64_blob_result(size) });
}

void annium_array_at(vm::context& ctx)
{
    auto idx = ctx.stack_back().as<size_t>();
    auto arr = ctx.stack_back(1).as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }
    smart_blob result;
    blob_type_selector(arr, [idx, &result](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t> || std::is_void_v<type> || std::is_same_v<type, sonia::invocation::object>) {
            THROW_INTERNAL_ERROR("unexpected array element type");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t sz = array_size_of<fstype>(b);
            if (idx >= sz) {
                throw exception("index out of range");
            }
            fstype const& e = data_of<fstype>(b)[idx];
            blob_result res = particular_blob_result(e);
            result = res;
        }
    });

    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ result });
}

void annium_array_set_at(vm::context& ctx)
{
    auto value = ctx.stack_back().as<blob_result>();
    auto idx = ctx.stack_back(1).as<size_t>();
    auto arr = ctx.stack_back(2).as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }
    blob_type_selector(arr, [idx, &value](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t> || std::is_void_v<type>) {
            THROW_INTERNAL_ERROR("unexpected array element type");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t sz = array_size_of<fstype>(b);
            if (idx >= sz) {
                throw exception("index out of range");
            }
            fstype & e = mutable_data_of<fstype>(b)[idx];
            if constexpr (std::is_same_v<fstype, blob_result>) {
                blob_result_unpin(&e);
                e = value;
                blob_result_pin(&e);
            } else {
                e = as<fstype>(value);
            }
        }
    });
    ctx.stack_pop(2);
}

void annium_array_tail(vm::context& ctx)
{
    auto arr = ctx.stack_back().as<blob_result>();
    if (!is_array(arr)) {
        throw exception("expected array, got %1%"_fmt % arr);
    }

    blob_type_selector(arr, [&ctx](auto ident, blob_result b) {
        using type = typename decltype(ident)::type;
        if constexpr (std::is_same_v<type, std::nullptr_t>) { }
        else if constexpr (std::is_void_v<type>) { }
        else if constexpr (numetron::is_basic_integer_view_v<type>) { 
            THROW_NOT_IMPLEMENTED_ERROR("bigint tail"); }
        else if constexpr (numetron::is_basic_decimal_view_v<type>) {
            THROW_NOT_IMPLEMENTED_ERROR("decimal tail");
        } else if constexpr (std::is_same_v<type, sonia::basic_string_view<char>>) {
            THROW_NOT_IMPLEMENTED_ERROR("string tail");
        } else if constexpr (std::is_same_v<type, sonia::invocation::object>) {
            THROW_NOT_IMPLEMENTED_ERROR("object tail");
        } else {
            using fstype = std::conditional_t<std::is_same_v<type, bool>, uint8_t, type>;
            size_t argcount = array_size_of<fstype>(b);

            if (argcount == 2) {
                smart_blob result = particular_blob_result(data_of<fstype>(b)[1]);
                blob_result_pin(&*result);
                ctx.stack_back().replace(std::move(result));
                return;
            }
            small_vector<fstype, 4> elements;
            elements.reserve(argcount - 1);

            for (size_t i = 1; i < argcount; ++i) {
                elements.push_back(data_of<fstype>(b)[i]);
                if constexpr (std::is_same_v<fstype, blob_result>) {
                    blob_result_pin(&elements.back());
                }
            }

            smart_blob r{ array_blob_result(span{elements.data(), elements.size()}) };
            r.allocate();
            elements.clear();
            ctx.stack_back().replace(std::move(r));
        }
    });
}

void annium_logical_not(vm::context& ctx)
{
    auto val = *ctx.stack_back();
    while (val.type == blob_type::blob_reference) {
        val = *data_of<blob_result>(val);
    }
    val = blob_type_selector(val, [](auto ident, blob_result const& b) {
        using type = typename decltype(ident)::type;
        if (!is_array(b)) {
            if constexpr (std::is_same_v<type, bool>) { return bool_blob_result(!b.data.bp.i8value); }
            else if constexpr (std::is_integral_v<type> || numetron::is_basic_integer_view_v<type>) { return bool_blob_result(!as<type>(b)); }
            else {
                throw exception("Logical not operation cannot be applied to the provided argument: %1%"_fmt % b);
            }
        } else if (contains_string(b)) {
            auto sv = as<std::string_view>(b);
            return bool_blob_result(sv.empty());
        } else {
            throw exception("Logical not operation cannot be applied to the provided argument: %1%"_fmt % b);
        }
    });
    ctx.stack_pop(1);
    ctx.stack_push(val);
}

void annium_unary_minus(vm::context& ctx)
{
    auto val = *ctx.stack_back();
    while (val.type == blob_type::blob_reference) {
        val = *data_of<blob_result>(val);
    }
    val = blob_type_selector(val, [](auto ident, blob_result const& b) -> blob_result {
        using type = typename decltype(ident)::type;
        if (!is_array(b)) {
            if constexpr (std::is_same_v<type, bool>) { return b; }
            else if constexpr (std::is_unsigned_v<type>) {
                return particular_blob_result(static_cast<type>(-as<std::make_signed_t<type>>(b))); }
            else if constexpr (std::is_signed_v<type> || numetron::is_basic_integer_view_v<type> || std::is_floating_point_v<type> || std::is_same_v<type, numetron::float16>) {
                return particular_blob_result(-as<type>(b)); }
            else if constexpr (numetron::is_basic_decimal_view_v<type>) {
                return particular_blob_result(-as<type>(b)); }
        }
        throw exception("Unary minus operation cannot be applied to the provided argument: %1%"_fmt % b);
    });
    ctx.stack_pop(1);
    ctx.stack_push(val);
}

//void annium_concat_string(vm::context& ctx)
//{
//    auto l = ctx.stack_back(1).as<string_view>();
//    auto r = ctx.stack_back().as<string_view>();
//    auto res = make_blob_result(blob_type::string, nullptr, static_cast<uint32_t>(l.size() + r.size()));
//    blob_result_allocate(&res);
//    char * buff = mutable_data_of<char>(res);
//    std::memcpy(buff, l.data(), l.size());
//    std::memcpy(buff + l.size(), r.data(), r.size());
//    ctx.stack_pop();
//    ctx.stack_back().replace( smart_blob{ std::move(res) } );
//}

void annium_operator_plus_numeric(vm::context& ctx)
{
    smart_blob const& l = ctx.stack_back(1);
    smart_blob const& r = ctx.stack_back();
    builtin_eid result_type = strongest_numeric_type(numeric_builtin_eid_of(*l), numeric_builtin_eid_of(*r));
    smart_blob res = add_numeric(l, r, result_type);

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_operator_minus_integer(vm::context& ctx)
{
    auto l = ctx.stack_back(1).as<numetron::integer>();
    auto r = ctx.stack_back().as<numetron::integer_view>();
    auto sum = l - r;
    smart_blob res{ bigint_blob_result(sum) };
    res.allocate();

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_operator_minus_numeric(vm::context& ctx)
{
    smart_blob const& l = ctx.stack_back(1);
    smart_blob const& r = ctx.stack_back();
    builtin_eid result_type = strongest_numeric_type(numeric_builtin_eid_of(*l), numeric_builtin_eid_of(*r));
    smart_blob res = subtract_numeric(l, r, result_type);

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_operator_mul_numeric(vm::context& ctx)
{
    smart_blob const& l = ctx.stack_back(1);
    smart_blob const& r = ctx.stack_back();
    builtin_eid result_type = strongest_numeric_type(numeric_builtin_eid_of(*l), numeric_builtin_eid_of(*r));
    smart_blob res = multiply_numeric(l, r, result_type);

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_operator_div_numeric(vm::context& ctx)
{
    smart_blob const& l = ctx.stack_back(1);
    smart_blob const& r = ctx.stack_back();
    builtin_eid result_type = strongest_numeric_type(numeric_builtin_eid_of(*l), numeric_builtin_eid_of(*r));
    smart_blob res = divide_numeric(l, r, result_type);

    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

// Backs bootstrap.ann's `divide(a, b, scale, mode)`, the explicit runtime-safe alternative to the
// plain `/` operator (which stays undefined for decimal at runtime -- see numeric_promotion.hpp).
// `mode` arrives as a bare integer ordinal (bootstrap.ann passes `to_integer(mode)`, not the
// rounding_mode value itself -- there's no shared symbolic enum type across the runtime boundary,
// see decimal_rounding_mode's comment).
void annium_divide_decimal_rounded(vm::context& ctx)
{
    numetron::decimal_view a = ctx.stack_back(3).as<numetron::decimal_view>();
    numetron::decimal_view b = ctx.stack_back(2).as<numetron::decimal_view>();
    uint32_t scale = ctx.stack_back(1).as<uint32_t>();
    auto mode = static_cast<decimal_rounding_mode>(ctx.stack_back().as<int32_t>());

    auto result = divide_decimal_rounded(a, b, scale, mode);
    if (!result) {
        throw exception("divide: division by zero");
    }
    smart_blob res{ decimal_blob_result(*result) };
    res.allocate();

    ctx.stack_pop(3);
    ctx.stack_back().replace(std::move(res));
}

void annium_to_integer(vm::context& ctx)
{
    auto& arg = ctx.stack_back();
    if (arg->type == blob_type::bigint) return;
    smart_blob result;
    if (arg->type == blob_type::boolean || is_basic_integral(arg->type)) {
        result = smart_blob{ bigint_blob_result(arg.as<numetron::integer>()) };
    } else if (::is_floating_point(arg->type)) {
        numetron::decimal_view dv = arg.as<numetron::decimal_view>();
        result = smart_blob{ bigint_blob_result((numetron::integer)dv) };
    } else {
        THROW_INTERNAL_ERROR("cannot convert to integer: %1%"_fmt % arg);
    }
    arg.replace(std::move(result));
}

void annium_str2dec(vm::context& ctx)
{
    auto str = ctx.stack_back().as<string_view>();
    try {
        numetron::decimal d{ str };
        smart_blob res{ decimal_blob_result(d) };
        res.allocate();
        ctx.stack_back().replace(std::move(res));
    } catch (std::exception const& e) {
        ctx.stack_back().replace(error_blob_result(e.what())); // nil_blob_result()
        ctx.stack_back().allocate();
    }
}

void annium_int2dec(vm::context& ctx)
{
    auto ival = ctx.stack_back().as<numetron::integer_view>();
    numetron::decimal dval{ ival };
    smart_blob res{ decimal_blob_result(dval) };
    res.allocate();
    ctx.stack_back().replace(std::move(res));
}

void annium_int2flt(vm::context& ctx)
{
    auto ival = ctx.stack_back().as<numetron::integer_view>();
    ctx.stack_back().replace(smart_blob{ f32_blob_result((float)ival) });
}

// static_cast-like narrowing/widening: bits of the source value are truncated to fit T,
// exactly as numetron::basic_integer_view<T>::operator T() / basic_decimal_view<T>::operator T() do.
template <typename T>
static T annium_numeric_cast(smart_blob& arg)
{
    if (::is_floating_point(arg->type)) {
        return static_cast<T>(arg.as<numetron::decimal_view>());
    }
    return static_cast<T>(arg.as<numetron::integer_view>());
}

void annium_numeric_to_i8(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    int8_t val = annium_numeric_cast<int8_t>(arg);
    arg.replace(smart_blob{ i8_blob_result(val) });
}

void annium_numeric_to_ui8(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    uint8_t val = annium_numeric_cast<uint8_t>(arg);
    arg.replace(smart_blob{ ui8_blob_result(val) });
}

void annium_numeric_to_i16(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    int16_t val = annium_numeric_cast<int16_t>(arg);
    arg.replace(smart_blob{ i16_blob_result(val) });
}

void annium_numeric_to_ui16(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    uint16_t val = annium_numeric_cast<uint16_t>(arg);
    arg.replace(smart_blob{ ui16_blob_result(val) });
}

void annium_numeric_to_i32(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    int32_t val = annium_numeric_cast<int32_t>(arg);
    arg.replace(smart_blob{ i32_blob_result(val) });
}

void annium_numeric_to_ui32(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    uint32_t val = annium_numeric_cast<uint32_t>(arg);
    arg.replace(smart_blob{ ui32_blob_result(val) });
}

void annium_numeric_to_i64(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    int64_t val = annium_numeric_cast<int64_t>(arg);
    arg.replace(smart_blob{ i64_blob_result(val) });
}

void annium_numeric_to_ui64(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    uint64_t val = annium_numeric_cast<uint64_t>(arg);
    arg.replace(smart_blob{ ui64_blob_result(val) });
}

// Unlike the fixed-width integer family above, these don't need the is_floating_point(arg->type)
// dispatch: numetron::decimal_view already represents any numeric source (fixed-width int, bigint,
// f16/f32/f64, decimal) exactly, via smart_blob::as<numetron::decimal_view>()'s own dispatch.
void annium_numeric_to_f16(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    numetron::float16 val = numetron::float16_cast(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f16_blob_result(val) });
}

void annium_numeric_to_f32(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    float val = static_cast<float>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f32_blob_result(val) });
}

void annium_numeric_to_f64(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    double val = static_cast<double>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f64_blob_result(val) });
}

void annium_numeric_to_decimal(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    numetron::decimal_view dv = arg.as<numetron::decimal_view>();
    smart_blob result{ decimal_blob_result(dv) };
    result.allocate();
    arg.replace(std::move(result));
}

// sqrt/log/floor/ceil/pow/round: f64-only for now (see FUTURE_WORK.md for decimal). Every operand is
// read through numetron::decimal_view the same way annium_numeric_to_f64 is, so any numeric source
// (fixed-width int, bigint, f16/f32/f64, decimal) is accepted -- these back bootstrap.ann's
// `sqrt`/`log`/`floor`/`ceil`/`pow`/`round`, declared `runtime @numeric`, always returning f64.
void annium_numeric_sqrt(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    double val = static_cast<double>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f64_blob_result(std::sqrt(val)) });
}

void annium_numeric_log(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    double val = static_cast<double>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f64_blob_result(std::log(val)) });
}

void annium_numeric_floor(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    double val = static_cast<double>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f64_blob_result(std::floor(val)) });
}

void annium_numeric_ceil(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    double val = static_cast<double>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f64_blob_result(std::ceil(val)) });
}

void annium_numeric_pow(vm::context& ctx)
{
    double base = static_cast<double>(ctx.stack_back(1).as<numetron::decimal_view>());
    double exponent = static_cast<double>(ctx.stack_back().as<numetron::decimal_view>());
    ctx.stack_pop();
    ctx.stack_back().replace(smart_blob{ f64_blob_result(std::pow(base, exponent)) });
}

void annium_numeric_round(vm::context& ctx)
{
    smart_blob& arg = ctx.stack_back();
    double val = static_cast<double>(arg.as<numetron::decimal_view>());
    arg.replace(smart_blob{ f64_blob_result(std::round(val)) });
}

// Rounds to at most `digits` digits after the decimal point (negative digits round to the left of
// the point), same "scale, round-to-nearest, unscale" shape as the standard textbook approach --
// unlike bootstrap.ann's decimal `divide(...)`, this is f64 arithmetic so there's no exactness
// concern to guard (a plain std::round of the scaled value is sufficient).
void annium_numeric_round_digits(vm::context& ctx)
{
    double val = static_cast<double>(ctx.stack_back(1).as<numetron::decimal_view>());
    double digits = static_cast<double>(ctx.stack_back().as<numetron::decimal_view>());
    ctx.stack_pop();
    double scale = std::pow(10.0, digits);
    ctx.stack_back().replace(smart_blob{ f64_blob_result(std::round(val * scale) / scale) });
}

class annium_callable : public invocation::callable
{
    smart_blob fn_blob_;
    size_t arg_count_;
    weak_ptr<environment> environment_;
    std::variant<invocation::invocable*, weak_ptr<invocation::invocable> > scope_;

public:
    annium_callable(smart_blob fn_blob, size_t arg_count, weak_ptr<environment> env, invocation::invocable* scope)
        : fn_blob_{ std::move(fn_blob) }
        , arg_count_{ arg_count }
        , environment_{ std::move(env) }
        , scope_{ nullptr }
    {
        if (scope) {
            auto shared = scope->self_as_invocable_shared();
            if (shared) {
                scope_ = std::move(shared);
            } else {
                scope_ = scope;
            }
        }
    }

    smart_blob invoke(span<const blob_result> args) noexcept override
    {
        shared_ptr<environment> env = environment_.lock();
        if (!env) {
            return smart_blob{ error_blob_result("annium_callable error: environment is no longer available") };
        }
        try {
            shared_ptr<invocation::invocable> scope_holder;
            invocation::invocable *ps = std::visit(
                [&scope_holder]<typename T>(T arg) -> invocation::invocable * {
                    if constexpr (std::is_same_v<T, invocation::invocable *>) {
                        return arg;
                    } else {
                        scope_holder = arg.lock();
                        if (!scope_holder) {
                            throw exception{ "annium_callable error: invocable environment is no longer available" };
                        }
                        return scope_holder.get();
                    }
                },
            scope_);

          // if (args.size() < arg_count_) {
          //     return smart_blob{ error_blob_result(("annium_callable error:
          //     expected %1% arguments, got %2%"_fmt % arg_count_ %
          //     args.size()).str()) };
          // }

            vm::context ctx{*env, ps};
            size_t init_stack_sz = ctx.stack_size();
            ctx.stack_push(fn_blob_);
            annium_unfold(ctx);
            size_t cindex = ctx.stack_back().as<size_t>();
            size_t address = ctx.const_at(cindex).as<size_t>();
            ctx.stack_pop();
            size_t argidx = 0;
            for (; argidx < (std::min)(args.size(), arg_count_); ++argidx) {
                ctx.stack_push(smart_blob{args[argidx]});
            }
            for (; argidx < arg_count_; ++argidx) {
                ctx.stack_push(smart_blob{});
            }
            env->bvm().run(ctx, address);

            size_t final_stack_sz = ctx.stack_size();
            smart_blob result;
            if (final_stack_sz > init_stack_sz) {
                BOOST_ASSERT(final_stack_sz == init_stack_sz + 1);
                return std::move(ctx.stack_back());
            }
            return smart_blob{nil_blob_result()};
        } catch (...) {
            GLOBAL_LOG_ERROR()
                << "Exception in annium_callable: %1%"_fmt %
                        boost::current_exception_diagnostic_information();
            return smart_blob{error_blob_result(
                boost::current_exception_diagnostic_information())};
        }
    }
};

void annium_create_callable(vm::context& ctx)
{
    using namespace sonia::invocation;

    size_t arg_count = ctx.stack_back().as<size_t>();
    smart_blob fn = std::move(ctx.stack_back(1));

    shared_ptr<callable> cl = std::make_shared<annium_callable>(std::move(fn), arg_count, ctx.get_environment().shared_from_this(), ctx.scope());
    smart_blob callable_object{ object_blob_result<wrapper_object<shared_ptr<callable>>>(std::move(cl)) };
    ctx.stack_pop();
    ctx.stack_back().replace(std::move(callable_object));
}

void annium_create_extern_object(vm::context& ctx)
{
    string_view name = ctx.stack_back().as<string_view>();
    if (name.starts_with("::"sv)) {
        name = name.substr(2);
        name = name.substr(2);
    }

    smart_blob resobj = ctx.env().invoke("create"sv, { string_blob_result(ctx.camel2kebab(name)) });
    if (resobj->type == blob_type::error) {
        throw exception(resobj.as<std::string>());
    }
    //using wobj_t = invocation::wrapper_object<shared_ptr<invocation::invocable>>;
    //GLOBAL_LOG_DEBUG() << "Creating extern object: %1%, address: %2%"_fmt % name % resobj.as<wobj_t>().value.get();
    ctx.stack_back().replace(std::move(resobj));
}

// (obj, propName, value)->obj
void annium_set_object_property(vm::context& ctx)
{
    using namespace sonia::invocation;
    shared_ptr<invocable> obj = ctx.stack_back(2).as<wrapper_object<shared_ptr<invocable>>>().value;
    if (!obj) {
        throw exception("annium_set_object_property error: object is null");
    }
    string_view prop_name = ctx.stack_back(1).as<string_view>();
    obj->set_property(ctx.camel2kebab(prop_name), *ctx.stack_back());
    ctx.stack_pop(2);
}

// (obj, propName) -> value
void annium_get_object_property(vm::context& ctx)
{
    using namespace sonia::invocation;
    shared_ptr<invocable> obj = ctx.stack_back(1).as<wrapper_object<shared_ptr<invocable>>>().value;
    if (!obj) {
        throw exception("annium_get_object_property error: object is null");
    }
    string_view prop_name = ctx.stack_back().as<string_view>();
    smart_blob res = obj->get_property(ctx.camel2kebab(prop_name));
    if (res.is_error()) {
        throw exception(res.as<std::string>());
    }
    // res may be a view into memory the host object only guarantees for the duration of the
    // get_property() call (e.g. something it built from its own transient state) -- see the
    // annium_invoke_object comment below for the concrete, confirmed instance of this pattern.
    res.allocate();
    ctx.stack_pop();
    ctx.stack_back().replace(std::move(res));
}

void annium_invoke(vm::context& ctx)
{
    size_t argcount = ctx.stack_back().as<size_t>();
    small_vector<blob_result, 16> args;
    args.reserve(argcount);
    for (size_t i = argcount; i > 0; --i) {
        args.emplace_back(*ctx.stack_back(i));
    }

    string_view name = ctx.stack_back(argcount + 1).as<string_view>();
    smart_blob resobj = ctx.env().invoke(name, span{ args });
    if (resobj.is_error()) {
        // auto tstr = (std::ostringstream{} << resobj).str();
        // GLOBAL_LOG_ERROR() << "Error invoking '%1%': %2%"_fmt % name % tstr;
        throw exception(resobj.as<std::string>());
    }
    // resobj may be a non-owning view into `args` (e.g. a string_view-returning host method
    // handing back a slice of one of its own string_view arguments) -- args is a local variable
    // and is about to go out of scope when this function returns, so resobj must own its bytes
    // before that happens. See the annium_invoke_object comment below for the confirmed case
    // this guards against (BUGFIXES.md).
    resobj.allocate();
    ctx.stack_pop(argcount + 1);
    ctx.stack_back().replace(std::move(resobj));
}

void annium_invoke_void(vm::context& ctx)
{
    annium_invoke(ctx);
    ctx.stack_pop();
}

void annium_invoke_object(vm::context& ctx)
{
    // we have on stack here: [object, method, arg1, arg2, ..., argN, N]
    using namespace sonia::invocation;
    size_t argcount = ctx.stack_back().as<size_t>();
    string_view method = ctx.stack_back(argcount + 1).as<string_view>();
    shared_ptr<invocable> pinvocable = ctx.stack_back(argcount + 2).as<wrapper_object<shared_ptr<invocable>>>().value;

    small_vector<blob_result, 16> args;
    args.reserve(argcount);
    for (size_t i = argcount; i > 0; --i) {
        args.emplace_back(*ctx.stack_back(i));
    }

    smart_blob res = pinvocable->invoke(method, args);
    if (res.is_error()) {
        throw exception(res.as<std::string>());
    }
    // res can be a non-owning view into `args` (e.g. std_object::substring returns a string_view
    // into its own `target` argument, and string_blob_result(string_view) wraps it as a reference
    // rather than copying) -- args is a local variable, about to be destroyed when this function
    // returns, taking that memory with it. Confirmed the hard way: consteval's own scratch
    // execution (ast/consteval_evaluator.cpp) reads a pushed ecall result well after this
    // function has returned, and under valgrind that read landed on already-invalidated stack
    // memory (garbage instead of "ell" from `substring("hello", 1, 3)`). Ordinary (non-consteval)
    // execution has the exact same dangling reference the instant this function returns -- it
    // just usually reads it again quickly enough, before anything else reuses this stack region,
    // that the bug stays latent. See BUGFIXES.md.
    res.allocate();
    ctx.stack_pop(argcount + 2);
    ctx.stack_back().replace(std::move(res));
}

void annium_invoke_callable(vm::context& ctx)
{
    // we have on stack here: [callable_object, arg1, arg2, ..., argN, N]
    using namespace sonia::invocation;
    size_t argcount = ctx.stack_back().as<size_t>();
    //GLOBAL_LOG_INFO() << "annium_invoke_callable: argcount = %1%"_fmt % argcount;
    shared_ptr<callable> pcallable = std::move(ctx.stack_back(argcount + 1).as<wrapper_object<shared_ptr<callable>>>().value);

    small_vector<blob_result, 16> args;
    args.reserve(argcount);
    for (size_t i = argcount; i > 0; --i) {
        args.emplace_back(*ctx.stack_back(i));
    }

    smart_blob res = pcallable->invoke(args);
    if (res.is_error()) {
        throw exception(res.as<std::string>());
    }
    // same dangling-view hazard as annium_invoke_object just above -- see BUGFIXES.md.
    res.allocate();
    ctx.stack_pop(argcount + 1);
    ctx.stack_back().replace(std::move(res));
}

}
