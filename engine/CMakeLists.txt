add_library(ritual STATIC)

target_sources(ritual
  PRIVATE
  src/core/log.cpp
)

target_include_directories(ritual
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(ritual
  PUBLIC
  glfw
  glad::glad
  OpenGL::GL
)

if(MSVC)
  target_compile_options(ritual PRIVATE /W4 /permissive-)
else()
  target_compile_options(ritual PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
endif()

if(RITUAL_BUILD_TESTS)
  add_subdirectory(tests)
endif()

add_library(Ritual::Engine ALIAS ritual)
