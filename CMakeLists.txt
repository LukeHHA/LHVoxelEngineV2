cmake_minimum_required(VERSION 3.20)
project(LHCraft VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Core)
add_subdirectory(LHCraft)


target_compile_options(Core PUBLIC
  -Wall
  -Wextra
  -fdiagnostics-color=auto
)
