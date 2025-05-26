cmake_minimum_required(VERSION 3.50)
project(LHCraftCoreLib VERSION 1.0)

configure_file(
    cmakeConfig.h.in
    cmakeConfig.h
)

add_library(Core STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad/src/glad.c
    src/Application/Application.cpp
    src/window/Window.cpp
    src/Logging/Logging.cpp
    src/Layers/Layer.cpp
    src/Layers/LayerStack.cpp
)

target_compile_definitions(Core PUBLIC
    LHCRAFT_ENABLE_ASSERTS
)

# exposes the header PUBLICLY so the compiler can resolve the include
target_include_directories(Core PUBLIC 
    ${CMAKE_BINARY_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/spdlog/include/spdlog
)

target_precompile_headers(Core PUBLIC
    $<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/src/LHCpch.h>
)

# Target link libs seems to need to be specified with PUBLIC/PRIVATE/INTERFACE or none at all
target_link_libraries(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw/libglfw3.a
)

if (APPLE)
    target_link_libraries(Core PUBLIC "-framework IOKit")
    target_link_libraries(Core PUBLIC "-framework Cocoa")
    target_link_libraries(Core PUBLIC "-framework OpenGL")
endif()

