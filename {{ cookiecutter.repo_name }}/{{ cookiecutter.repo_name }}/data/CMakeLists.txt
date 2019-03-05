cmake_minimum_required(VERSION 3.5)

project(data)

add_library(
    data_lib
    include/mnist.hpp
    src/mnist.cpp
)

target_include_directories(data_lib PUBLIC include)
target_include_directories(data_lib PRIVATE src)
set_property(TARGET data_lib PROPERTY CXX_STANDARD 14)
