add_library(SegFault STATIC src/Application.cpp  "src/EntryPoint.hpp"  "src/EntryPoint.cpp")
target_include_directories(SegFault PUBLIC src)