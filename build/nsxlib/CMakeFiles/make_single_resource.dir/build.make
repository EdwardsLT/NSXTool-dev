# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/lewisedwards/bin/nsxtool-dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lewisedwards/bin/nsxtool-dev/build

# Include any dependencies generated for this target.
include nsxlib/CMakeFiles/make_single_resource.dir/depend.make

# Include the progress variables for this target.
include nsxlib/CMakeFiles/make_single_resource.dir/progress.make

# Include the compile flags for this target's objects.
include nsxlib/CMakeFiles/make_single_resource.dir/flags.make

nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o: nsxlib/CMakeFiles/make_single_resource.dir/flags.make
nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o: ../cmake/scripts/make_single_resource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/cmake/scripts/make_single_resource.cpp

nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/cmake/scripts/make_single_resource.cpp > CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.i

nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/cmake/scripts/make_single_resource.cpp -o CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.s

nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.requires:

.PHONY : nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.requires

nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.provides: nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.requires
	$(MAKE) -f nsxlib/CMakeFiles/make_single_resource.dir/build.make nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.provides.build
.PHONY : nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.provides

nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.provides.build: nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o


# Object files for target make_single_resource
make_single_resource_OBJECTS = \
"CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o"

# External object files for target make_single_resource
make_single_resource_EXTERNAL_OBJECTS =

nsxlib/make_single_resource: nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o
nsxlib/make_single_resource: nsxlib/CMakeFiles/make_single_resource.dir/build.make
nsxlib/make_single_resource: nsxlib/CMakeFiles/make_single_resource.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable make_single_resource"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make_single_resource.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
nsxlib/CMakeFiles/make_single_resource.dir/build: nsxlib/make_single_resource

.PHONY : nsxlib/CMakeFiles/make_single_resource.dir/build

nsxlib/CMakeFiles/make_single_resource.dir/requires: nsxlib/CMakeFiles/make_single_resource.dir/__/cmake/scripts/make_single_resource.cpp.o.requires

.PHONY : nsxlib/CMakeFiles/make_single_resource.dir/requires

nsxlib/CMakeFiles/make_single_resource.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && $(CMAKE_COMMAND) -P CMakeFiles/make_single_resource.dir/cmake_clean.cmake
.PHONY : nsxlib/CMakeFiles/make_single_resource.dir/clean

nsxlib/CMakeFiles/make_single_resource.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/nsxlib /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/nsxlib /home/lewisedwards/bin/nsxtool-dev/build/nsxlib/CMakeFiles/make_single_resource.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : nsxlib/CMakeFiles/make_single_resource.dir/depend

