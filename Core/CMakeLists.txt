cmake_minimum_required(VERSION 3.50)

project(LHCraftCoreLib VERSION 1.0)

add_library(Core STATIC
    Src/Core/Core.cpp
)

# exposes the header PUBLICLY so the compiler can resolve the include
target_include_directories(Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Src
)