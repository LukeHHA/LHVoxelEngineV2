cmake_minimum_required(VERSION 3.20)
project(LHCraft VERSION 1.0)

option(ENABLE_WARNINGS "Turn on -Wall -Wextra in Debug builds" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Core)
add_subdirectory(LHCraft)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  if(ENABLE_WARNINGS)
    target_compile_options(Core PUBLIC
      -Wall
      -Wextra
      -Wno-unused-variable
      -Wno-unused-parameter
    )
  else()
    # -w turns off all warnings
    target_compile_options(Core PUBLIC
      -w
    )
  endif()
endif()
