# Research Direction

This gym studies compiling formal game rules into efficient forward models via
rules automata. Improvements should stay in that family: better automaton
transformations and static analyses, better pragma/analysis inference, better
code generation from automata, or equivalent general rule-compilation
techniques that work for any rule file.

Out of scope even if they raise scores: hand-written or game-specific engines,
recognising particular games, caching outputs, learned simulators, and
anything that changes how the evaluator compiles, runs or measures the model.
Note the trade-off the experiments expose: a smaller automaton is not
automatically a faster forward model.
