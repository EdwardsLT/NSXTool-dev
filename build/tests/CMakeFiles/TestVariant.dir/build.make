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
include tests/CMakeFiles/TestVariant.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestVariant.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestVariant.dir/flags.make

tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o: tests/CMakeFiles/TestVariant.dir/flags.make
tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o: ../tests/stl/TestVariant.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/stl/TestVariant.cpp

tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/stl/TestVariant.cpp > CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.i

tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/stl/TestVariant.cpp -o CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.s

tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.requires

tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.provides: tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestVariant.dir/build.make tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.provides

tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.provides.build: tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o


# Object files for target TestVariant
TestVariant_OBJECTS = \
"CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o"

# External object files for target TestVariant
TestVariant_EXTERNAL_OBJECTS =

tests/TestVariant: tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o
tests/TestVariant: tests/CMakeFiles/TestVariant.dir/build.make
tests/TestVariant: nsxlib/libnsx.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestVariant: externals/c-blosc/blosc/libblosc.a
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestVariant: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestVariant: /usr/local/lib/libgsl.so
tests/TestVariant: /usr/local/lib/libgslcblas.so
tests/TestVariant: tests/CMakeFiles/TestVariant.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestVariant"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestVariant.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestVariant.dir/build: tests/TestVariant

.PHONY : tests/CMakeFiles/TestVariant.dir/build

tests/CMakeFiles/TestVariant.dir/requires: tests/CMakeFiles/TestVariant.dir/stl/TestVariant.cpp.o.requires

.PHONY : tests/CMakeFiles/TestVariant.dir/requires

tests/CMakeFiles/TestVariant.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestVariant.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestVariant.dir/clean

tests/CMakeFiles/TestVariant.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestVariant.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestVariant.dir/depend
