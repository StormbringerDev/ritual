cmake_minimum_required(VERSION 3.21)
project(Ritual
    VERSION 0.1.0
    LANGUAGES CXX C
    DESCRIPTION "Ritual game engine"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(RITUAL_BUILD_EXAMPLES "Build example applications" ON)
option(RITUAL_BUILD_TESTS    "Build unit tests" OFF)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Engine library
add_subdirectory(engine)

# Examples
# if(RITUAL_BUILD_EXAMPLES)
#     add_subdirectory(examples)
# endif()

# Cantrip build (for later)
# add_custom_target(cantrip-runtime
#     COMMAND cargo build --release --manifest-path ${CMAKE_SOURCE_DIR}/cantrip/Cargo.toml
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/cantrip
#     COMMENT "Building Cantrip runtime"
# )