cmake_minimum_required(VERSION 3.5)
project(Splat CXX)

# Add subdirectories
add_subdirectory(src)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
