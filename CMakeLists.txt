cmake_minimum_required(VERSION 3.6)
project(AlgolCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lexico.cpp lexico.h)
add_executable(AlgolCompiler ${SOURCE_FILES})