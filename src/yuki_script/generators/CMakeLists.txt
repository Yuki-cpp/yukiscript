#generators

add_library(yuki_stmts_generators generators.cpp op_generators.cpp var_generators.cpp control_generators.cpp function_generators.cpp)
target_include_directories(yuki_stmts_generators PRIVATE "${CMAKE_SOURCE_DIR}/src/yuki_script")

target_link_libraries(yuki_stmts_generators yuki_stmt)
