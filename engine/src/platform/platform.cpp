#include "ritual/platform/platform.hpp"
#include "ritual/core/log.hpp"

#include <GLFW/glfw3.h>

namespace ritual {

namespace {

void glfw_error_callback(int, const char *msg) { ritual::log_error(msg); }

} // namespace

Platform::Platform() {
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) {
    ritual::log_error("Failed to initialize GLFW");
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Platform::~Platform() {
  glfwTerminate();
}

void Platform::poll_events() { glfwPollEvents(); }

} // namespace ritual