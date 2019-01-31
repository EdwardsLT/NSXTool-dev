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
include tests/CMakeFiles/TestTransAxis.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestTransAxis.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestTransAxis.dir/flags.make

tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o: tests/CMakeFiles/TestTransAxis.dir/flags.make
tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o: ../tests/instrument/TestTransAxis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/instrument/TestTransAxis.cpp

tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/instrument/TestTransAxis.cpp > CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.i

tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/instrument/TestTransAxis.cpp -o CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.s

tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.requires

tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.provides: tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestTransAxis.dir/build.make tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.provides

tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.provides.build: tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o


# Object files for target TestTransAxis
TestTransAxis_OBJECTS = \
"CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o"

# External object files for target TestTransAxis
TestTransAxis_EXTERNAL_OBJECTS =

tests/TestTransAxis: tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o
tests/TestTransAxis: tests/CMakeFiles/TestTransAxis.dir/build.make
tests/TestTransAxis: nsxlib/libnsx.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestTransAxis: externals/c-blosc/blosc/libblosc.a
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestTransAxis: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestTransAxis: /usr/local/lib/libgsl.so
tests/TestTransAxis: /usr/local/lib/libgslcblas.so
tests/TestTransAxis: tests/CMakeFiles/TestTransAxis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestTransAxis"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestTransAxis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestTransAxis.dir/build: tests/TestTransAxis

.PHONY : tests/CMakeFiles/TestTransAxis.dir/build

tests/CMakeFiles/TestTransAxis.dir/requires: tests/CMakeFiles/TestTransAxis.dir/instrument/TestTransAxis.cpp.o.requires

.PHONY : tests/CMakeFiles/TestTransAxis.dir/requires

tests/CMakeFiles/TestTransAxis.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestTransAxis.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestTransAxis.dir/clean

tests/CMakeFiles/TestTransAxis.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestTransAxis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestTransAxis.dir/depend
