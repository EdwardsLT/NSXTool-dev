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
CMAKE_SOURCE_DIR = /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build

# Include any dependencies generated for this target.
include test/CMakeFiles/sparse_basic_7.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/sparse_basic_7.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/sparse_basic_7.dir/flags.make

test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o: test/CMakeFiles/sparse_basic_7.dir/flags.make
test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o: ../test/sparse_basic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o -c /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/test/sparse_basic.cpp

test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.i"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/test/sparse_basic.cpp > CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.i

test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.s"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/test/sparse_basic.cpp -o CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.s

test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.requires:

.PHONY : test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.requires

test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.provides: test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/sparse_basic_7.dir/build.make test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.provides.build
.PHONY : test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.provides

test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.provides.build: test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o


# Object files for target sparse_basic_7
sparse_basic_7_OBJECTS = \
"CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o"

# External object files for target sparse_basic_7
sparse_basic_7_EXTERNAL_OBJECTS =

test/sparse_basic_7: test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o
test/sparse_basic_7: test/CMakeFiles/sparse_basic_7.dir/build.make
test/sparse_basic_7: test/CMakeFiles/sparse_basic_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sparse_basic_7"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sparse_basic_7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/sparse_basic_7.dir/build: test/sparse_basic_7

.PHONY : test/CMakeFiles/sparse_basic_7.dir/build

test/CMakeFiles/sparse_basic_7.dir/requires: test/CMakeFiles/sparse_basic_7.dir/sparse_basic.cpp.o.requires

.PHONY : test/CMakeFiles/sparse_basic_7.dir/requires

test/CMakeFiles/sparse_basic_7.dir/clean:
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test && $(CMAKE_COMMAND) -P CMakeFiles/sparse_basic_7.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/sparse_basic_7.dir/clean

test/CMakeFiles/sparse_basic_7.dir/depend:
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/test /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/test/CMakeFiles/sparse_basic_7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/sparse_basic_7.dir/depend

