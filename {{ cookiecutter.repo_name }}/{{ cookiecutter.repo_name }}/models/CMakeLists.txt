cmake_minimum_required(VERSION 3.5)


project(models)


add_library(
    model_lib
    include/mlp.hpp
)


target_include_directories(model_lib PUBLIC include)
set_property(TARGET model_lib PROPERTY CXX_STANDARD 11)


if(BUILD_SHARED_LIBS)
    target_compile_definitions(model_lib PRIVATE MODELS_EXPORTS)
    target_compile_definitions(model_lib INTERFACE MODELS_IMPORTS)
endif()
