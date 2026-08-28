#include "ritual/core/log.hpp"

#include <cstdio>

namespace ritual {

void log_info(const char *msg) { std::printf("[INFO] %s\n", msg); }

void log_error(const char *msg) { std::fprintf(stderr, "[ERROR] %s\n", msg); }

} // namespace ritual