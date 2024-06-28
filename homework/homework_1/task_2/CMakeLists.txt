cmake_minimum_required(VERSION 3.10)
project(ipb_arithmetic)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the output directories for libraries and binaries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(include)

# Add the library (static)
add_library(ipb_arithmetic STATIC
    src/subtract.cpp
    src/sum.cpp
)

# Add the executable
add_executable(test_ipb_arithmetic
    src/main.cpp
)

# Link the library to the executable
target_link_libraries(test_ipb_arithmetic ipb_arithmetic)

# Install rules
install(TARGETS ipb_arithmetic test_ipb_arithmetic
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/ipb_arithmetic)