# Engine library
add_library(ritual STATIC)

target_sources(ritual
  PRIVATE
    # Core
    src/core/log.cpp
    # Platform
    # src/platform/window.cpp
    # Renderer
    # src/renderer/opengl/context.cpp
    # Scripting
    # src/scripting/cantrip_host.cpp
)

target_include_directories(ritual
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Dependencies
# find_package(glfw3 REQUIRED)
# find_package(OpenGL REQUIRED)
# target_link_libraries(ritual PUBLIC glfw OpenGL::GL)

# Warnings
if(MSVC)
  target_compile_options(ritual PRIVATE /W4 /permissive-)
else()
  target_compile_options(ritual PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
endif()

# Alias for cleaner usage
add_library(Ritual::Engine ALIAS ritual)