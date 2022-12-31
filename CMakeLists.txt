cmake_minimum_required(VERSION 3.10.0)

include_directories(include/)

project(FloatMath)
add_library(FloatMath src/floatmath/floatmath.c src/floatmath/floatops.c)

project(FloatAddTest)
add_executable(FloatAddTest src/fm_add_test.c)
target_link_libraries(FloatAddTest FloatMath)

project(FloatSubstractTest)
add_executable(FloatSubstractTest src/fm_substract_test.c)
target_link_libraries(FloatSubstractTest FloatMath)

project(FloatMultiplyTest)
add_executable(FloatMultiplyTest src/fm_multiply_test.c)
target_link_libraries(FloatMultiplyTest FloatMath)

project(FloatDivideTest)
add_executable(FloatDivideTest src/fm_divide_test.c)
target_link_libraries(FloatDivideTest FloatMath)
