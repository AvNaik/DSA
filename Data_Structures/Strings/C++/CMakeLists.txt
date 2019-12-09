cmake_minimum_required (VERSION 3.5)

project (strings)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file_1 "${source_dir}/reverse.cpp")

file (GLOB source_file_2 "${source_dir}/pangram.cpp")

file(GLOB source_file_3 "${source_dir}/remove_space.cpp")

file(GLOB source_file_4 "${source_dir}/anagram.cpp")

file (GLOB source_file_5 "${source_dir}/sort.cpp")

file(GLOB source_file_6 "${source_dir}/vectors.cpp")

file (GLOB source_file_7 "${source_dir}/palindrome.cpp")

file (GLOB source_file_8 "${source_dir}/occurance.cpp")

file(GLOB source_file_9 "${source_dir}/lexi.cpp")

add_executable (reverse "${source_file_1}")

add_executable (pangram "${source_file_2}")

add_executable (remove_space "${source_file_3}")

add_executable (anagram "${source_file_4}")

add_executable (sorted "${source_file_5}")

add_executable (vectors "${source_file_6}")

add_executable (palindrome "${source_file_7}")

add_executable (occurance "${source_file_8}")

add_executable (lexi "${source_file_9}")
