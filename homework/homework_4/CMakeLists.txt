cmake_minimum_required(VERSION 3.10)
project(NamedVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Define the source files
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ipb_algorithm.cpp
)

# Create a library from sources
add_library(ipb_algorithm STATIC ${SOURCES})

# Set include directories for the library
target_include_directories(ipb_algorithm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Create an executable from main.cpp
add_executable(create_named_vector ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(create_named_vector PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the executable with the library
target_link_libraries(create_named_vector PRIVATE ipb_algorithm)

target_compile_definitions(create_named_vector PRIVATE MY_SYMBOL)

# Add tests directory
add_subdirectory(tests)
