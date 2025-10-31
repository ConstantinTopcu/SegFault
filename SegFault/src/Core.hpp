#pragma once

namespace SegFault
{

#ifdef _WIN32
#define SF_PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define SF_PLATFORM_MAC_OS
#elif defined(__linux__)
#define SF_PLATFORM_LINUX
#endif

}