find_package(GTest CONFIG REQUIRED)

add_executable(ritual_tests
  test_log.cpp
)

target_link_libraries(ritual_tests PRIVATE
  Ritual::Engine
  GTest::gtest_main
)

if(MSVC)
  target_compile_options(ritual_tests PRIVATE /W4 /permissive-)
else()
  target_compile_options(ritual_tests PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
endif()

include(GoogleTest)
gtest_discover_tests(ritual_tests)
