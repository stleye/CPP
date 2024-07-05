cmake_minimum_required(VERSION 3.10)
project(NamedVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Create a library from sources
# add_library(named_vector STATIC
#     src/named_vector.cpp
#     src/ipb_algorithm.cpp
# )

# # Set include directories for the library
# target_include_directories(named_vector PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

# Create an executable from main.cpp
add_executable(create_named_vector src/main.cpp src/named_vector.tpp)

target_include_directories(create_named_vector PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the executable with the library
#target_link_libraries(create_named_vector PRIVATE named_vector)