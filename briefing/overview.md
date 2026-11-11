# Overview

**Paper ID:** 2511.10593
**Title:** Regular Games - an Automata-Based General Game Playing Language
**Domain:** General game playing / formal game languages / compiler optimization

Regular Games proposes an automata-based rule language and compiler for general
game playing. Its central claim is that game rules translated into optimized
rule automata compile into forward models that are faster than those of the
previous fastest system (Regular Boardgames), with much smaller automata than
a direct translation.

This gym asks for a compiler from game-rule files to C++ forward models. It
verifies every produced model against ground truth and scores the executed
instructions per random playout (relative to frozen comparison models) and the
size of the produced rules automaton. The official RG toolchain is packaged in
`method/` as the reference compiler.
