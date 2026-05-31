# Paper's Method

The paper introduces Regular Games (RG), a low-level automata language for finite games, and High-Level Regular Games (HRG), a more convenient source language. HRG and existing rule languages are translated into RG automata. The automata are then validated, optimized through static transformation passes, and compiled into C++ forward models.

The reproduced method uses the authors' official pipeline:

1. Parse HRG game descriptions.
2. Translate them into RG automata.
3. Run the paper's optimizer passes, including skip-edge compaction, assignment and comparison simplifications, reachability/tag simplifications, and exclusive-edge joins.
4. Compile the optimized automaton with `rg2cpp` into a C++ reasoner exposing legal-move generation, move application, terminal checks, current player, and scores.
5. Run deterministic random playouts through the generated reasoner as a correctness check.

The reproduction keeps the paper's computation intact but scores structural metrics instead of wall-clock throughput.
