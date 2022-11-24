add_library(Graphics Graphics.cpp)

add_executable(Graphics_test Graphics_test.cpp)

target_link_libraries(Graphics_test Graphics)