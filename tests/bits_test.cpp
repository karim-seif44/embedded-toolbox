#include <gtest/gtest.h>
#include <toolbox/bits.hpp>

TEST(Bits, SetBit) { EXPECT_EQ(toolbox::set_bit(0u, 3), 0x08u); }

TEST(Bits, ClearBit) { EXPECT_EQ(toolbox::clear_bit(0xFFu, 0), 0xFEu); }

TEST(Bits, IsBitSet) {
  EXPECT_TRUE(toolbox::is_bit_set(0b1010u, 1));
  EXPECT_FALSE(toolbox::is_bit_set(0b1010u, 0));
}

TEST(Bits, WorksAtCompileTime) {
  static_assert(toolbox::set_bit(0u, 7) == 0x80u, "constexpr must fold at compile time");
  SUCCEED();
}
