#pragma once

#include "cmakeConfig.h"
#include "Logging/Logging.h"

#ifdef __APPLE__

// --- Breakpoint for debugger on MacOS ---
#if defined(__APPLE__) || defined(__linux__)
#include <signal.h>
#define DEBUG_BREAK() raise(SIGTRAP)
#elif defined(__clang__)
#define DEBUG_BREAK() __builtin_debugtrap()
#else
#define DEBUG_BREAK() __builtin_trap()
#endif

// --- Engine and App specific ASSERT ---
#ifdef LHCRAFT_ENABLE_ASSERTS
#pragma message("Asserts are ENABLED")
#define CORE_ASSERT(x, ...)                                       \
    {                                                             \
        if (!(x))                                                 \
        {                                                         \
            CORE_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            DEBUG_BREAK();                                        \
        }                                                         \
    }
#define APP_ASSERT(x, ...)                                       \
    {                                                            \
        if (!(x))                                                \
        {                                                        \
            APP_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            DEBUG_BREAK();                                       \
        }                                                        \
    }
#else
#pragma message("Asserts are DISABLED")
#define CORE_ASSERT(x, ...)
#define APP_ASSERT(x, ...)
#endif

#else
#error Core only supports MacOS
#endif
