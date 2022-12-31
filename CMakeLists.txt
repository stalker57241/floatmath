cmake_minimum_required(VERSION 3.10.0)

include_directories(include/)

project(floatmath)
add_library(floatmath src/floatmath/floatmath.c src/floatmath/floatops.c)

project(floataddtest)
add_executable(floataddtest src/fm_add_test.c)
target_link_libraries(floataddtest floatmath)

project(floatsubstracttest)
add_executable(floatsubstracttest src/fm_substract_test.c)
target_link_libraries(floatsubstracttest floatmath)

project(floatmultiplytest)
add_executable(floatmultiplytest src/fm_multiply_test.c)
target_link_libraries(floatmultiplytest floatmath)

project(floatdividetest)
add_executable(floatdividetest src/fm_divide_test.c)
target_link_libraries(floatdividetest floatmath)
