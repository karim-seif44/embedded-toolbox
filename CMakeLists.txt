cmake_minimum_required(VERSION 3.20)
project(embedded_toolbox CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Strict warnings for OUR code only, never for dependencies.
add_library(toolbox_warnings INTERFACE)
target_compile_options(toolbox_warnings INTERFACE -Wall -Wextra -Wpedantic -Werror)

add_library(toolbox INTERFACE)
target_include_directories(toolbox INTERFACE include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
