#pragma once

#include <stdint.h>

namespace SegFault
{

#ifdef _WIN32
#define SF_PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define SF_PLATFORM_MAC_OS
#elif defined(__linux__)
#define SF_PLATFORM_LINUX
#else
#error Unknown OS.
#endif

using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using int8  = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

}