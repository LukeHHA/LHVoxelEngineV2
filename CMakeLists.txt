cmake_minimum_required(VERSION 3.50)
project(LHCraft VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(
  -Wall
  -Wextra
  -Wpedantic
)

add_subdirectory(Core)
add_subdirectory(LHCraft)








