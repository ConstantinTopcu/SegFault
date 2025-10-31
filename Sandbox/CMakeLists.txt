add_executable(Sandbox src/Sandbox.cpp)
target_link_libraries(Sandbox PRIVATE SegFault)
target_include_directories(Sandbox PRIVATE SegFault/src)