cmake_minimum_required(VERSION 3.10)
project(ImageBrowser)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(fmt REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add the library
add_library(image_browser STATIC
    src/image_browser.cpp
    src/html_writer.cpp
)

# Specify include directories
target_include_directories(image_browser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/api
)

target_link_libraries(image_browser fmt::fmt)

add_executable(create_image_browser src/main.cpp)

# Link the executable to the library
target_link_libraries(create_image_browser PRIVATE image_browser)
