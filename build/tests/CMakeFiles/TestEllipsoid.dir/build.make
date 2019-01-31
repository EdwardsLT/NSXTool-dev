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
include tests/CMakeFiles/TestEllipsoid.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestEllipsoid.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestEllipsoid.dir/flags.make

tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o: tests/CMakeFiles/TestEllipsoid.dir/flags.make
tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o: ../tests/geometry/TestEllipsoid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestEllipsoid.cpp

tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestEllipsoid.cpp > CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.i

tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/geometry/TestEllipsoid.cpp -o CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.s

tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.requires

tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.provides: tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestEllipsoid.dir/build.make tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.provides

tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.provides.build: tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o


# Object files for target TestEllipsoid
TestEllipsoid_OBJECTS = \
"CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o"

# External object files for target TestEllipsoid
TestEllipsoid_EXTERNAL_OBJECTS =

tests/TestEllipsoid: tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o
tests/TestEllipsoid: tests/CMakeFiles/TestEllipsoid.dir/build.make
tests/TestEllipsoid: nsxlib/libnsx.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestEllipsoid: externals/c-blosc/blosc/libblosc.a
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestEllipsoid: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestEllipsoid: /usr/local/lib/libgsl.so
tests/TestEllipsoid: /usr/local/lib/libgslcblas.so
tests/TestEllipsoid: tests/CMakeFiles/TestEllipsoid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestEllipsoid"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestEllipsoid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestEllipsoid.dir/build: tests/TestEllipsoid

.PHONY : tests/CMakeFiles/TestEllipsoid.dir/build

tests/CMakeFiles/TestEllipsoid.dir/requires: tests/CMakeFiles/TestEllipsoid.dir/geometry/TestEllipsoid.cpp.o.requires

.PHONY : tests/CMakeFiles/TestEllipsoid.dir/requires

tests/CMakeFiles/TestEllipsoid.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestEllipsoid.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestEllipsoid.dir/clean

tests/CMakeFiles/TestEllipsoid.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestEllipsoid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestEllipsoid.dir/depend
