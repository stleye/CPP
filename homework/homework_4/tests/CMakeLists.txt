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

# Link the executable with the library
target_link_libraries(${TEST_BINARY} ipb_algorithm Catch2::Catch2)
catch_discover_tests(${TEST_BINARY})
