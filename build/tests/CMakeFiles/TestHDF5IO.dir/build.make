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
include tests/CMakeFiles/TestHDF5IO.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestHDF5IO.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestHDF5IO.dir/flags.make

tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o: tests/CMakeFiles/TestHDF5IO.dir/flags.make
tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o: ../tests/data/TestHDF5IO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/data/TestHDF5IO.cpp

tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/data/TestHDF5IO.cpp > CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.i

tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/data/TestHDF5IO.cpp -o CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.s

tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.requires

tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.provides: tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestHDF5IO.dir/build.make tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.provides

tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.provides.build: tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o


# Object files for target TestHDF5IO
TestHDF5IO_OBJECTS = \
"CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o"

# External object files for target TestHDF5IO
TestHDF5IO_EXTERNAL_OBJECTS =

tests/TestHDF5IO: tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o
tests/TestHDF5IO: tests/CMakeFiles/TestHDF5IO.dir/build.make
tests/TestHDF5IO: nsxlib/libnsx.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestHDF5IO: externals/c-blosc/blosc/libblosc.a
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestHDF5IO: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestHDF5IO: /usr/local/lib/libgsl.so
tests/TestHDF5IO: /usr/local/lib/libgslcblas.so
tests/TestHDF5IO: tests/CMakeFiles/TestHDF5IO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestHDF5IO"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestHDF5IO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestHDF5IO.dir/build: tests/TestHDF5IO

.PHONY : tests/CMakeFiles/TestHDF5IO.dir/build

tests/CMakeFiles/TestHDF5IO.dir/requires: tests/CMakeFiles/TestHDF5IO.dir/data/TestHDF5IO.cpp.o.requires

.PHONY : tests/CMakeFiles/TestHDF5IO.dir/requires

tests/CMakeFiles/TestHDF5IO.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestHDF5IO.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestHDF5IO.dir/clean

tests/CMakeFiles/TestHDF5IO.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestHDF5IO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestHDF5IO.dir/depend

