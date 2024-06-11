# CMakeLists.txt
cmake_minimum_required(VERSION 3.11.3)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set the project name to "Mazes"
project(Mazes
  VERSION 0.1.0 # https://semver.org/spec/v2.0.0.html
  DESCRIPTION "A simple maze generator"
  LANGUAGES CXX
)

# Find the libpng library
find_package(PNG REQUIRED)

# Set library output path to /lib
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# Add GoogleTest library subdirectory
#add_subdirectory(extern/googletest)

# Add MazeLib as library
add_library(MazeLib
  src/aldous_broder.hpp
  src/aldous_broder.cpp
  src/binary_tree.cpp
  src/cell.hpp
  src/cell.cpp
  src/grid.hpp
  src/grid.cpp
  src/sidewinder.hpp
  src/sidewinder.cpp
  src/wilsons.hpp
  src/wilsons.cpp
)

# Include the libpng headers
target_include_directories(MazeLib PUBLIC ${PNG_INCLUDE_DIR})

# Link against the libpng library
target_link_libraries(MazeLib ${PNG_LIBRARY})

# Add the project executable
add_executable(Maze src/main.cpp)
target_link_libraries(Maze MazeLib)

# Add the testing executable
#add_executable(test test/test.cpp src/cell.cpp)

#target_link_libraries(test gtest gtest_main)
