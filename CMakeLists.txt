project(stl_cxx_base CXX)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

include(cmake/common.cmake)

add_subdirectory(3rdParty EXCLUDE_FROM_ALL)
add_subdirectory(examples)
add_subdirectory(exercises)
add_subdirectory(tests)


