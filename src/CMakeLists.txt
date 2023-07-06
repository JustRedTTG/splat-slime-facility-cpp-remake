# Add source files
file(GLOB_RECURSE SOURCES "*.cpp")

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add platform-specific files
if (UNIX)
   file(GLOB_RECURSE GRAPHICS_SOURCES "src/graphics/linux/*.cpp")
   file(GLOB_RECURSE INPUT_SOURCES "src/input/linux/*.cpp")
elseif (WIN32)
   file(GLOB_RECURSE GRAPHICS_SOURCES "src/graphics/windows/*.cpp")
   file(GLOB_RECURSE INPUT_SOURCES "src/input/windows/*.cpp")
endif()

# Create executable
add_executable(Splat ${SOURCES} ${GRAPHICS_SOURCES} ${INPUT_SOURCES})
