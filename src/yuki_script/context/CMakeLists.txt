#context

add_library(yuki_context context.cpp context_stack.cpp)
target_include_directories(yuki_context PRIVATE "${CMAKE_SOURCE_DIR}/src/yuki_script")
