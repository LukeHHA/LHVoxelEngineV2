cmake_minimum_required(VERSION 3.50)
project(LHCraft VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/External)

add_subdirectory(Core)
add_subdirectory(LHCraft)






