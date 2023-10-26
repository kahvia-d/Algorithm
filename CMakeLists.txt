cmake_minimum_required(VERSION 3.24)
#指定cmake工程名
project(algorithm)

#c++版本
set(CMAKE_CXX_STANDARD 14)
# 指定可执行程序输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(AcWing3375 Acwing/graduate/1/AcWing3375.cpp)
add_executable(AcWing3376 Acwing/graduate/1/AcWing3376.cpp)
add_executable(AcWing3373 Acwing/graduate/1/AcWing3373.cpp)
add_executable(AcWing3374 Acwing/graduate/1/AcWing3374.cpp)
add_executable(AcWing3607 Acwing/graduate/2/AcWing3607.cpp)
add_executable(AcWing3573 Acwing/graduate/2/AcWing3573.cpp)
add_executable(AcWing3302 Acwing/graduate/3/AcWing3302.cpp)
add_executable(AcWing3302_SuffixExpression Acwing/graduate/3/AcWing3302_SuffixExpression.cpp)
add_executable(AcWing18 Acwing/graduate/4/AcWing18.cpp)
add_executable(AcWing3766 Acwing/graduate/4/AcWing3766.cpp)