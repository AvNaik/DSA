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
CMAKE_SOURCE_DIR = /home/avanaik/Study/DSA/Data_Structures/Strings/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/avanaik/Study/DSA/Data_Structures/Strings/C++

# Include any dependencies generated for this target.
include CMakeFiles/remove_space.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/remove_space.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/remove_space.dir/flags.make

CMakeFiles/remove_space.dir/src/remove_space.cpp.o: CMakeFiles/remove_space.dir/flags.make
CMakeFiles/remove_space.dir/src/remove_space.cpp.o: src/remove_space.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/avanaik/Study/DSA/Data_Structures/Strings/C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/remove_space.dir/src/remove_space.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/remove_space.dir/src/remove_space.cpp.o -c /home/avanaik/Study/DSA/Data_Structures/Strings/C++/src/remove_space.cpp

CMakeFiles/remove_space.dir/src/remove_space.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/remove_space.dir/src/remove_space.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/avanaik/Study/DSA/Data_Structures/Strings/C++/src/remove_space.cpp > CMakeFiles/remove_space.dir/src/remove_space.cpp.i

CMakeFiles/remove_space.dir/src/remove_space.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/remove_space.dir/src/remove_space.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/avanaik/Study/DSA/Data_Structures/Strings/C++/src/remove_space.cpp -o CMakeFiles/remove_space.dir/src/remove_space.cpp.s

CMakeFiles/remove_space.dir/src/remove_space.cpp.o.requires:

.PHONY : CMakeFiles/remove_space.dir/src/remove_space.cpp.o.requires

CMakeFiles/remove_space.dir/src/remove_space.cpp.o.provides: CMakeFiles/remove_space.dir/src/remove_space.cpp.o.requires
	$(MAKE) -f CMakeFiles/remove_space.dir/build.make CMakeFiles/remove_space.dir/src/remove_space.cpp.o.provides.build
.PHONY : CMakeFiles/remove_space.dir/src/remove_space.cpp.o.provides

CMakeFiles/remove_space.dir/src/remove_space.cpp.o.provides.build: CMakeFiles/remove_space.dir/src/remove_space.cpp.o


# Object files for target remove_space
remove_space_OBJECTS = \
"CMakeFiles/remove_space.dir/src/remove_space.cpp.o"

# External object files for target remove_space
remove_space_EXTERNAL_OBJECTS =

remove_space: CMakeFiles/remove_space.dir/src/remove_space.cpp.o
remove_space: CMakeFiles/remove_space.dir/build.make
remove_space: CMakeFiles/remove_space.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/avanaik/Study/DSA/Data_Structures/Strings/C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable remove_space"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/remove_space.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/remove_space.dir/build: remove_space

.PHONY : CMakeFiles/remove_space.dir/build

CMakeFiles/remove_space.dir/requires: CMakeFiles/remove_space.dir/src/remove_space.cpp.o.requires

.PHONY : CMakeFiles/remove_space.dir/requires

CMakeFiles/remove_space.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/remove_space.dir/cmake_clean.cmake
.PHONY : CMakeFiles/remove_space.dir/clean

CMakeFiles/remove_space.dir/depend:
	cd /home/avanaik/Study/DSA/Data_Structures/Strings/C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/avanaik/Study/DSA/Data_Structures/Strings/C++ /home/avanaik/Study/DSA/Data_Structures/Strings/C++ /home/avanaik/Study/DSA/Data_Structures/Strings/C++ /home/avanaik/Study/DSA/Data_Structures/Strings/C++ /home/avanaik/Study/DSA/Data_Structures/Strings/C++/CMakeFiles/remove_space.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/remove_space.dir/depend

