find_package(GTest CONFIG REQUIRED)

add_executable(ritual_test
  log_test.cpp
)
target_link_libraries(ritual_test PRIVATE
  Ritual::engine
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ritual_test)
