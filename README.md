## Vectors (std::vector)

Covered vector internals and STL usage by writing and testing `vectors.cpp`.

- **size vs capacity**: size = constructed elements, capacity = allocated slots; independent of each other
- **Growth mechanism**: doubles when `size == capacity` on next `push_back`; NOT implemented via `realloc` — allocates new block, move-constructs old elements into it, destroys old elements, frees old block (has to run constructors/destructors, unlike a raw C realloc)
- **`reserve(n)`**: allocates capacity for `n` elements upfront, size stays 0 — avoids repeated reallocation when final size is known ahead of time
- **`resize(n)`**: actually constructs real elements up to size `n` (value-initialized); shrinking destroys extra elements but capacity is untouched
- **Indexed access (`v[i] = ...`) is only valid after elements are constructed** — `reserve()` alone gives raw unconstructed memory, `resize()` or `push_back()` are needed first
- **Iterator/pointer invalidation**:
  - `push_back` triggering reallocation → full invalidation, old buffer freed (classic use-after-free if a stale pointer is dereferenced)
  - `insert`/`erase` in the middle → partial invalidation, elements from that point onward shift (memmove-like), no reallocation
  - `pop_back()` → narrow invalidation, only the removed element itself
- **`[]` vs `.at()`**: `[]` no bounds check (UB on out-of-range), `.at()` throws `std::out_of_range`
- **`vector(n, v)`**: constructor form giving `n` copies of value `v`
- **Nested vectors**: `vector<vector<int>>` for 2D data, iterated with `const auto&` to avoid copies
- Combined with `<algorithm>`: used `std::find` inside `.erase()` to remove by value

Reference: `vectors.cpp`
