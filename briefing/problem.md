# Problem Definition

The task is to represent finite turn-based games, including games with chance and imperfect information, in a machine-readable rule language and produce a reusable forward model. A forward model must expose the current player, legal moves, state transitions, terminal detection, and scores without relying on game-specific handwritten code.

Success is measured by whether the generated model stays compact enough to analyze and compile while still executing legal playouts from the original game rules. The problem definition is method-agnostic: any future solution may use a different implementation, but it must consume the same game-rule inputs and produce artifacts that `scripts/evaluate.sh` can score.
