# Install script for directory: /Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/src/libFastNoiseD.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFastNoiseD.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFastNoiseD.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFastNoiseD.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/FastSIMD" TYPE FILE FILES
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastSIMD/FastSIMD.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastSIMD/FastSIMD_Config.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastSIMD/FastSIMD_Export.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastSIMD/FunctionList.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastSIMD/InlInclude.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastSIMD/SIMDTypeList.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/FastNoise" TYPE FILE FILES
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/FastNoise.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/FastNoise_C.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/FastNoise_Config.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/FastNoise_Export.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Metadata.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/SmartNode.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/FastNoise/Generators" TYPE FILE FILES
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/BasicGenerators.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Blends.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Cellular.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/DomainWarp.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/DomainWarpFractal.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Fractal.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Generator.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Modifiers.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Perlin.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Simplex.h"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/Core/Vendor/FastNoise2/src/../include/FastNoise/Generators/Value.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2" TYPE FILE FILES
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/generated/FastNoise2Config.cmake"
    "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/generated/FastNoise2ConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2/FastNoise2Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2/FastNoise2Targets.cmake"
         "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/CMakeFiles/Export/685b7b2fe36c8f3a2e6ec6f0a6279b14/FastNoise2Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2/FastNoise2Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2/FastNoise2Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2" TYPE FILE FILES "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/CMakeFiles/Export/685b7b2fe36c8f3a2e6ec6f0a6279b14/FastNoise2Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FastNoise2" TYPE FILE FILES "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/CMakeFiles/Export/685b7b2fe36c8f3a2e6ec6f0a6279b14/FastNoise2Targets-debug.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/src/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/amyalex/Documents/Production_Projects/LHVoxelEngineV2/build/Core/Vendor/FastNoise2/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
