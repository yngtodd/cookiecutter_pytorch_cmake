cmake_minimum_required(VERSION 3.5)

project(models)

add_library(
    model_lib
    include/mlp.hpp
    src/mlp.cpp
)

target_include_directories(model_lib PUBLIC include)
target_include_directories(model_lib PUBLIC src)
set_property(TARGET model_lib PROPERTY CXX_STANDARD 14)
target_link_libraries(model_lib "${TORCH_LIBRARIES}")
