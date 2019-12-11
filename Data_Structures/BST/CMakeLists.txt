cmake_minimum_required (VERSION 3.5)

project (bst)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")

set (include_dir "${PROJECT_SOURCE_DIR}/inc/")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file "${source_dir}/*.cpp")

include_directories (${include_dir})

add_executable (mf "${source_file}")
