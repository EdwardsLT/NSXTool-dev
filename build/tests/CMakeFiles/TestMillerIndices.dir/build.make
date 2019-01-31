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
include tests/CMakeFiles/TestMillerIndices.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestMillerIndices.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestMillerIndices.dir/flags.make

tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o: tests/CMakeFiles/TestMillerIndices.dir/flags.make
tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o: ../tests/geometry/TestMillerIndices.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestMillerIndices.cpp

tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestMillerIndices.cpp > CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.i

tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestMillerIndices.cpp -o CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.s

tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.requires

tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.provides: tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestMillerIndices.dir/build.make tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.provides

tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.provides.build: tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o


# Object files for target TestMillerIndices
TestMillerIndices_OBJECTS = \
"CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o"

# External object files for target TestMillerIndices
TestMillerIndices_EXTERNAL_OBJECTS =

tests/TestMillerIndices: tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o
tests/TestMillerIndices: tests/CMakeFiles/TestMillerIndices.dir/build.make
tests/TestMillerIndices: nsxlib/libnsx.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestMillerIndices: externals/c-blosc/blosc/libblosc.a
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestMillerIndices: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestMillerIndices: /usr/local/lib/libgsl.so
tests/TestMillerIndices: /usr/local/lib/libgslcblas.so
tests/TestMillerIndices: tests/CMakeFiles/TestMillerIndices.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestMillerIndices"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestMillerIndices.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestMillerIndices.dir/build: tests/TestMillerIndices

.PHONY : tests/CMakeFiles/TestMillerIndices.dir/build

tests/CMakeFiles/TestMillerIndices.dir/requires: tests/CMakeFiles/TestMillerIndices.dir/geometry/TestMillerIndices.cpp.o.requires

.PHONY : tests/CMakeFiles/TestMillerIndices.dir/requires

tests/CMakeFiles/TestMillerIndices.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestMillerIndices.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestMillerIndices.dir/clean

tests/CMakeFiles/TestMillerIndices.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestMillerIndices.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestMillerIndices.dir/depend

