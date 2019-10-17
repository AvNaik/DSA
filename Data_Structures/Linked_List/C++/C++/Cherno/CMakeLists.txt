cmake_minimum_required (VERSION 3.5)

project (test2392)

set (source_dir_1 "${PROJECT_SOURCE_DIR}/src/Prog_1")

set (include_dir_1 "{$PROJECT_SOURCE-DIR}/src/Prog_1/include")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags} -Wall -Werror -std=c++17")

file (GLOB source_files_1 "${source_dir_1}/MainP.cpp" "${include_dir_1}/*.cpp")

add_executable (t "${source_files_1}")
