cmake_minimum_required(VERSION 3.13)
project(SafeMatrix)

set(CMAKE_CXX_STANDARD 11)

add_executable(SafeMatrix main.cpp SafeMatrix.h SafeArray.h)