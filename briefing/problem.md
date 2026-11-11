# Problem Definition

General game playing needs **forward models**: programs that, given only a
formal description of a finite turn-based game, expose its current player,
legal moves, move application, terminal detection and final scores, without
any hand-written game-specific code. Search and learning agents spend most of
their time inside the forward model, so its efficiency matters.

In this gym the rules are written in the High-level Regular Games (HRG)
language (`data/games/hrg/*.hrg`) and, for the same games, in the Regular
Boardgames (RBG) language (`data/games/rbg/*.rbg`); both languages are defined
in `method/rg/` and the paper in `paper/`. A method is a **compiler**: given
one rule file (HRG or RBG) it must produce

1. a C++ forward model (`reasoner.hpp`, `reasoner.cpp`) implementing the
   `reasoner::` API described below, and
2. the low-level Regular Games (RG) rules automaton it derived for the game
   (`game.json`, the RG abstract-syntax JSON accepted by the official RG
   compiler `rg2cpp`, i.e. after the upstream `adjust_AST.py` normalisation).

The forward model must play exactly the game in the rule file. The goal is a
forward model that executes uniformly random playouts with as little work as
possible, and an automaton for the game that is as small as possible.

## Interface

A method lives in `method/compilers/<name>/` and provides

- `compile.sh <rules> <outdir>` — must write `reasoner.hpp`,
  `reasoner.cpp` and `game.json` into `<outdir>`. It is called once per rule
  file with a copy named `rules.hrg` or `rules.rbg`, with the workspace as working directory, and
  must finish within 15 seconds per game (the reference needs about 1-2 s).
- optionally `prepare.sh` — one-time, input-independent setup (for example
  building tools), run once before the per-game calls (time cap 1 hour).

Every directory under `method/compilers/` that contains a `compile.sh` is a
method and is scored; one that fails gets the worst score.

The forward model API (namespace `reasoner`), as used by the evaluator's
driver:

- `reasoner::GameState` — default-constructible initial state, copyable;
  `getCurrentPlayer()`, `isTerminal()`, `getPlayerScore(p)` for players
  `2 .. 1 + PLAYERS_COUNT`, `getAllMoves(std::vector<reasoner::Move>&, reasoner::RgCache&)`,
  `applyMove(const reasoner::Move&, reasoner::RgCache&)`, `applyAnyMove(reasoner::RgCache&)`
  (applies the single move of the deterministic `keeper` system player);
- `reasoner::RgCache` (default-constructible), `reasoner::Move`,
  `reasoner::PLAYERS_COUNT`, `reasoner::keeper`, `reasoner::random`.

The reference compiler in `method/compilers/hrg_rg_optimized/` produces
exactly this interface.

## Rules of the game for submissions

The submitted C++ is compiled and run by the evaluator together with its own
driver. It may only implement the forward model: it may not perform I/O, read
the environment, spawn processes or threads, terminate the process, use inline
assembly, define symbols outside its own `reasoner` namespace that could
replace library or driver functions, or override the evaluator's compiler
settings (`#pragma GCC optimize/target`, `optimize`/`target`/`constructor`
attributes). Such submissions fail.
