## Standard Template Libraries (STL) in CPP

### Vectors (std::vector)

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

Reference: [`vectors`](./vectors.cpp)

### Array (std::array)

Covered fixed-size array as an STL container, contrasted with std::vector.

- **Template signature**: `array<T, N>` — size is a compile-time constant, part of the type itself (unlike vector)
- **Initialization**: brace-init works directly (`{3,4,5,1,2}` or `{{...}}`); `.fill(v)` sets every element to `v`
- **`.size()` == `.max_size()`** always, since array can't grow/shrink — unlike vector where capacity can exceed size
- **`sizeof(arr)`** gives the exact byte size of N*sizeof(T) — no hidden overhead, unlike vector (which stores a pointer + size + capacity on the stack, with data on the heap)
- **`[]` vs `.at()`**: same distinction as vector — `[]` unchecked, `.at()` bounds-checked (throws `std::out_of_range`)
- **`.front()`/`.back()`**: return references to first/last element
- **`.swap()`**: swaps contents between two arrays of the same type/size — O(N), element-by-element (no pointer-swap trick like vector, since array data lives inline, not on the heap)
- **`.data()`**: raw pointer to underlying storage — used with `memcpy` for C-style buffer operations; gotcha: must manually account for null terminator if treating as a C-string, array doesn't do this for you
- **`.empty()`**: true only if N == 0 (a `array<T,0>` is legal but degenerate)
- **Works with `<algorithm>`**: `std::sort(arr.begin(), arr.end())` — same iterator interface as vector

Reference: [`arrays`](./arrays.cpp)
