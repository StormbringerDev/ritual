#pragma once

namespace ritual {

class Platform {
public:
  Platform();
  ~Platform();

  void poll_events();
};

} // namespace ritual