# Audit progress

- Scientific sensitivity checked: genuine path compression improves scored
  size, removing optimization worsens it, and slower execution ties.
- Three actual RNG seeds measured; all scored metrics have zero spread.
- All 17 construction cases finished with saved train and hidden-test scores.
- Eleven named shortcut cases tested, including one null-valued failure and
  a cohort-dependent task-failure win. Bounded brute force did not finish.
- REDTEAM.md and normalized rank calculations written.
- Fresh CPU job `12cf7f46-91a` verified all 17 saved submissions against the
  unchanged hidden test, with exact equality to construction-job scores.
- Audit complete. Original job script and non-audit tracked files restored;
  all evidence and calculations retained under redteam/ and REDTEAM.md.
  Reproduction milestone remains `core_claim_plus`.
