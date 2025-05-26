# Changelog

All notable changes to this project will be documented in this file.

## [Unreleased] - 2025-05-26

### Added

- `Events` folder containing all API for events system
- Event system within `Application.cpp` that binds callbacks to an `Application::OnEvent` function which dispatches events to functions
- KeyCode and Mouse codes in `Events`

- `Layer` system

## [Unreleased] - 2025-05-25

### Added

- `cmakeConfig.h.in` to allow global configs to be included within source files such as `VERSION_MAJOR` `VERSION_MINOR`
- `LHCpch.h` in `Core/src/` of headers to be precompiled by cmake

## [Unreleased] - 2025-05-24

### Added

- `TODO.md`
- `spdlog` as git submodule
- `CORE_LOG_` and `APP_LOG_` Macros defined in `Logging.h` with:
  - `INFO`
  - `WARN`
  - `ERROR`
  - `TRACE`
  - `CRITICAL`
    As possible options

### Changed

- Updated location of the `Vendor` Folder (Previously `External`) to the `Core` Folder

### Fixed

- Fixed the include paths in `Core.h` aswell as `Application.h`

### Security

## [1.0] – 2025-05-24
