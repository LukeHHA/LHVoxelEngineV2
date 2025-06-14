cmake_minimum_required(VERSION 3.20)
project(LHCraftApp)

add_executable(LHCraftApp
    src/App.cpp
    Examples/ExampleRenderLayer.cpp
    Examples/TestOverlay.cpp
)

target_include_directories(LHCraftApp PUBLIC
    Examples/
)

target_link_libraries(LHCraftApp PRIVATE
    Core
)



