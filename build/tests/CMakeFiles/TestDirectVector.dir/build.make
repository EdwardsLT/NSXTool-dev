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
include tests/CMakeFiles/TestDirectVector.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestDirectVector.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestDirectVector.dir/flags.make

tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o: tests/CMakeFiles/TestDirectVector.dir/flags.make
tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o: ../tests/geometry/TestDirectVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestDirectVector.cpp

tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestDirectVector.cpp > CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.i

tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestDirectVector.cpp -o CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.s

tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.requires

tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.provides: tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestDirectVector.dir/build.make tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.provides

tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.provides.build: tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o


# Object files for target TestDirectVector
TestDirectVector_OBJECTS = \
"CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o"

# External object files for target TestDirectVector
TestDirectVector_EXTERNAL_OBJECTS =

tests/TestDirectVector: tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o
tests/TestDirectVector: tests/CMakeFiles/TestDirectVector.dir/build.make
tests/TestDirectVector: nsxlib/libnsx.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestDirectVector: externals/c-blosc/blosc/libblosc.a
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestDirectVector: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestDirectVector: /usr/local/lib/libgsl.so
tests/TestDirectVector: /usr/local/lib/libgslcblas.so
tests/TestDirectVector: tests/CMakeFiles/TestDirectVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestDirectVector"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestDirectVector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestDirectVector.dir/build: tests/TestDirectVector

.PHONY : tests/CMakeFiles/TestDirectVector.dir/build

tests/CMakeFiles/TestDirectVector.dir/requires: tests/CMakeFiles/TestDirectVector.dir/geometry/TestDirectVector.cpp.o.requires

.PHONY : tests/CMakeFiles/TestDirectVector.dir/requires

tests/CMakeFiles/TestDirectVector.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestDirectVector.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestDirectVector.dir/clean

tests/CMakeFiles/TestDirectVector.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestDirectVector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestDirectVector.dir/depend

