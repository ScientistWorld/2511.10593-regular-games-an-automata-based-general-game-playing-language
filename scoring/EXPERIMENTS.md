# Experiments

## forward_model_efficiency

Establishes how efficient the forward model is that a method generates from a
game-rule file, under the workload a general game playing agent puts on it:
many uniformly random playouts. For every game the evaluator first checks that
the generated model plays exactly the game in the rule file (game-tree counts
and playout statistics against ground truth), then counts the machine
instructions it executes for a fixed playout count with a fixed seed. The
score compares this work with a fixed comparison model for the same game built
from a matched description in another rule language (geometric mean over games
and the worst game). Any game that fails verification fails the method's run.

## automaton_optimization

Establishes how compact the rules automaton is that a method derives for each
game. The evaluator independently compiles the submitted automaton with the
official reference compiler, checks that it plays exactly the game in the rule
file, and counts its nodes and edges relative to a direct, untransformed
translation of the same rule file (mean percentage reduction over games). Any
automaton that fails verification fails the method's run.

## translated_rules_optimization

Establishes how well a method handles rule descriptions that were written in a
different rule language and translated automatically, where the paper itself
reports that its system does not consistently reach the efficiency of that
language's own compiler. For each game's RBG description the evaluator checks
that the generated model plays exactly that description (against its direct,
untransformed translation), counts the instructions per random playout
relative to that direct translation, and counts the size of the submitted
automaton relative to it. Any failure fails the method's run.
