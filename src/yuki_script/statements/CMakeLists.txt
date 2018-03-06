#Statements

add_library(yuki_stmt stmts.cpp binary_op_stmts.cpp unary_op_stmts.cpp control_stmts.cpp var_stmts.cpp function_stmts.cpp)

target_include_directories(yuki_stmt PRIVATE "${CMAKE_SOURCE_DIR}/src/yuki_script")
target_link_libraries(yuki_stmt yuki_type_support)
