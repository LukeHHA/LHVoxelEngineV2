# LHVoxelEngineV2

A new project aiming to fix the organisation and mess that was the previous voxel engine. While the previous "Engine" was more of an
attempt at getting a voxel like game developed, it lacked the organisation and forethought that is evedently important when making games.
This project will focus more on the development of reproducable and abstract applications that can be built with an integer-aligned voxel grid system
with a primary focus on trying to limit application space to world coordinates. This project will follow the core/app architecture as seen on The Cherno's
Youtube channel.

---

Currently there will be limited game examples as I work to implement features avalible to the app space.

## Getting Started

Project is currently being developed in Visual Studio Code on MacOs.
Currently the aim is to develop the project for MacOs and try to implement Linux integration.
Currently no desire to develop for Windows.

<ins>**1. Clone**</ins>

Clone the repo at `git clone --recursive https://github.com/THEDEGENER/LHVoxelEngineV2`.

<ins>**2. Dependencies**</ins>

Currently the cmake file will link to `-OpenGL -Cocoa -IOKit` if detected on apple. `GLFW GLAD glm` are included in the directory and configured in cmake. Currently cmake will not resolve any missing dependencies, however in the future I plane to configure the project to resolve any issues and test on multipul devices.

## Goal

Ideally by learning to effectivly abstract the OpenGl pipeline and messy configuration I hope to have some working version of an engine that can quickly be used to spin up a voxel world. How much work from the developer will be needed past getting to that point is yet to be seen, however getting to that point quickly already clears one of the major hurdles when coding a game in c++ without a full fledged engine.
