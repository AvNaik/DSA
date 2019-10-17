cmake_minimum_required (VERSION 3.5)

project (sorting)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file_1 "${source_dir}/insertion_sort.cpp")

file (GLOB source_file_2 "${source_dir}/merge_sort.cpp")

file (GLOB source_file_3 "${source_dir}/quick_sort.cpp")

add_executable (insertion_sort "${source_file_1}")

add_executable (merge_sort "${source_file_2}")

add_executable (quick_sort "${source_file_3}")

