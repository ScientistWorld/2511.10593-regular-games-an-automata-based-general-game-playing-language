# Compute audit history

- `676cc982-768`: job wrapper exited 0, but no scored audit case completed.
  The audit harness failed when compiling a copied playout driver because its
  include search path omitted `method/rgcompiler/test/fast_random.hpp`.
  Original model generation succeeded and was cached. The brute-force probe
  explored roughly 50,000 states in each game without completing enumeration.
  Fixed the include paths and changed the bundle to return a nonzero exit code
  if any case fails. These infrastructure failures are not method results.
