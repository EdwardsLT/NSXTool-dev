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
include nsxlib/CMakeFiles/update_resources.dir/depend.make

# Include the progress variables for this target.
include nsxlib/CMakeFiles/update_resources.dir/progress.make

# Include the compile flags for this target's objects.
include nsxlib/CMakeFiles/update_resources.dir/flags.make

nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o: nsxlib/CMakeFiles/update_resources.dir/flags.make
nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o: ../cmake/scripts/update_resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/cmake/scripts/update_resources.cpp

nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/cmake/scripts/update_resources.cpp > CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.i

nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/cmake/scripts/update_resources.cpp -o CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.s

nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.requires:

.PHONY : nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.requires

nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.provides: nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.requires
	$(MAKE) -f nsxlib/CMakeFiles/update_resources.dir/build.make nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.provides.build
.PHONY : nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.provides

nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.provides.build: nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o


# Object files for target update_resources
update_resources_OBJECTS = \
"CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o"

# External object files for target update_resources
update_resources_EXTERNAL_OBJECTS =

nsxlib/update_resources: nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o
nsxlib/update_resources: nsxlib/CMakeFiles/update_resources.dir/build.make
nsxlib/update_resources: nsxlib/CMakeFiles/update_resources.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable update_resources"
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/update_resources.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
nsxlib/CMakeFiles/update_resources.dir/build: nsxlib/update_resources

.PHONY : nsxlib/CMakeFiles/update_resources.dir/build

nsxlib/CMakeFiles/update_resources.dir/requires: nsxlib/CMakeFiles/update_resources.dir/__/cmake/scripts/update_resources.cpp.o.requires

.PHONY : nsxlib/CMakeFiles/update_resources.dir/requires

nsxlib/CMakeFiles/update_resources.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/nsxlib && $(CMAKE_COMMAND) -P CMakeFiles/update_resources.dir/cmake_clean.cmake
.PHONY : nsxlib/CMakeFiles/update_resources.dir/clean

nsxlib/CMakeFiles/update_resources.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/nsxlib /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/nsxlib /home/lewisedwards/bin/nsxtool-dev/build/nsxlib/CMakeFiles/update_resources.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : nsxlib/CMakeFiles/update_resources.dir/depend

