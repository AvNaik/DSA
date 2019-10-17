cmake_minimum_required (VERSION 3.5)

project (linkedlist)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file_1 "${source_dir}/insertion.cpp")

file (GLOB source_file_2 "${source_dir}/rotate.cpp")

file (GLOB source_file_3 "${source_dir}/insert.cpp")

file (GLOB source_file_4 "${source_dir}/reverse.cpp")

file (GLOB source_file_5 "${source_dir}/reorder.cpp")

add_executable (dni "${source_file_1}")

add_executable (rotate "${source_file_2}") 

add_executable (insert "${source_file_3}")

add_executable (reverse "${source_file_4}")

add_executable (reorder "${source_file_5}")
