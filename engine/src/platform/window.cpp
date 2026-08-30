#include "ritual/platform/window.hpp"
#include "ritual/core/log.hpp"

#include <GLFW/glfw3.h>

namespace ritual {

Window::Window(WindowProps props) {
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
}

void Window::swap_buffers() { glfwSwapBuffers(handle_); }

bool Window::should_close() const { return glfwWindowShouldClose(handle_); }

void Window::make_current() const { glfwMakeContextCurrent(handle_); }

void Window::set_swap_interval(int interval) { glfwSwapInterval(interval); }

} // namespace ritual