# Overview

**Paper ID:** 2511.10593
**Title:** Regular Games - an Automata-Based General Game Playing Language
**Domain:** General game playing / formal game languages / compiler optimization

Regular Games proposes an automata-based rule language and compiler for general game playing. The core claim is that game rules can be translated, optimized, and compiled into compact generated forward models that run legal game simulations efficiently.

This workspace packages the official RG interpreter and RGcompiler sources, vendors Rust dependencies for offline compute nodes, and provides a reproducible harness for HRG game optimization plus generated C++ playout checks.
