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
include doc/snippets/CMakeFiles/compile_Cwise_floor.dir/depend.make

# Include the progress variables for this target.
include doc/snippets/CMakeFiles/compile_Cwise_floor.dir/progress.make

# Include the compile flags for this target's objects.
include doc/snippets/CMakeFiles/compile_Cwise_floor.dir/flags.make

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/flags.make
doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o: doc/snippets/compile_Cwise_floor.cpp
doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o: ../doc/snippets/Cwise_floor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o -c /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets/compile_Cwise_floor.cpp

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.i"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets/compile_Cwise_floor.cpp > CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.i

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.s"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets/compile_Cwise_floor.cpp -o CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.s

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.requires:

.PHONY : doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.requires

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.provides: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.requires
	$(MAKE) -f doc/snippets/CMakeFiles/compile_Cwise_floor.dir/build.make doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.provides.build
.PHONY : doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.provides

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.provides.build: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o


# Object files for target compile_Cwise_floor
compile_Cwise_floor_OBJECTS = \
"CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o"

# External object files for target compile_Cwise_floor
compile_Cwise_floor_EXTERNAL_OBJECTS =

doc/snippets/compile_Cwise_floor: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o
doc/snippets/compile_Cwise_floor: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/build.make
doc/snippets/compile_Cwise_floor: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable compile_Cwise_floor"
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile_Cwise_floor.dir/link.txt --verbose=$(VERBOSE)
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets && ./compile_Cwise_floor >/home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets/Cwise_floor.out

# Rule to build all files generated by this target.
doc/snippets/CMakeFiles/compile_Cwise_floor.dir/build: doc/snippets/compile_Cwise_floor

.PHONY : doc/snippets/CMakeFiles/compile_Cwise_floor.dir/build

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/requires: doc/snippets/CMakeFiles/compile_Cwise_floor.dir/compile_Cwise_floor.cpp.o.requires

.PHONY : doc/snippets/CMakeFiles/compile_Cwise_floor.dir/requires

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/clean:
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets && $(CMAKE_COMMAND) -P CMakeFiles/compile_Cwise_floor.dir/cmake_clean.cmake
.PHONY : doc/snippets/CMakeFiles/compile_Cwise_floor.dir/clean

doc/snippets/CMakeFiles/compile_Cwise_floor.dir/depend:
	cd /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/doc/snippets /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets /home/pellegrini/Downloads/eigen-eigen-67e894c6cd8f/build/doc/snippets/CMakeFiles/compile_Cwise_floor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/snippets/CMakeFiles/compile_Cwise_floor.dir/depend

