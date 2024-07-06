cmake_minimum_required(VERSION 3.10)

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(${TEST_BINARY}
               test_named_vector.cpp
               test_ipb_algorithm.cpp
               test_main.cpp)

# Set include directories for the library
target_include_directories(${TEST_BINARY} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Add this line to specify the directory where ipb_algorithm library is built
target_link_directories(${TEST_BINARY} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../build/lib  # Adjust path as necessary
)

# Link the executable with the library
target_link_libraries(${TEST_BINARY} PRIVATE ipb_algorithm Catch2::Catch2)

# Register tests with Catch2
catch_discover_tests(${TEST_BINARY})
