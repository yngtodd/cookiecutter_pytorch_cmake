# [== {{ cookiecutter.full_name }}. Copyright (C) {{ cookiecutter.year }}. MIT


# [== Project Properties
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project ({{ cookiecutter.repo_name }})
set (APPLICATION_NAME "{{ cookiecutter.project_name }}")
set (APPLICATION_CODENAME "${PROJECT_NAME}")
set (APPLICATION_COPYRIGHT_YEARS "{{ cookiecutter.year }}")
set (APPLICATION_VERSION_MAJOR 0)
set (APPLICATION_VERSION_MINOR 1)
set (APPLICATION_VERSION_PATCH 0)
set (APPLICATION_VERSION_TYPE SNAPSHOT)
set (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}-${APPLICATION_VERSION_TYPE}")


# [== Requirements
find_package(Torch REQUIRED)
include_directories(${TORCH_INCLUDE_DIRS})


# [== Debugging Options
set (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release


# [== Standard libraries
add_subdirectory(data)
add_subdirectory(models)


# [== Add Build Targets
add_executable(train runner/train.cpp)
target_link_libraries(train data_lib model_lib "${TORCH_LIBRARIES}")
set_property(TARGET train PROPERTY CXX_STANDARD 14)
