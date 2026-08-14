add_executable(01_hello_window main.cpp)

target_link_libraries(01_hello_window PRIVATE Ritual::Engine)

# Set assets working dir later
# set_target_properties(01_hello_window PROPERTIES
#     VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/assets"
# )