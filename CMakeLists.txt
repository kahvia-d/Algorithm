cmake_minimum_required(VERSION 3.24)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)
# 指定可执行程序输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(AcWing3375 Acwing/graduate/AcWing3375.cpp)

