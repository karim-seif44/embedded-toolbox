add_executable(toolbox_tests bits_test.cpp)
target_link_libraries(toolbox_tests
  PRIVATE toolbox toolbox_warnings toolbox_sanitizers GTest::gtest_main)

add_executable(asan_demo asan_demo.cpp)
target_link_libraries(asan_demo
  PRIVATE toolbox toolbox_warnings toolbox_sanitizers)

include(GoogleTest)
gtest_discover_tests(toolbox_tests)
