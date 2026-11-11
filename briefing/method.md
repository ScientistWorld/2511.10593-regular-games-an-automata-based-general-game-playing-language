# Paper's Method

The paper introduces Regular Games (RG), a low-level language whose rules are a
nondeterministic finite automaton over game states, and High-level Regular
Games (HRG), a structured source language translated to RG. An RG description
is improved by a fixed-point loop of static transformations (dataflow-based
analysis, constant propagation, inlining of assignments and reachability
checks, compaction of skip edges, joining exclusive edges, pruning redundant
tags, ...) and annotated with inferred pragmas (`@disjoint`, `@unique`,
`@repeat`, `@simpleApply`, `@tagIndex`, ...). The `rg2cpp` compiler then
generates a C++ forward model that enumerates legal moves by walking the
automaton.

The reference method `method/compilers/hrg_rg_optimized/` runs the authors'
official pipeline unchanged:

1. `method/rg/interpreter_rust` CLI: HRG -> RG translation with
   `--enable-all-optimizations --enable-all-pragmas` (all transformations and
   pragma inference);
2. `method/rgcompiler/scripts/adjust_AST.py` normalisation -> `game.json`;
3. `method/rgcompiler` `rg2cpp` with the upstream default code-generation
   options (`--simple-path-compression 0 --disjoint 1 --arithmetic 1 --gccinline 0 ...`)
   -> `reasoner.hpp`, `reasoner.cpp`.

`method/toolchain/build.sh` builds both tools offline; `method/toolchain/compile_game.py`
runs steps 1-3 for any HRG/RBG/RG input with configurable flags.

The paper measures efficiency as flat Monte Carlo playouts per second (Table 1)
and reports mean automaton reductions of 47% nodes / 41% edges for HRG games
(Section 3.3).
