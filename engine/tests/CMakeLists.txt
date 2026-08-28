add_executable(ritual-tests test_log.cpp)
target_link_libraries(ritual-tests PRIVATE Ritual::Engine gtest gtest_main)
add_test(NAME ritual-tests COMMAND ritual-tests)
