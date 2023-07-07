cmake_minimum_required(VERSION 3.5)
project(Splat CXX)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)
include_directories(Splat ${SDL2_INCLUDE_DIRS})
find_package(SDL2_image REQUIRED)
include_directories(Splat ${SDL2_IMAGE_INCLUDE_DIRS})

# Add platform-specific files
#if (UNIX)
#    file(GLOB_RECURSE GRAPHICS_SOURCES "src/graphics/linux/*.cpp")
#    file(GLOB_RECURSE INPUT_SOURCES "src/input/linux/*.cpp")
#elseif (WIN32)
#    file(GLOB_RECURSE GRAPHICS_SOURCES "src/graphics/windows/*.cpp")
#    file(GLOB_RECURSE INPUT_SOURCES "src/input/windows/*.cpp")
#endif()

# Create executable
add_executable(Splat ${SOURCES})
target_link_libraries(Splat  ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})