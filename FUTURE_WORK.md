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

## Regenerate `annium.tab.cpp`/`.tab.hpp` so `*` (multiplication) actually parses

**Status:** source-level fix done (grammar + compiler side), regeneration deliberately deferred — user's own call to make, on purpose (see `IMPLEMENTATION_NOTES.md`'s "Generic numeric arithmetic" section for the full story).

**Problem:** `a * b` doesn't parse yet. `annium.y` and `ast_terms.hpp` have been fixed to give `ASTERISK` a real binary grammar rule (`binary_operator_type::MUL`, wired through to the new `numeric_literal_mul_pattern`/`__mul_numeric` exactly like `+`/`-`), but the checked-in generated `annium.tab.cpp`/`.tab.hpp` predate this change and don't have it. Regenerating from the fixed `.y`/`.l` (bison/flex) is what actually makes `*` usable.

**Why deferred:** explicitly a build/codegen step the user asked to hold off on for now, not a design gap — verify the regen doesn't introduce shift/reduce conflicts around `ASTERISK`'s dual unary(deref)/binary(multiply) role before trusting it (the precedence declarations that should prevent this already existed and are unused by any other rule yet, see the note in `IMPLEMENTATION_NOTES.md`).

## Extend generic numeric arithmetic (`__plus`/`__minus`/`__multiply`) to `__div`

**Status:** not started, deliberately deferred (`__plus`, `__minus`, and `__multiply` are done — see `IMPLEMENTATION_NOTES.md`'s "Generic numeric arithmetic" section).

**Problem:** `__div` doesn't exist as a callable operator at all, and unlike `*` its grammar rule (`SLASH`) has the identical `handle_call_op`/dead-`expr`-nonterminal problem `*` had — needs the same grammar fix (plus its own regeneration) before the compiler-side pattern would even be reachable.

**Proposed direction:** the reusable pieces are already in `entities/literals/numeric_promotion.hpp` (`strongest_numeric_type`, `widen_for_literal_fit`, the shared value-conversion helpers, `add_numeric`/`subtract_numeric`/`multiply_numeric` as the template to follow for `divide_numeric`). Needs: (1) the same grammar fix `*` got (`DIV` in `ANNIUM_BINARY_OPERATOR_ENUM`, a `syntax-expression[larg] SLASH syntax-expression[rarg]` rule, a `base_expression_visitor` dispatch case, a `builtin_qnid::divide`) plus bison/flex regeneration, (2) a `numeric_literal_div_pattern` mirroring `numeric_literal_minus_pattern`'s shape (division, like subtraction, must preserve operand order), (3) a type-erased runtime extern mirroring the others (`numeric_builtin_eid_of` + a per-result-type switch — check what binary operators `numetron::decimal`/`numetron::integer` actually expose for division before assuming it's a direct `operator/`), (4) the corresponding `builtin_eid` slot and registration in `annium_environment.cpp`. Division additionally needs a decision this codebase hasn't made yet: what `strongest_numeric_type` should mean for two *integral* operands (does `i32/i32` truncate like C, or promote to `decimal`?) — plausibly a different join rule than addition/subtraction/multiplication.

**Why deferred:** explicitly out of scope for the `__plus`/`__minus`/`__multiply` task this grew out of; the user asked for the mechanism to be *designed* reusably but only `__plus`/`__minus`/`__multiply` to be *implemented* so far.

`can_convert_constexpr_value_safely`'s decimal-source fit check for `integer`/`f16`/`f32`/`f64` targets — previously tracked here as deferred — has since been fixed at the root (both the `integer` case and the float cases, via an actual round-trip precision check for the latter). See `BUGFIXES.md`'s "`can_convert_constexpr_value_safely`'s `decimal_view` branch let a fractional `decimal` implicitly narrow to `integer` without loss-of-precision check" entry (and its follow-up paragraph).

## Reconcile `logical_not_pattern`'s strict `boolean`-only gate with `annium_logical_not`'s broader (currently unreachable) behavior

**Status:** not started, deliberately deferred.

**Problem:** `logical_not_pattern::try_match` (`functional/general/logical_not_pattern.cpp:24`) requests its argument with `expected_result_t{ env.get(builtin_eid::boolean), ... }` — i.e. it only ever accepts something that's already `boolean` (or safely implicit-casts to it; `is_always_safe_runtime_conversion` in `numeric_promotion.hpp` has no case that lists `boolean` as a valid *target* for any numeric source, only the reverse, so in practice nothing but an actual `bool` gets through). But the runtime function it calls into for the non-constexpr case, `annium_logical_not` (`library/annium_library.cpp`), is written to handle far more: any integral type (`!x` meaning "is zero"), any string (`!s` meaning "is empty"), and throws for anything else (arrays, etc.) — a general "falsy" check, not a strict boolean negation. Since `annium_logical_not` is only ever invoked from `logical_not_pattern::apply()` (confirmed by grep — no other call site), and that path is gated to booleans only, all of that extra generality in `annium_logical_not` is currently dead/unreachable code. The pattern's own `print()` label (`"logical_not(:@is_numeric)->boolean"`, predates this session) reflects that same broader intent that was apparently never finished, and doesn't match what `try_match` actually enforces today.

**Proposed direction (not decided):** either (a) loosen `logical_not_pattern::try_match` to accept the same "truthy" types `annium_logical_not` already implements (making `!5`/`logical_not("")` etc. real, working language features, matching what the runtime function already does), or (b) leave the gate as strictly `boolean`-only and prune/simplify `annium_logical_not` to match (removing the now-pointless integral/string branches), and fix the `print()` label to say `boolean` instead of `@is_numeric`/`@numeric`. Not decided which is intended — needs a real design call, not a drive-by fix.

**Why deferred:** discovered while reviewing the `print()` notation of the new `numeric_literal_plus/minus/mul_pattern`s (unrelated feature); explicitly out of scope for that work, user asked to just record it here for now.
