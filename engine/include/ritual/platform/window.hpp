#pragma once

struct GLFWwindow;

namespace ritual {

struct WindowProps {
  int width = 640;
  int height = 480;
  const char *title = "Ritual";
  bool resizable = true;
};

class Window {
public:
  Window(WindowProps props);
  ~Window();

  void swap_buffers();
  void poll_events();
  bool should_close() const;

  void make_current() const;
  void set_swap_interval(int);

private:
  GLFWwindow *handle_ = nullptr;
};

} // namespace ritual