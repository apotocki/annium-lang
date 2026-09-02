# Annium Language Syntax Reference

A working reference to `.ann` source syntax, built incrementally from reading `src/annium/annium.l` / `annium.y` and real registered signatures — **not a complete spec**. Extend this file as new syntax is investigated; don't let it silently go stale (if you find a section wrong while working on the grammar, fix it in the same change). Referenced from `CLAUDE.md`.

## Builtin type keywords

From `ANNIUM_BUILTIN_QNAMES_SEQ` / `ANNIUM_BUILTIN_TYPES_SEQ` (`src/annium/environment.hpp`):

| Keyword | Meaning |
|---|---|
| `i8`, `u8`, `i16`, `u16`, `i32`, `u32`, `i64`, `u64` | fixed-width integers (note: **`u8`/`u16`/...**, not `ui8`/`ui16`/... — that spelling is only used VM-internally for `blob_type`, see `sonia::invocation::blob_type` in `modules/sonia-prime`) |
| `f16`, `f32`, `f64` | fixed-width floats |
| `integer` | arbitrary-precision integer (bigint) |
| `decimal` | arbitrary-precision decimal |
| `bool` | boolean |
| `string` | string |
| `object` | opaque host/extern object handle |
| `callable` | first-class callable value |
| `any` | untyped/dynamic |
| `typename` | the type of types — see "typename-mode parameters" below |
| `tuple`, `array`, `function`, `functor`, `union` | compound/structural type constructors |

## Function/parameter declaration

A parameter is written as (informally, several grammar productions in `annium.y:780-861` cover the combinations):

```
[name | $internalName] [: [runtime|constexpr] constraint] [default]
```

- **Modifier** (`runtime` / `constexpr`, before the type): `runtime T` requires an actual runtime value; `constexpr T` requires a compile-time constant; omitted = `constexpr_or_runtime_type` (either is accepted, and the matcher decides per call site).
- **Unnamed positional**: just a constraint, no name — `runtime`, `runtime integer`, `constexpr string`, or a bare type name like `integer` (defaults to `constexpr_or_runtime_type`). Example: `"__to_integer(runtime)->integer"`.
- **Named, caller-visible**: `name: constraint` — e.g. `"decimal(text: string)->decimal|()"`.
- **Named, internal-only** (not part of the call-site signature, just a label used in the result-type expression or for readability): `$name: constraint`, where `$name` lexes as `CONTEXT_IDENTIFIER` (`$` followed by **letters**, `annium.l:104`). Example: `"__array_set_at($arr: runtime, $index: runtime integer, $value)"`.
- **Named, caller-visible name + separate internal name**: `name $internalName: constraint` — see "External name + internal name" below.
- **Placeholder**: `_` matches any single positional argument without binding a name.
- **Variadic**: trailing `...` — `"__print(runtime ..., runtime integer)"`.
- **Optional**: `name?: constraint` with a default-value spec.

### `$0` / `$1` / `$$` are NOT parameter names

`$0`, `$1`, ... lex as `RESERVED_IDENTIFIER` (`$` followed by a plain number, `annium.l:105`) — a **completely different token** from `$name` (`CONTEXT_IDENTIFIER`). `RESERVED_IDENTIFIER` is only valid in **expression position**, inside a function body or a result-type expression, meaning "the value of the Nth positional argument" — e.g. `assert_equal`'s body uses `$0 == $1`; `"__array_tail(~runtime tuple(_, $t...))->tuple($t...)"`'s result type references a *pattern-bound* `$t`, not this reserved form. You cannot declare a parameter named `$0` — the grammar's `internal-identifier` production only accepts `CONTEXT_IDENTIFIER`. Use a letters-based `$name` instead.

### Call-site argument matching: named vs. positional

Whether a parameter's declared name starts with `$` decides how its argument must be written at the call site — this is independent of the `runtime`/`constexpr` modifier and of whether the parameter has a default:

- **Declared with an external (non-`$`) name** (`name: constraint` or `name $internalName: constraint`) — the argument **must** be passed by that name: `f(name: value)`. Named arguments may appear in **any order**.
- **Declared as `$name` only** (no external name) — the parameter is **positional only**; nothing is written at the call site for it. Positional arguments are matched strictly in **declaration order**, regardless of where any named arguments are interleaved among them at the call site.

This is why `bootstrap.ann`'s `starts_with(self: ~ runtime string, $prefix: runtime string) -> bool` must be called as `starts_with(self: "hello", "he")`, not `starts_with("hello", "he")`: `self` has an external name (no `$`), so it's mandatory and named; `$prefix` has none, so it's positional and unnamed at the call site. The same applies to `substring(self: ~ runtime string, $start: runtime u32, $length: runtime i32 = i32.max)`: `substring(self: "hello", 1, 3)`.

### External name + internal name: `name $internalName: constraint`

A parameter can declare *both* a caller-facing external name and a separate implementation-facing internal name, e.g. `f(count $n: integer)`: the call site writes `count:`, the body refers to the value as `$n` (like Swift's external/internal parameter name pairs). This is `named_parameter_name` (`ast_terms.hpp`) with both `external_name` and `internal_name` set. Plain `name: constraint` is the same struct with `internal_name` left empty (the body then refers to the parameter by its external name directly); plain `$name: constraint` is the other variant, `unnamed_parameter_name` (no external name — positional, per above).

## Member calls (`a.b(args)`) desugar to ordinary functional lookup

`a.b(args)` is sugar, resolved in two steps, tried in order:

1. `b(self: <type of a>, args)` — a plain call to a functional named `b` whose `self` parameter matches `a`'s type.
2. If no such pattern matches: `invoke(self: <type of a>, method: __identifier, args)` — the generic dynamic-dispatch fallback (used for e.g. host/extern objects with no compile-time-known member set).

So member-call syntax needs no special declaration on the callee's side: any function with a `self`-named first parameter (e.g. `starts_with(self: ~ runtime string, ...)`) is callable both as `starts_with(self: x, ...)` and as `x.starts_with(...)` — they're the same call, just written differently.

## `@concept` constraints

`@name` attached to a parameter pattern requires a registered compile-time predicate `fn name(t: typename) -> bool`; the parameter matches only if calling that predicate with the candidate's type returns `true`. Multiple `@a @b` on one pattern is AND (all must pass). See `IMPLEMENTATION_NOTES.md` for how this is actually evaluated (`pattern_matcher::do_match_concepts`) and known predicates (`is_struct`, `tuple_of`, `numeric`).

A concept can be attached to a fully unnamed positional parameter, combined with an explicit `runtime`/`constexpr` modifier: `runtime @numeric` (`"__to_i8(runtime @numeric)->i8"`) — like any other unnamed positional parameter, it isn't referenced by name at the call site; use `$0`/`$1`/... in the body or result-type expression if you need to refer back to it. This form is a dedicated `parameter-decl` grammar alternative (`constraint-expression-specified-mod[mod] concept-expression-list[cpts]`, `annium.y`, next to the plain `constraint-expression-specified` abbreviated case) — don't confuse it with the *named* forms (`name: runtime @concept` / `$name: runtime @concept`, `annium.y:820,834`), which exist separately for when you actually need to bind and reference the parameter (e.g. from the result-type expression, à la `array_tail`'s `$t`).

A concept can also be attached to a parameter with *no* modifier and *no* name at all — just `@numeric`, or `@a @b`, standing alone as the whole parameter — e.g. `bootstrap.ann`'s `less(@numeric, @numeric)` / `less_eq`/`greater`/`greater_eq`. This is its own `parameter-decl` grammar alternative (`concept-expression-list[cpts] parameter-default-value-opt[default]`, `annium.y`, right next to the `UNDERSCORE concept-expression-list-opt[cpts] ...` case it mirrors) — like the other unnamed forms, it's positional (`$0`/`$1`/...). The modifier defaults to `constexpr_or_runtime_type`, same as the named placeholder case below, which is *why* a single such declaration (not a `runtime`/`constexpr` overload pair) is enough to both stay constexpr-foldable when called with constexpr arguments and still work at runtime otherwise — see `less_eq` for exactly that: unlike `less` itself (which has separate `runtime @numeric` / `constexpr @numeric` overloads so its two bodies can differ — a real runtime `__less` call vs. a `consteval __less` fold), `less_eq`/`greater`/`greater_eq` only need one bare-`@numeric` declaration each because their single body works unmodified in both contexts.

A named placeholder can default to the same modifier too — `self: @is_struct` (as in `bootstrap.ann`) — but that's a *different* `parameter-decl` alternative (`internal-identifier[intid] concept-expression-list-opt[cpts] ...`), the one that has a name (`self`) and an optional trailing concept list, not the fully bare one above.

## `typename`-mode parameters

A parameter can require its argument to itself be a type (a `typename`-typed value, e.g. `SomeStruct` passed directly rather than an instance of it), via the `TILDA TYPENAME` / `TYPENAME` pattern-mod grammar (`annium.y:969-972`). `is_struct`'s and `numeric`'s own single parameter both work this way. In C++ pattern implementations, this shows up as: the argument's `get_result_type(...)` equals `env.get(builtin_eid::typename_)`, and the type being tested is the argument's *value* (`arg_er.value()`), not its type.

## Casts

`value as Type` — binary expression, `binary_operator_type::CAST` (`annium.y:1141-1142`). Example (`tests/test-suite/casts.ann`): `v0 as i32`, chainable: `v0 as i32 as i64`.

## `extern fn`

```
extern fn name(runtime T1, runtime T2, ...) [-> R];
```

Declares a natively-implemented function with no body. All parameters must be `runtime` (rejected otherwise — see `IMPLEMENTATION_NOTES.md`). The runtime lookup name is the qname joined with `::` (e.g. `namespace foo { extern fn bar(...); }` → looked up as `"foo::bar"`).

## `let` with explicit type

`let name: Type = expr;` — e.g. `let fltvar: f16 = 100;`, `let s8: i8 = -5;`. Useful for constructing a value of a specific fixed-width type from an untyped (bigint/decimal-default) literal in tests.

## Double-underscore builtins are ordinary callables

Names like `__to_integer`, `__print`, `__get_frame_stack_height`, `__to_i8` are not special syntax — they're just registered functionals with a conventional `__`-prefixed name (signalling "compiler/library-internal"), callable exactly like any other function from `.ann` source: `__to_i8(x)`, `assert_equal(__get_frame_stack_height(), 1)`.

## `consteval` / `consteval(condition)`

`consteval expr` forces `expr` through compile-time evaluation (CTFE) even when it would otherwise be a runtime call — see `CONSTEVAL_CTFE_PLAN.md` / `IMPLEMENTATION_NOTES.md`'s `consteval` section. `expr` is a `syntax-expression` (`annium.y:1104`), so it binds like a unary prefix operator (same precedence as unary `-`).

`consteval(condition) expr` — guarded form, analogous to C++'s `explicit(bool)`/`noexcept(bool)` (`annium.y`, next to the plain rule). `condition` must itself resolve to a compile-time `bool`; `true` behaves exactly like plain `consteval expr` above, `false` skips forcing and `expr` gets its ordinary constexpr-or-runtime interpretation. Lets one definition serve both a `runtime` and a `constexpr` parameter: `inline fn sqrt(@numeric) -> f64 => consteval(is_const($0)) __sqrt(runtime_cast($0));`, instead of `bootstrap.ann`'s current separate `runtime @numeric` / `constexpr @numeric` overload pair for `sqrt`/`log`/`floor`/`ceil`/`pow`/`round`.
