# Future Work

Deliberately deferred design/refactor ideas — things worth doing but not started, with enough context to pick back up later without re-deriving the reasoning. Not a bug tracker; for concrete open bugs use whatever the project's normal issue tracking is. Referenced from `CLAUDE.md`.

## Replace the ad hoc `match_penalty` fields with an explicit specificity-rank enum

**Status:** not started, deliberately deferred.

**Problem:** overload resolution priority (`functional/parameter_matcher.cpp`'s `constraint_matcher`, `functional/match_penalty.*`) is currently a hand-grown vector of named counters (`casts`, `placeholders`, `variadics`, `cast_capable_matches`) compared lexicographically. Each constraint-matching branch (`operator()(syntax_expression const*)`, `operator()(syntax_pattern const*)`, and any future one) independently decides which of these fields to touch and how — there's no single place that defines "how specific was this parameter match." This already caused one real bug: the pattern branch silently dropped a `has_cast` signal the expression branch had always tracked, because there was nothing forcing the two branches to stay in sync (fixed — see `IMPLEMENTATION_NOTES.md`'s `constraint_matcher`/`cast_capable_matches` section — but the fix closes *that* instance, not the structural cause). Field names like `cast_allowances` (since renamed to `cast_capable_matches`) are also not self-documenting — they encode a specific tie-break outcome some test wanted, not a concept with an obvious meaning from its name alone.

**Proposed direction:** introduce a single, closed, documented enum describing how a parameter was satisfied, e.g.:

```cpp
enum class match_specificity : uint8_t {
    exact_value,      // fn foo(5) -- literal/constexpr value matched exactly
    exact_pattern,     // structural/@concept match, no cast needed
    exact_type,        // fn foo(integer) -- type matched exactly, no cast needed
    generic_pattern,   // fn foo(~$T) -- placeholder/generic pattern
    cast_needed,       // implicit_cast or constexpr<->runtime materialization required
};
```

Every constraint-matching branch would compute this classification through one shared function/table instead of hand-picking `match_penalty` field values, and `match_penalty` would become a histogram (count per `match_specificity` level) compared lexicographically from most- to least-specific. This makes cross-branch drift structurally impossible (one source of truth, not N independently-maintained branches), and turns `match_priority.ann` into more of an executable specification (organized by rank-pair) rather than a growing pile of individually-motivated regression cases.

**Why deferred:** this is a real refactor of core matching internals (`parameter_matcher.cpp`, `match_penalty.hpp/.cpp`, likely `pattern_matcher.cpp` if nested structural sub-matches should also report through the same scale), not a localized fix — it needs a full test-suite pass to confirm no existing overload-resolution priority silently shifts. Not worth starting opportunistically; do it as its own deliberate task.

**Where to pick this up:** `IMPLEMENTATION_NOTES.md`'s "Disambiguating the constexpr vs. runtime overload for a literal argument" section has the concrete bug/fix this idea grew out of, including exact file:line references into the current (pre-refactor) mechanism.

`numetron::basic_decimal_view::operator<=>`'s digit-shifting branch (equal-case bug, plus the related remainder-discarding issue that could have affected `less`/`greater` too) — previously tracked here as deferred — has since been fixed at the root. See `BUGFIXES.md`'s "`basic_decimal_view::operator<=>` couldn't report equality for two differently-scaled representations of the same value" entry.

`annium.tab.cpp`/`.tab.hpp`/the flex lexer regeneration for `*` and `/` — previously tracked here as deliberately deferred — has since been done and confirmed (both `binary_operator_type::MUL` and `binary_operator_type::DIV` are present in the checked-in `annium.tab.cpp`, and `arithmetic.ann`'s multiplication/division tests build and pass). See `IMPLEMENTATION_NOTES.md`'s "Generic numeric arithmetic" section for the full story, including the two-level `SLASH` lexer gap (both its flex macro definition and its rule were dead) that made `/`'s fix bigger than `*`'s.

## Implement the remaining `rounding_mode` values for `divide(a, b, scale, mode)`

**Status:** the mechanism and `rounding_mode.half_even` are done (see `IMPLEMENTATION_NOTES.md`'s "Generic numeric arithmetic" section — `bootstrap.ann`'s `divide(...)`, `decimal_rounding_mode`/`divide_decimal_rounded` in `numeric_promotion.hpp`/`.cpp`). `half_up`, `half_down`, `up`, `down`, `ceiling`, and `floor` are declared in both `bootstrap.ann`'s `rounding_mode` enum and the mirrored C++ `decimal_rounding_mode` enum, but `divide_decimal_rounded` throws `THROW_NOT_IMPLEMENTED_ERROR` for all of them — only `half_even`'s branch is actually implemented.

**Problem:** runtime `decimal` division (the plain `/` operator) is a separate, still-open question — see the next entry — but for the *explicit* `divide(...)` function specifically, the outstanding work is narrower: it's a design that's already settled (both the function shape and what `half_even` should do), just not finished across all seven modes.

**Proposed direction:** `divide_decimal_rounded`'s existing structure (`numeric_promotion.cpp`) already computes the exact truncated quotient `q` and remainder `r` before applying `half_even`'s tie-break — every other mode is a different rule applied to that same `(q, r, den)` triple (plus the operand signs), not a different algorithm: `up`/`down` need no remainder check at all (`down` keeps `q` as-is always — it's already round-toward-zero; `up` increments `q` whenever `r != 0`, i.e. away from zero); `half_up`/`half_down` are `half_even`'s tie-break with a fixed direction instead of parity (`half_up`: `2r >= den` always rounds away from zero on a tie; `half_down`: `2r > den` only, ties round toward zero); `ceiling`/`floor` need the *sign* of the true (unrounded) quotient, not just its magnitude, since they're direction-of-the-number-line rules, not magnitude rules (`ceiling` rounds toward `+infinity`, `floor` toward `-infinity` — these are the two modes where a nonzero remainder's rounding direction depends on the result's sign, unlike all the others).

**Why deferred:** scoped incrementally on purpose — the user asked to implement the mechanism and `half_even` first and add the rest afterward, mirroring how `__plus`/`__minus`/`__multiply`/`__divide` were each done and tested one at a time before moving to the next.

## Decide what the plain `/` operator should mean for `decimal` at runtime

**Status:** still undefined — `numeric_literal_div_pattern` unconditionally rejects any runtime-involving join that lands on `decimal` (`"runtime division is not defined for decimal"`). This is a *separate* question from the one above: `divide(a, b, scale, mode)` is a deliberately explicit, opt-in function precisely so the plain `/` operator doesn't have to answer "what if the quotient doesn't terminate" — nothing about `divide(...)` existing forces `/` to gain a runtime decimal behavior too.

**Problem:** division for an arbitrary-precision decimal type doesn't have an obvious general answer the way addition/subtraction/multiplication do — most quotients (e.g. `1 / 3`) aren't exactly representable in any finite decimal significand/exponent pair. Constexpr `/` sidesteps this by rejecting non-terminating results as a compile error (`try_divide_decimal_constexpr`); there's no runtime equivalent of a compile error to fall back on for the plain operator.

**Proposed direction:** not decided whether `/` should ever get a runtime decimal behavior at all, given `divide(...)` already covers the explicit case. If it does, `divide_decimal_rounded` is directly reusable (it's not tied to the `divide(...)` call site) — but that still needs a decision about *which* implicit scale/rounding `/` alone would use, which is exactly the ambiguity `divide(...)`'s explicit parameters were introduced to avoid.

**Why deferred:** out of scope for the `divide(...)` task this grew out of — the user's design explicitly kept `/` untouched (see `IMPLEMENTATION_NOTES.md`).

`can_convert_constexpr_value_safely`'s decimal-source fit check for `integer`/`f16`/`f32`/`f64` targets — previously tracked here as deferred — has since been fixed at the root (both the `integer` case and the float cases, via an actual round-trip precision check for the latter). See `BUGFIXES.md`'s "`can_convert_constexpr_value_safely`'s `decimal_view` branch let a fractional `decimal` implicitly narrow to `integer` without loss-of-precision check" entry (and its follow-up paragraph).

## Reconcile `logical_not_pattern`'s strict `boolean`-only gate with `annium_logical_not`'s broader (currently unreachable) behavior

**Status:** not started, deliberately deferred.

**Problem:** `logical_not_pattern::try_match` (`functional/general/logical_not_pattern.cpp:24`) requests its argument with `expected_result_t{ env.get(builtin_eid::boolean), ... }` — i.e. it only ever accepts something that's already `boolean` (or safely implicit-casts to it; `is_always_safe_runtime_conversion` in `numeric_promotion.hpp` has no case that lists `boolean` as a valid *target* for any numeric source, only the reverse, so in practice nothing but an actual `bool` gets through). But the runtime function it calls into for the non-constexpr case, `annium_logical_not` (`library/annium_library.cpp`), is written to handle far more: any integral type (`!x` meaning "is zero"), any string (`!s` meaning "is empty"), and throws for anything else (arrays, etc.) — a general "falsy" check, not a strict boolean negation. Since `annium_logical_not` is only ever invoked from `logical_not_pattern::apply()` (confirmed by grep — no other call site), and that path is gated to booleans only, all of that extra generality in `annium_logical_not` is currently dead/unreachable code. The pattern's own `print()` label (`"logical_not(:@is_numeric)->boolean"`, predates this session) reflects that same broader intent that was apparently never finished, and doesn't match what `try_match` actually enforces today.

**Proposed direction (not decided):** either (a) loosen `logical_not_pattern::try_match` to accept the same "truthy" types `annium_logical_not` already implements (making `!5`/`logical_not("")` etc. real, working language features, matching what the runtime function already does), or (b) leave the gate as strictly `boolean`-only and prune/simplify `annium_logical_not` to match (removing the now-pointless integral/string branches), and fix the `print()` label to say `boolean` instead of `@is_numeric`/`@numeric`. Not decided which is intended — needs a real design call, not a drive-by fix.

**Why deferred:** discovered while reviewing the `print()` notation of the new `numeric_literal_plus/minus/mul_pattern`s (unrelated feature); explicitly out of scope for that work, user asked to just record it here for now.

## Remove `vm.hpp`'s dead `#else` branch now that `vm2.hpp` is the live implementation

**Status:** not started, low priority, purely cosmetic.

**Problem:** `sonia/utility/lang/vm.hpp` is now `#if 1` / `#include "vm2.hpp"` / `#else` ~1300 lines of the old hand-written `traverse()` implementation / `#endif`. The `#else` branch is permanently unreachable (the condition is a literal `1`) and still carries the unfixed `append_jt`/`append_jtx`/`append_jf`/`append_jfx` dead-code landmine (see `BUGFIXES.md`) and the pre-fix `op::ecall` decode bug — neither matters for compilation since nothing preprocesses that branch, but the file is confusing to read cold.

**Proposed direction:** either delete the `#else` branch's content entirely (leaving `vm.hpp` as a pure one-line forwarding shim to `vm2.hpp`), or delete `vm.hpp` outright and repoint its few includers directly at `vm2.hpp`. Whichever's chosen, `vm2.hpp`'s own `IMPLEMENTATION_NOTES.md` section (VM instruction dispatch) should be updated to stop mentioning the forwarding shim once it's gone.

**Why deferred:** not blocking anything — both MSVC and GCC builds pass as of this session. Purely a follow-up cleanup once the `vm2.hpp` codegen path has had more real-world mileage.

## Mark trivial pattern-mismatch errors so they can be collapsed/hidden in diagnostics

**Status:** not started, deliberately deferred.

**Problem:** `error_printer_visitor::print()` (see `IMPLEMENTATION_NOTES.md`'s "Error-tree printing prints leaf-first, longest chain first" section) now prints the deepest, longest failure chain first and caps how many alternative chains it shows in full. That fixes ordering/volume, but every `type_mismatch_error` (`errors/type_mismatch_error.*`) generated while `functional::find`/`parameter_matcher.cpp`/`pattern_matcher.cpp` reject a candidate overload still prints as a full-weight error, indistinguishable from a "real" error. For a call with several plausible-looking overloads, the leading chains can still be pure signature-shape noise ("expected `integer`, got `string`" for a candidate that was never a serious contender) rather than the actually-informative failure.

**Proposed direction:** add a way for an `error` node to self-report as "trivial"/collapsible — e.g. a `virtual bool is_trivial() const noexcept { return false; }` on `error` (or `general_error`), overridden by `type_mismatch_error` and similar pattern-rejection errors — and have `error_printer_visitor::print()` (or a caller-selected mode) render trivial leaves as a single collapsed line (e.g. the candidate's signature plus "rejected: type mismatch") instead of expanding their full chain. Needs a decision on default behavior (collapsed by default with a verbose escape hatch, vs. shown by default) and how the "escape hatch" is exposed — a `print()` parameter/mode enum on `error_printer_visitor` is simplest; a compiler-wide CLI flag is a separate, bigger decision.

**Why deferred:** the user asked to build the ordering/chain-collection mechanism first and explicitly flagged the triviality-tagging piece as a separate follow-up needing its own design pass (which errors count as "trivial," what the collapsed one-line form should say, whether it's opt-in or opt-out) rather than building it opportunistically alongside the ordering change.

## Consider a smarter tie-break than raw chain length for ordering alternative error chains

**Status:** not started, deliberately deferred.

**Problem:** `error_printer_visitor::print()`'s longest-chain-first heuristic (see `IMPLEMENTATION_NOTES.md`) uses chain depth alone as a proxy for "most likely the real error." Depth is a reasonable default but not always right — a deep chain can come from a generic combinator pattern failing for unrelated reasons several layers down, while a shallow chain is the actual intended overload. The matcher already computes something more direct (`functional::find`'s per-candidate `match_descriptor->penalty`/parameter-match specificity, see `functional/parameter_matcher.cpp`), but that information isn't threaded through to error objects, so `collect_chains()`/the sort in `print()` can't use it as a tie-break (or primary key) today.

**Proposed direction:** not decided — would need `pattern_match_error`/`type_mismatch_error` (or a shared base) to carry enough of the match-penalty signal to compare candidates by "how close was this match" in addition to/instead of raw depth, and a decision on how that interacts with the existing `alt_error` structure (which currently only stores the rejected candidates' error trees, not their penalties).

**Why deferred:** the user agreed depth-first ordering was a reasonable first cut and explicitly flagged this as a possible refinement to reconsider later, not a blocker for the initial leaf-first printing change.

## `not_empty_condition_t` codegen is not implemented in the VM compiler

**Status:** not started; the only genuinely missing piece of conditional codegen.

**Problem:** `compiler_visitor::operator()(semantic::not_empty_condition_t const&)` (`vm/compiler_visitor.hpp:492`) is live and immediately `THROW_NOT_IMPLEMENTED_ERROR` — its sketched implementation sits in an `#if 0` block right below (lines 495-515). Note the throw's message text is a copy-paste leftover reading `"compiler_visitor return_statement"`, which will misdirect anyone who hits it; fix that string as part of any work here. So `.ann` source needing a runtime nil/emptiness branch cannot compile.

**Proposed direction:** model it on the *working* `conditional_t` implementation (see the correction below) — that one is label-based via `asm_builder_t::op_t::je`/`jne`/`jmp` and `fnbuilder_.make_label()`, not the raw `append_jtx`/`append_jfx`/`swap_code_blocks` shape the `#if 0` block sketches. Treat that `#if 0` code as an abandoned earlier design, not as a starting point.

## `consteval <expr>` (CTFE) — deferred pieces from the v1 implementation

**Status:** v1 implemented per `CONSTEVAL_CTFE_PLAN.md` (see `IMPLEMENTATION_NOTES.md`'s `consteval` section for the actual shape). The three items below were deliberately left out of v1 — none of them are exercised by the motivating example or the plan's own test list, and each needs a real design decision, not a drive-by fix.

**No step/instruction budget.** A `consteval` expression whose call chain doesn't terminate (accidental infinite recursion, etc.) will hang the compiler — `bvm().run()` runs to completion or throws, there's no bound. The user explicitly deferred this for v1 (plan section 8's second open question) rather than design a budget mechanism (fixed constant vs. compiler flag) without a concrete need driving the choice.

**Operand-level temporaries and outer-frame references are rejected, not supported.** `evaluate_consteval` cleanly errors out if the operand's `syntax_expression_result::temporaries` is non-empty, or if its own instructions (not an inlined callee's — see the implementation notes) touch `push_local_variable`/`set_local_variable`/`push_by_offset{frame_bottom}`. The former would need the operand evaluated through a real scope (temporaries only get a variable-table entry via `fn_compiler_context::append_result`, which ties them to *some* function's frame — plausibly a fresh scope on the scratch entity itself, but that needs its own `fn_compiler_context`, and it's not obvious that context's namespace/binding chain would resolve names identically to the enclosing one without deliberately copying `ctx`'s bindings across). The latter is arguably not fixable at all — a runtime-only local variable's value genuinely doesn't exist at compile time — but could in principle be given a much more specific diagnostic (name the variable) instead of the current generic message.

**CT-representability doesn't recurse into tuple/array/struct element types.** The plan's table (section 3.4) says these should be representable iff every element is; the implementation only checks the two builtin opaque types (`object`/`callable`, plus the post-run `blob_type::object` check that also catches `callable`) at the top level. A tuple/array/struct whose element happens to be `object`/`callable` would currently either fail confusingly inside `make_generic_entity` or (if the blob-level shape doesn't obviously scream "object") potentially produce a bogus constexpr entity instead of a clean error. Needs iterating `entity_signature::fields()` for the `builtin_qnid::tuple`/`data` cases, plus a real answer for struct entities (which don't appear to share a generic "this is a struct" signature-name marker the way tuple/array do — would need `dynamic_cast<struct_entity const*>` or equivalent).

### Correction: `conditional_t` (plain `if`) *is* implemented — an earlier version of this entry was wrong

This entry previously claimed that both `conditional_t` and `not_empty_condition_t` throw, that conditionals therefore could not compile at all, and that fixing it would require reinstating the commented-out `jt`/`jtp`/`jtn`/`jf`/`jfp`/`jfn` opcodes. All three claims were incorrect, verified by reading the file:

- The throwing `conditional_t` override in `compiler_visitor_generic` (`vm/compiler_visitor.hpp:451`) is **entirely inside an `#if 0` block** (lines 450-489) — dead code.
- The live handler is `compiler_visitor_base::operator()(semantic::conditional_t const&)` (`vm/compiler_visitor.hpp:241`), a real implementation. Both `compiler_visitor` and `inline_compiler_visitor` inherit it through `using compiler_visitor_base::operator();`, so *both* codegen paths have it.
- It emits `asm_builder_t::op_t::je`/`jne`/`jmp` against labels from `fnbuilder_.make_label()` — the `asm_builder` layer, resolving to the live `jmp`/`je`/`jne` opcode family. It never touches `append_jtx`/`append_jfx`, so the commented-out `jt`/`jf` opcodes are irrelevant to it and do **not** need reviving.
- `switch_t` (`vm/compiler_visitor.hpp:289`) is implemented the same way.

The mistake came from grepping for `THROW_NOT_IMPLEMENTED_ERROR` near `conditional_t` without checking whether the enclosing block was `#if 0`'d — exactly the trap `IMPLEMENTATION_NOTES.md` warns about under "Stale / dead code caveat".

## Exact/decimal-native `sqrt`/`log`/`floor`/`ceil`/`pow`/`round`

**Status:** not started, deliberately deferred. `bootstrap.ann`'s `sqrt`/`log`/`floor`/`ceil`/`pow`/`round(value[, digits])` (backed by `annium_numeric_sqrt`/`_log`/`_floor`/`_ceil`/`_pow`/`_round`/`_round_digits` in `library/annium_library.cpp`) all take `runtime @numeric` — any numeric source, `decimal` included — but convert straight to `double` via `numetron::decimal_view` and compute through `<cmath>`, always returning `f64`. So calling any of them with a `decimal` operand today silently goes through `f64` and loses `decimal`'s exactness. (`abs`/`min`/`max` don't have this problem — they're pure `.ann`, implemented via the already-generic `<` and unary `-`, and preserve the operand's own type exactly, `decimal` included.)

**Problem:** `floor`/`ceil`/`round` are the ones a `decimal` caller would most plausibly want exact (unlike `log`/`sqrt`/`pow`, which are inherently transcendental/irrational in general and have no exact `decimal` answer for most inputs) — a `decimal`-native `floor`/`ceil` is just significand/exponent manipulation, no `double` round-trip needed, and would avoid the precision loss a large-significand `decimal` would suffer going through `f64`.

**Proposed direction:** not designed — would need deciding whether `decimal` gets its own overload set (mirroring `divide(a, b, scale, mode)`'s explicit, `decimal`-only shape) or whether the existing `@numeric`-generic functions should special-case `decimal` internally and return `decimal` instead of `f64` when the input is `decimal` (which would make the return type context-dependent, unlike every other numeric function in `bootstrap.ann` today).

**Why deferred:** the user explicitly scoped the initial `sqrt`/`log`/`floor`/`ceil`/`pow`/`round` work to `f16`/`f32`/`f64` only, to unblock `formatBytes(...)`, and said `decimal` support would be a separate follow-up.

## Wire up (or replace) `numetron::limb_arithmetic::udiv`'s multi-limb divisor case

**Status:** not started, deliberately deferred -- flagged by the user, who recalled disabling a working multi-limb implementation at some point but not why.

**Problem:** the public entry point `udiv(std::span<const LimbT> u, std::span<const LimbT> v, std::span<LimbT> q, std::span<LimbT> r)` (`limb_arithmetic/udiv.hpp`, bottom of the file) -- the one every higher-level division (`basic_integer`'s `operator/`/`operator%`, and transitively anything that divides by a bigint) actually calls -- only implements a single-limb divisor (`ve - vb == 1`, routed to the fast `udivby1` path); any wider divisor hits `throw std::runtime_error("not implemented")`. This was worked around, not fixed, while adding `f16`/`f32`/`f64` `.pi`/`.e` to `bootstrap.ann` (see `BUGFIXES.md`'s "Adding `f16`/`f32`/`f64` `.pi`/`.e` surfaced a chain of five independent bugs" entry, point 3) by restructuring `decimal_view::operator T()` to never divide by anything wider than one limb in the first place.

**The work isn't starting from zero.** The same file already contains two different apparent attempts at a real multi-limb algorithm, neither wired to the `udiv` entry point above:

- `udiv_bc`/`udiv_svoboda`/`udiv_dv` (lines ~72-285) -- a base-case long division plus a Svoboda's-algorithm variant (precomputed-reciprocal division) and a divide-and-conquer wrapper, feeding a *different* `udiv(LimbT uh, span ul, LimbT dh, span dl, qit, alloc)` overload (line ~288, allocator-taking, output-iterator-based quotient) that nothing else in the library calls.
- `udiv2` (lines ~342-486) -- a separate, more self-contained normalize/divide/denormalize implementation with its own two overloads, also uncalled from anywhere else.

Both look substantially complete (normalization, quotient digit estimation with the correction loop, remainder recovery) rather than stubs, which fits the user's recollection of having had a working version -- but neither has been audited for correctness here, and it's not established which of the two (if either, as-is) is actually right, or why the entry point was pointed at a bare throw instead of either one.

**Proposed direction:** when picked back up, treat this as "review and validate an existing implementation," not "write one from scratch": pick one of `udiv_svoboda`/`udiv2` (or reconcile them), get it wired to the real `udiv` entry point, and test hard against exactly the class of inputs that exposed the `add()`/`decimal_view` bugs in the `BUGFIXES.md` entry above -- wide, close-in-magnitude operands, exact-equality cases, and both odd and even limb-count divisors -- before trusting it. Once it's correct, `decimal_view::operator T()`'s `floor_div_pow5` chunking (the workaround this entry exists because of) can be simplified back to a single direct `A / pow5k` / `A % pow5k`.

**Why deferred:** genuinely unresolved *why* it was disabled -- could be a real correctness bug in one or both attempts, an incomplete integration, or something unrelated to correctness entirely. Re-enabling it blind, without knowing which, is exactly the kind of risk this project's bug history (three separate previously-latent `numetron` arithmetic bugs surfaced by one feature addition, per the entry above) argues against.

## `to_union_implicit_cast_pattern` never produces a compile-time-constant union value

**Status:** not started, deliberately deferred.

**Problem:** `to_union_implicit_cast_pattern::try_match` (`entities/union/to_union_implicit_cast_pattern.cpp:115`) unconditionally does `pmd->signature.result.emplace(exp.type, false)` — the `is_const` flag is hardcoded `false`, so casting *any* value to a union type always yields a runtime result, even when the source value is itself a compile-time constant and the union's matched case is known at compile time too (e.g. the `enum_union` all-const-fields case, which still forces non-const via the same line). A commented-out alternative sits right above it (`//if (can_be_only_runtime(exp.modifier) || !er.is_const_result) { ... } else { pmd->signature.result.emplace(er.value(), true); }`), suggesting a conditional const path was once intended but never finished/enabled.

**Consequence:** unions can never appear inside any *other* compile-time constant either — a fixed array, tuple, or struct with a union-typed element is transitively forced non-const the moment that element goes through this cast, per how `fixed_array_make_pattern`/`tuple_make_pattern` track `all_const` (any non-const matched element flips the whole composite to non-const). `fixed_array_get_pattern.cpp`'s `materialize_const_blob` helper (added to fold a compile-time-constant fixed array — including nested arrays/tuples — into a single runtime blob for `array_at` indexing with a dynamic index) relies on exactly this invariant to justify never having to handle a union case: since a union value is never const, no fully-const array/tuple/struct can contain one, so `materialize_const_blob` can safely `THROW_NOT_IMPLEMENTED_ERROR` on anything it doesn't recognize instead of silently falling back. If this entry is ever fixed, `materialize_const_blob` will need a matching case (fold to the `[value, which]` shape `to_union_implicit_cast_pattern::apply`/`union_apply_pattern::apply` build via `arrayify`, treating a const-union's constant `which`/value pair as another composite to recurse into) — see `fixed_array_get_pattern.cpp`'s comment above `materialize_const_blob` for the exact cross-reference.

**Proposed direction:** not designed — would need enabling the commented-out conditional branch (or something equivalent), deciding what a compile-time-constant union value's entity representation should look like (mirroring how a const tuple is an `empty_entity` whose type carries the field values — see `IMPLEMENTATION_NOTES.md` if such a section exists, or `tuple_make_pattern.cpp`/`tuple_get_pattern.cpp` for the pattern to mirror), and then testing across every pattern that inspects `is_const_result` for a union-typed value (`union_apply_pattern`, any future `materialize_const_blob`-style folding).

**Why deferred:** found while implementing `fixed_array_get_pattern`'s Case 3 (dynamic index into a constant fixed array); fixing the union limitation itself is unrelated in scope to that task. Recorded here per the user's request to fix it later rather than opportunistically.

## `[x]` with a single constexpr value throws instead of building a one-element array

**Status:** not started, deliberately deferred.

**Problem:** a bracketed expression with exactly one element parses as its own AST node, `bracket_expression`, distinct from the general `array_expression` (`annium.y:1071-1078` — `expression-list.size() == 1` takes the `bracket_expression` branch, anything else takes `array_expression`). `base_expression_visitor::operator()(bracket_expression const&)` (`ast/base_expression_visitor.cpp:258-280`) gives `[x]` two totally different meanings depending on what `x` is: if `x` is a *type*, `[x]` means "an array type of element type `x`" (no size — `make_array_type_entity(er.value())`); if `x` is a *runtime value*, `[x]` builds a genuine one-element array (`make_array_type_entity(er.type(), 1)`). But if `x` is a **constexpr value** (not a type), it hits `THROW_NOT_IMPLEMENTED_ERROR("base_expression_visitor annium_array_type_t")` — there's no case for "one constant value, wrapped as a one-element constant array."

**Consequence:** `let a = [42];` (a single compile-time-constant element, no `runtime_cast`) cannot compile today. The trailing-comma form `[42,]` (`annium.y`, the `OPEN_SQUARE_BRACKET expression-list COMMA CLOSE_SQUARE_BRACKET` alternative) sidesteps this entirely — it always builds `array_expression` regardless of element count, which routes through `make_array(...)`/`fixed_array_make_pattern` and handles the all-const single-element case correctly — so `[42,]` is the working spelling in the meantime. Found while writing a `fixed_array_get_pattern` Case 3 test for a one-element constant array (`array_operations.ann`'s `ca1`); worked around there with `[42,]` rather than fixed here.

**Proposed direction:** not designed — the type-vs-value duality of plain `[x]` already exists and works for the type and runtime-value cases; a constexpr value just needs the equivalent of the runtime branch (`make_array_type_entity(er.type(), 1)` then materialize as const), likely by routing through `make_array(...)` the same way `array_expression` already does (`base_expression_visitor.cpp:548-558`) rather than hand-rolling it here.

**Why deferred:** discovered as a side effect of testing unrelated `fixed_array_get_pattern` work; not itself in scope for that task.

