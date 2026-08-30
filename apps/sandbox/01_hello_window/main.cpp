#include "ritual/core/log.hpp"
#include "ritual/platform/window.hpp"

int main() {
  ritual::log_info("Ritual - 01_hello_window");

  ritual::Window window({640, 480, "Ritual - Hellow Window"});

  window.make_current();
  window.set_swap_interval(1);

  while (!window.should_close()) {
    window.poll_events();
    window.swap_buffers();
  }

  ritual::log_info("Window closed");
  return 0;
}