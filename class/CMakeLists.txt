cmake_minimum_required(VERSION 3.0)
project(ExampleClassProject)

# Add C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable target
add_executable(example src/main.cpp src/ExampleClass.tpp)

# Include directory for header files
target_include_directories(example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
