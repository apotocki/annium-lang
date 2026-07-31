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

## Extend generic numeric arithmetic (`__plus`) to `__minus`/`__mul`/`__div`

**Status:** not started, deliberately deferred (only `__plus` was done — see `IMPLEMENTATION_NOTES.md`'s "Generic numeric arithmetic" section).

**Problem:** `__minus` is still the old single `(runtime integer, runtime integer)~>integer` typed overload (no `decimal` overload even exists, let alone cross-type support); `__mul`/`__div` don't exist as callable operators at all.

**Proposed direction:** the reusable pieces are already in `entities/literals/numeric_promotion.hpp` (`strongest_numeric_type`, `widen_for_literal_fit`, the shared value-conversion helpers) and `add_numeric`'s shape in the same header is a template for `subtract_numeric`/`multiply_numeric`/`divide_numeric`. Each new operator needs: (1) a `numeric_literal_<op>_pattern` mirroring `numeric_literal_plus_pattern`'s try_match/apply shape, (2) a type-erased runtime extern mirroring `annium_operator_plus_numeric` (`numeric_builtin_eid_of` + a per-result-type switch), (3) the corresponding `builtin_eid` slot and registration in `annium_environment.cpp`. Division additionally needs a decision this codebase hasn't made yet: what `strongest_numeric_type` should mean for two *integral* operands (does `i32/i32` truncate like C, or promote to `decimal`?) — plausibly a different join rule than addition/subtraction/multiplication.

**Why deferred:** explicitly out of scope for the `__plus` task this grew out of; the user asked for the mechanism to be *designed* reusably but only `__plus` to be *implemented* this round.

`can_convert_constexpr_value_safely`'s decimal-source fit check for `integer`/`f16`/`f32`/`f64` targets — previously tracked here as deferred — has since been fixed at the root (both the `integer` case and the float cases, via an actual round-trip precision check for the latter). See `BUGFIXES.md`'s "`can_convert_constexpr_value_safely`'s `decimal_view` branch let a fractional `decimal` implicitly narrow to `integer` without loss-of-precision check" entry (and its follow-up paragraph).
