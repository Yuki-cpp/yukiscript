#interpreter

add_executable(yuki_script main.cpp)
target_include_directories(yuki_script PRIVATE "${CMAKE_SOURCE_DIR}/src/yuki_script")

target_link_libraries(yuki_script yuki_utils yuki_context yuki_stmts_generators)
