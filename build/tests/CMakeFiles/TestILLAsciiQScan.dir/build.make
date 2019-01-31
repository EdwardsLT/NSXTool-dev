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
include tests/CMakeFiles/TestILLAsciiQScan.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestILLAsciiQScan.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestILLAsciiQScan.dir/flags.make

tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o: tests/CMakeFiles/TestILLAsciiQScan.dir/flags.make
tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o: ../tests/data/TestILLAsciiQScan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/data/TestILLAsciiQScan.cpp

tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/data/TestILLAsciiQScan.cpp > CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.i

tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/data/TestILLAsciiQScan.cpp -o CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.s

tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.requires

tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.provides: tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestILLAsciiQScan.dir/build.make tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.provides

tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.provides.build: tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o


# Object files for target TestILLAsciiQScan
TestILLAsciiQScan_OBJECTS = \
"CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o"

# External object files for target TestILLAsciiQScan
TestILLAsciiQScan_EXTERNAL_OBJECTS =

tests/TestILLAsciiQScan: tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o
tests/TestILLAsciiQScan: tests/CMakeFiles/TestILLAsciiQScan.dir/build.make
tests/TestILLAsciiQScan: nsxlib/libnsx.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestILLAsciiQScan: externals/c-blosc/blosc/libblosc.a
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestILLAsciiQScan: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestILLAsciiQScan: /usr/local/lib/libgsl.so
tests/TestILLAsciiQScan: /usr/local/lib/libgslcblas.so
tests/TestILLAsciiQScan: tests/CMakeFiles/TestILLAsciiQScan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestILLAsciiQScan"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestILLAsciiQScan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestILLAsciiQScan.dir/build: tests/TestILLAsciiQScan

.PHONY : tests/CMakeFiles/TestILLAsciiQScan.dir/build

tests/CMakeFiles/TestILLAsciiQScan.dir/requires: tests/CMakeFiles/TestILLAsciiQScan.dir/data/TestILLAsciiQScan.cpp.o.requires

.PHONY : tests/CMakeFiles/TestILLAsciiQScan.dir/requires

tests/CMakeFiles/TestILLAsciiQScan.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestILLAsciiQScan.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestILLAsciiQScan.dir/clean

tests/CMakeFiles/TestILLAsciiQScan.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestILLAsciiQScan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestILLAsciiQScan.dir/depend
