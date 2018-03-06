#Utils

add_library(yuki_utils utils.cpp  token_utils.cpp)
target_include_directories(yuki_utils PRIVATE "${CMAKE_SOURCE_DIR}/src/yuki_script")
