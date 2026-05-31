# Reproduction Milestones

**Current: core_claim_plus**

## Progress Log

### [2026-05-31 17:38] - core_claim
- Ran the official Regular Games HRG-to-RG optimizer, rg2cpp C++ generation, C++ compilation, and deterministic playout pipeline on Connect4 and Breakthrough.
- Reproduced the paper's core structural optimization claim: 44.854% fewer automaton nodes and 39.167% fewer automaton edges, close to the reported 47% and 41%.
- Preserved the correctness constraint: both baseline and optimized generated reasoners completed 200/200 deterministic playouts.

### [2026-05-31 18:05] - core_claim
- Continuation audit confirmed the implementation is the paper's actual automata optimization and C++ reasoner generation pipeline, not a surrogate.
- Queued an expanded HRG-game run to test the same claim on additional settings.

### [2026-05-31 18:15] - core_claim_plus
- Expanded the core experiment from two HRG games to six: Connect4, Breakthrough, Hex, Yavalath, Tic-Tac-Toe, and Tic-Tac-Die.
- The optimized pipeline averaged 49.427% fewer automaton nodes and 44.911% fewer automaton edges, exceeding the paper's reported 47% and 41% HRG structural reductions on this subset.
- The correctness constraint still held: all baseline and optimized generated reasoners completed 200/200 deterministic playouts.

## Stop Justification
- Completed at milestone `core_claim_plus`.
