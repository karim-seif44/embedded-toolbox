add_executable(toolbox_tests bits_test.cpp)
target_link_libraries(toolbox_tests PRIVATE toolbox toolbox_warnings GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(toolbox_tests)
