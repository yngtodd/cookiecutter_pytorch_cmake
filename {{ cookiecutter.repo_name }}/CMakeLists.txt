# [== {{ cookiecutter.full_name }}. Copyright (C) {{ cookiecutter.year }}. GPLv3


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


# [== Project Output Paths
set (MAINFOLDER ${PROJECT_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
set (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")
set (CATCH_DIR "${MAINFOLDER}/external/catch")


# [== Standard libraries
add_subdirectory(data)
add_subdirectory(models)


# [== Add Build Targets
add_executable(train runner/train.cpp)
target_link_libraries(train data models "${TORCH_LIBRARIES}")
set_property(TARGET train PROPERTY CXX_STANDARD 11)


# [== Add Install Targets
if (EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")
    install(DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}" DESTINATION "include")
endif (EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")
