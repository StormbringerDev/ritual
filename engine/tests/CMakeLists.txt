find_package(GTest CONFIG REQUIRED)

add_executable(ritual-tests
  test_log.cpp
  test_window.cpp
)

target_link_libraries(ritual-tests PRIVATE
  Ritual::Engine
  GTest::gtest_main
)

if(MSVC)
  target_compile_options(ritual-tests PRIVATE /W4 /permissive-)
else()
  target_compile_options(ritual-tests PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
endif()

include(GoogleTest)
gtest_discover_tests(ritual-tests)
