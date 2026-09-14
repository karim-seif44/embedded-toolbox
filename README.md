# embedded-toolbox

Small, tested C++17 utilities for embedded work. Header-only, no dependencies
beyond the standard library.

## Build

    cmake -S . -B build -G Ninja
    cmake --build build
    ctest --test-dir build --output-on-failure

## Sanitized build

    cmake -S . -B build-asan -G Ninja -DSANITIZE=ON
    cmake --build build-asan
    ctest --test-dir build-asan --output-on-failure

## What's inside

| Header | Purpose |
|---|---|
| toolbox/bits.hpp | constexpr bit set / clear / test helpers for register work |

Warnings are -Wall -Wextra -Wpedantic -Werror on project code only; third-party
code builds with its own defaults.
