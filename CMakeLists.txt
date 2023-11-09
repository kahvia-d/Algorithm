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
add_executable(AcWing3786 Acwing/graduate/5/AcWing3786.cpp)
add_executable(AcWing3765 Acwing/graduate/5/AcWing3765.cpp)
add_executable(AcWing148 Acwing/graduate/6/AcWing148.cpp)
add_executable(AcWing149 Acwing/graduate/6/AcWing149.cpp)
add_executable(AcWing848 Acwing/graduate/7/AcWing848.cpp)
add_executable(AcWing848_dfs Acwing/graduate/7/AcWing848_dfs.cpp)
add_executable(AcWing858 Acwing/graduate/8/AcWing858.cpp)