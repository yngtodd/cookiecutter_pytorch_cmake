cmake_minimum_required(VERSION 3.5)


project(data)


add_library(
    data_lib
    include/data.hpp
    src/data.cpp
)


target_include_directories(data_lib PUBLIC include)
target_include_directories(data_lib PRIVATE src)
set_property(TARGET data_lib PROPERTY CXX_STANDARD 11)


if(BUILD_SHARED_LIBS)
    target_compile_definitions(data_lib PRIVATE DATA_EXPORTS)
    target_compile_definitions(data_lib INTERFACE DATA_IMPORTS)
endif()
