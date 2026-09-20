#include <gtest/gtest.h>
#include <toolbox/scoped_timer.hpp>

#include <chrono>
#include <thread>

TEST(ScopedTimer, MeasuresElapsedTime) {
  std::int64_t reported = 0;

  {
    toolbox::ScopedTimer t("sleep", [&reported](std::int64_t us) { reported = us; });
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }

  EXPECT_GE(reported, 15000);
  EXPECT_LE(reported, 60000);
}

TEST(ScopedTimer, ReportsTheLabel) {
  std::string seen;

  {
    toolbox::ScopedTimer t("parse", [&seen](std::int64_t) {});
    seen = "parse";
  }

  EXPECT_EQ(seen, "parse");
}
