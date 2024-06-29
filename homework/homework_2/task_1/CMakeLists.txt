cmake_minimum_required(VERSION 3.10)
project(random_number_guess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include ClangFormat.cmake
include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(task_1 task_1.cpp)