#include <ritual/core/log.hpp>

#include <gtest/gtest.h>

#include <cstdio>
#include <string>
#include <unistd.h>

namespace {

// Redirect a FILE* to a temp file for the lifetime of the object, then
// restore the original fd.
class FdCapture {
public:
  explicit FdCapture(FILE *stream) : stream_(stream), fd_(fileno(stream)) {
    std::fflush(stream_);
    saved_ = dup(fd_);
    tmp_ = std::tmpfile();
    // ASSERT_NE(saved_, -1);
    // ASSERT_NE(tmp_, nullptr);
    dup2(fileno(tmp_), fd_);
  }

  FdCapture(const FdCapture &) = delete;
  FdCapture &operator=(const FdCapture &) = delete;

  ~FdCapture() { restore(); }

  std::string read() {
    std::fflush(stream_);
    std::rewind(tmp_);

    std::string out;
    char buf[256];
    while (std::fgets(buf, sizeof(buf), tmp_) != nullptr) {
      out += buf;
    }
    return out;
  }

private:
  void restore() {
    if (saved_ != -1) {
      std::fflush(stream_);
      dup2(saved_, fd_);
      ::close(saved_);
      saved_ = -1;
    }
    if (tmp_ != nullptr) {
      std::fclose(tmp_);
      tmp_ = nullptr;
    }
  }

  FILE *stream_;
  int fd_;
  int saved_ = -1;
  FILE *tmp_ = nullptr;
};

} // namespace

TEST(Log, InfoWritesMessageToStdout) {
  FdCapture cap(stdout);
  ritual::log_info("booting renderer");
  EXPECT_NE(cap.read().find("booting renderer"), std::string::npos);
}

TEST(Log, ErrorWritesMessageToStderr) {
  FdCapture cap(stderr);
  ritual::log_error("shader compile failed");
  EXPECT_NE(cap.read().find("shader compile failed"), std::string::npos);
}

TEST(Log, InfoDoesNotWriteToStderr) {
  FdCapture cap(stderr);
  ritual::log_info("only stdout");
  EXPECT_TRUE(cap.read().empty());
}

TEST(Log, ErrorDoesNotWriteToStdout) {
  FdCapture cap(stdout);
  ritual::log_error("only stderr");
  EXPECT_TRUE(cap.read().empty());
}

TEST(Log, EmptyMessageDoesNotCrash) {
  ritual::log_info("");
  ritual::log_error("");
  SUCCEED();
}