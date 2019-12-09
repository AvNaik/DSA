cmake_minimum_required (VERSION 3.5)

project (binarytrees)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file_1 "${source_dir}/insert.cpp")

add_executable (insert "${source_file_1}")



