#include "ritual/platform/window.hpp"
#include "ritual/core/log.hpp"

#include <GLFW/glfw3.h>

namespace ritual {

namespace {

void glfw_error_callback(int, const char *msg) { ritual::log_error(msg); }

} // namespace

Window::Window(WindowProps props) {
  glfwSetErrorCallback(glfw_error_callback);

  if (!glfwInit()) {
    ritual::log_error("Failed to initialize GLFW");
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, props.resizable);

  handle_ = glfwCreateWindow(props.width, props.height, props.title, nullptr,
                             nullptr);
  if (!handle_) {
    glfwTerminate();
    ritual::log_error("Failed to create window");
    return;
  }

  glfwSetWindowUserPointer(handle_, this);
}

Window::~Window() {
  if (handle_ != nullptr) {
    glfwDestroyWindow(handle_);
    handle_ = nullptr;
  }
  glfwTerminate();
}

void Window::swap_buffers() {
  glfwSwapBuffers(handle_);
}

void Window::poll_events() {
  glfwPollEvents();
}

bool Window::should_close() const {
  return glfwWindowShouldClose(handle_);
}

void Window::make_current() const {
  glfwMakeContextCurrent(handle_);
}

void Window::set_swap_interval(int interval) {
  glfwSwapInterval(interval);
}

} // namespace ritual