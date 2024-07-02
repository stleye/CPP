cmake_minimum_required(VERSION 3.10)
project(NamedVector)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(named_vector STATIC
    src/named_vector.cpp
)

target_include_directories(named_vector PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)