cmake_minimum_required(VERSION 3.50)

project(LHCraftCoreLib VERSION 1.0)

add_library(Core STATIC
    ${THIRD_PARTY_DIR}/glad/glad.c
    src/Core.cpp
    src/window/Window.cpp
)

# exposes the header PUBLICLY so the compiler can resolve the include
target_include_directories(Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${THIRD_PARTY_DIR}/glm
    ${THIRD_PARTY_DIR}/glad
    ${THIRD_PARTY_DIR}/khr
    ${THIRD_PARTY_DIR}/glfw
)

# Target link libs seems to need to be specified with PUBLIC/PRIVATE/INTERFACE or none at all
target_link_libraries(Core PUBLIC
    ${THIRD_PARTY_DIR}/glfw/libglfw3.a
)

if (APPLE)
    target_link_libraries(Core PUBLIC "-framework IOKit")
    target_link_libraries(Core PUBLIC "-framework Cocoa")
    target_link_libraries(Core PUBLIC "-framework OpenGL")
endif()

