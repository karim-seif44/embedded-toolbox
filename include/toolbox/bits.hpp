#pragma once
#include <cstdint>

namespace toolbox {

constexpr std::uint32_t set_bit(std::uint32_t reg, unsigned n) { return reg | (1u << n); }
constexpr std::uint32_t clear_bit(std::uint32_t reg, unsigned n) { return reg & ~(1u << n); }
constexpr bool is_bit_set(std::uint32_t reg, unsigned n) { return ((reg >> n) & 1u) != 0u; }

}  // namespace toolbox
