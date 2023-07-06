# Add source files
file(GLOB_RECURSE SOURCES "*.cpp")

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create executable
add_executable(Splat ${SOURCES})
