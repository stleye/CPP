cmake_minimum_required(VERSION 3.10)
project(named_vector)

# Set C++ standard and requirements
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Find Catch2 package (assuming installed or added via add_subdirectory)
find_package(Catch2 REQUIRED)

# Define the source files for the library and executable
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ipb_algorithm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp  # Example main.cpp
)

# Create a library from sources
add_library(ipb_algorithm STATIC ${SOURCES})

# Set include directories for the library
target_include_directories(ipb_algorithm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Create an executable from main.cpp (if needed)
add_executable(create_named_vector ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(create_named_vector PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the executable with the library
target_link_libraries(create_named_vector PRIVATE ipb_algorithm)

# Optionally, define any compile definitions here
# target_compile_definitions(create_named_vector PRIVATE MY_SYMBOL)

# Define test executable and link with Catch2
set(TEST_BINARY ${PROJECT_NAME}_test)

# Define test source files
set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_named_vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_ipb_algorithm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_main.cpp  # Example test main
)

# Create test executable
add_executable(${TEST_BINARY} ${TEST_SOURCES})

# Set include directories for the test executable
target_include_directories(${TEST_BINARY} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the test executable with the library and Catch2
target_link_libraries(${TEST_BINARY} PRIVATE ipb_algorithm Catch2::Catch2)

# Discover and register tests with Catch2
include(Catch)
catch_discover_tests(${TEST_BINARY})
