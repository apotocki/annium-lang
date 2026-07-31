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
