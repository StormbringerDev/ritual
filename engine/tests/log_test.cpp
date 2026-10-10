#include "ritual/core/log.hpp"

#include "gtest/gtest.h"
#include <gtest/gtest.h>

#include <string>

namespace {

struct Captured {
  std::string out;
  std::string err;
};

template <typename Fn> Captured capture(Fn fn) {
  testing::internal::CaptureStdout();
  testing::internal::CaptureStderr();
  fn();
  Captured c;
  c.out = testing::internal::GetCapturedStdout();
  c.err = testing::internal::GetCapturedStderr();
  return c;
}

} // namespace

TEST(LogTest, InfoWritesToStdout) {
  const Captured c = capture([] { ritual::log_info("hello"); });
  EXPECT_EQ(c.out, "[INFO]: hello\n");
}

TEST(LogTest, ErrorWritesToStderr) {
  const Captured c = capture([] { ritual::log_error("boom"); });
  EXPECT_EQ(c.err, "[ERROR]: boom\n");
}

TEST(LogTest, InfoDoesNotWriteToStderr) {
  const Captured c = capture([] { ritual::log_info("hello"); });
  EXPECT_TRUE(c.err.empty());
}

TEST(LogTest, ErrorDoesNotWriteToStdout) {
  const Captured c = capture([] { ritual::log_error("boom"); });
  EXPECT_TRUE(c.out.empty());
}

TEST(LogTest, EmptyStringDoesNotCrash) {
  EXPECT_NO_FATAL_FAILURE({
    const Captured c = capture([] {
      ritual::log_info("");
      ritual::log_error("");
    });
    EXPECT_EQ(c.out, "[INFO]: \n");
    EXPECT_EQ(c.err, "[ERROR]: \n");
  });
}