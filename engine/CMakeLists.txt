add_library(ritual STATIC
  src/core/log.cpp
)

target_include_directories(ritual PUBLIC include)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(ritual PUBLIC
  glfw
  glad::glad
  OpenGL::GL
)

add_library(Ritual::engine ALIAS ritual)

if(RITUAL_BUILD_TESTS)
  add_subdirectory(tests)
endif()
