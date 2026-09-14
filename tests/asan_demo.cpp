#include <cstdio>
#include <memory>
#include <toolbox/bits.hpp>

int main() {
  auto reg = std::make_unique<std::uint32_t>(0u);   // owns it
  *reg = toolbox::set_bit(*reg, 4);
  std::printf("reg = 0x%02X\n", *reg);
  return 0;                                         // destructor frees it
}
