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
include apps/simulate/CMakeFiles/simulate.dir/depend.make

# Include the progress variables for this target.
include apps/simulate/CMakeFiles/simulate.dir/progress.make

# Include the compile flags for this target's objects.
include apps/simulate/CMakeFiles/simulate.dir/flags.make

apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o: apps/simulate/CMakeFiles/simulate.dir/flags.make
apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o: ../apps/simulate/simulate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulate.dir/simulate.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/apps/simulate/simulate.cpp

apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulate.dir/simulate.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/apps/simulate/simulate.cpp > CMakeFiles/simulate.dir/simulate.cpp.i

apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulate.dir/simulate.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/apps/simulate/simulate.cpp -o CMakeFiles/simulate.dir/simulate.cpp.s

apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.requires:

.PHONY : apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.requires

apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.provides: apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.requires
	$(MAKE) -f apps/simulate/CMakeFiles/simulate.dir/build.make apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.provides.build
.PHONY : apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.provides

apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.provides.build: apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o


# Object files for target simulate
simulate_OBJECTS = \
"CMakeFiles/simulate.dir/simulate.cpp.o"

# External object files for target simulate
simulate_EXTERNAL_OBJECTS =

apps/simulate/simulate: apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o
apps/simulate/simulate: apps/simulate/CMakeFiles/simulate.dir/build.make
apps/simulate/simulate: nsxlib/libnsx.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libpthread.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libsz.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libz.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libdl.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libm.so
apps/simulate/simulate: externals/c-blosc/blosc/libblosc.a
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libz.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libfftw3.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
apps/simulate/simulate: /usr/lib/x86_64-linux-gnu/libtiff.so
apps/simulate/simulate: /usr/local/lib/libgsl.so
apps/simulate/simulate: /usr/local/lib/libgslcblas.so
apps/simulate/simulate: apps/simulate/CMakeFiles/simulate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simulate"
	cd /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simulate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/simulate/CMakeFiles/simulate.dir/build: apps/simulate/simulate

.PHONY : apps/simulate/CMakeFiles/simulate.dir/build

apps/simulate/CMakeFiles/simulate.dir/requires: apps/simulate/CMakeFiles/simulate.dir/simulate.cpp.o.requires

.PHONY : apps/simulate/CMakeFiles/simulate.dir/requires

apps/simulate/CMakeFiles/simulate.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate && $(CMAKE_COMMAND) -P CMakeFiles/simulate.dir/cmake_clean.cmake
.PHONY : apps/simulate/CMakeFiles/simulate.dir/clean

apps/simulate/CMakeFiles/simulate.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/apps/simulate /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate /home/lewisedwards/bin/nsxtool-dev/build/apps/simulate/CMakeFiles/simulate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/simulate/CMakeFiles/simulate.dir/depend

