cmake_minimum_required(VERSION 3.10)
project(html_writer)

set(CMAKE_CXX_STANDARD 17)

find_package(fmt REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)

# Add the library
add_library(html_writer STATIC
    src/html_writer.cpp
    # Add more source files as needed
)

# Specify include directories
target_include_directories(html_writer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/api
)

target_link_libraries(html_writer fmt::fmt)

# Add executable and specify source file
add_executable(test_html_writer
    src/test_html_writer.cpp  # Specify the source file here
)

# Link the library to the executable
target_link_libraries(test_html_writer html_writer)
