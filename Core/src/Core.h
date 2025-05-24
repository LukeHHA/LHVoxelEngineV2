#pragma once

#ifdef __APPLE__

#include "Application/Application.h"
#include "Window/Window.h"
#include "Logging/Logging.h"

// Entry Point

#include "EntryPoint.h"

#else
#error Core only supports MacOS
#endif
