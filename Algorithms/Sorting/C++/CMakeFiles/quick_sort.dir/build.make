# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/avanaik/Study/Algorithms/Sorting/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/avanaik/Study/Algorithms/Sorting/C++

# Include any dependencies generated for this target.
include CMakeFiles/quick_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quick_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quick_sort.dir/flags.make

CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o: CMakeFiles/quick_sort.dir/flags.make
CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o: src/quick_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/avanaik/Study/Algorithms/Sorting/C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o -c /home/avanaik/Study/Algorithms/Sorting/C++/src/quick_sort.cpp

CMakeFiles/quick_sort.dir/src/quick_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quick_sort.dir/src/quick_sort.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/avanaik/Study/Algorithms/Sorting/C++/src/quick_sort.cpp > CMakeFiles/quick_sort.dir/src/quick_sort.cpp.i

CMakeFiles/quick_sort.dir/src/quick_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quick_sort.dir/src/quick_sort.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/avanaik/Study/Algorithms/Sorting/C++/src/quick_sort.cpp -o CMakeFiles/quick_sort.dir/src/quick_sort.cpp.s

CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.requires:

.PHONY : CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.requires

CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.provides: CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.requires
	$(MAKE) -f CMakeFiles/quick_sort.dir/build.make CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.provides.build
.PHONY : CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.provides

CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.provides.build: CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o


# Object files for target quick_sort
quick_sort_OBJECTS = \
"CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o"

# External object files for target quick_sort
quick_sort_EXTERNAL_OBJECTS =

quick_sort: CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o
quick_sort: CMakeFiles/quick_sort.dir/build.make
quick_sort: CMakeFiles/quick_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/avanaik/Study/Algorithms/Sorting/C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quick_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quick_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quick_sort.dir/build: quick_sort

.PHONY : CMakeFiles/quick_sort.dir/build

CMakeFiles/quick_sort.dir/requires: CMakeFiles/quick_sort.dir/src/quick_sort.cpp.o.requires

.PHONY : CMakeFiles/quick_sort.dir/requires

CMakeFiles/quick_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quick_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quick_sort.dir/clean

CMakeFiles/quick_sort.dir/depend:
	cd /home/avanaik/Study/Algorithms/Sorting/C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/avanaik/Study/Algorithms/Sorting/C++ /home/avanaik/Study/Algorithms/Sorting/C++ /home/avanaik/Study/Algorithms/Sorting/C++ /home/avanaik/Study/Algorithms/Sorting/C++ /home/avanaik/Study/Algorithms/Sorting/C++/CMakeFiles/quick_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quick_sort.dir/depend
