# Constraints

Fixed by the evaluator (`eval/`), not by the method:

- The rule files of each slice (train: `data/games/hrg` and `data/games/rbg`; held-out: hidden).
- The ground truth: game-tree counts and random-playout statistics of the
  frozen direct translation of each rule file; the verification depth,
  playout counts, seeds and the six-standard-error tolerance.
- The comparison models: the frozen RBG->RG, direct HRG->RG and direct RBG->RG
  forward models and the direct translations' automaton sizes.
- The driver, the compiler and its flags (`g++ -std=c++23 -O3 -flto
  -march=x86-64-v2 -DNDEBUG`), the instruction counter (valgrind), and the
  reference RG compiler used to check submitted automata.

A method must:

- accept HRG (`rules.hrg`) and RBG (`rules.rbg`) rule files and produce
  `reasoner.hpp`, `reasoner.cpp` and `game.json` for every rule file within
  15 s per game (one-time `prepare.sh` may take up to 1 hour);
- generate the forward model from the rule file it is given (no game-specific
  hand-written engines or cached outputs);
- keep the generated C++ free of I/O, environment access, process or thread
  control, early termination, inline assembly, symbol interposition outside
  `namespace reasoner`, and compiler-setting overrides (pragmas/attributes).

Any failure on any game gives the method the worst value of every scored
metric in all three experiments. Function-level inlining hints
(`always_inline`, `flatten`, `noinline`, `hot`, `cold`) are allowed.
