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
include tests/CMakeFiles/TestAABB.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestAABB.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestAABB.dir/flags.make

tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o: tests/CMakeFiles/TestAABB.dir/flags.make
tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o: ../tests/geometry/TestAABB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestAABB.cpp

tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestAABB.cpp > CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.i

tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestAABB.cpp -o CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.s

tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.requires

tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.provides: tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestAABB.dir/build.make tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.provides

tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.provides.build: tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o


# Object files for target TestAABB
TestAABB_OBJECTS = \
"CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o"

# External object files for target TestAABB
TestAABB_EXTERNAL_OBJECTS =

tests/TestAABB: tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o
tests/TestAABB: tests/CMakeFiles/TestAABB.dir/build.make
tests/TestAABB: nsxlib/libnsx.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestAABB: externals/c-blosc/blosc/libblosc.a
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestAABB: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestAABB: /usr/local/lib/libgsl.so
tests/TestAABB: /usr/local/lib/libgslcblas.so
tests/TestAABB: tests/CMakeFiles/TestAABB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestAABB"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestAABB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestAABB.dir/build: tests/TestAABB

.PHONY : tests/CMakeFiles/TestAABB.dir/build

tests/CMakeFiles/TestAABB.dir/requires: tests/CMakeFiles/TestAABB.dir/geometry/TestAABB.cpp.o.requires

.PHONY : tests/CMakeFiles/TestAABB.dir/requires

tests/CMakeFiles/TestAABB.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestAABB.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestAABB.dir/clean

tests/CMakeFiles/TestAABB.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestAABB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestAABB.dir/depend
