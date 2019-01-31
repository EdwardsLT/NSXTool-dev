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
include tests/CMakeFiles/TestMatrixParser.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestMatrixParser.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestMatrixParser.dir/flags.make

tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o: tests/CMakeFiles/TestMatrixParser.dir/flags.make
tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o: ../tests/utils/TestMatrixParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/utils/TestMatrixParser.cpp

tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/utils/TestMatrixParser.cpp > CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.i

tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/utils/TestMatrixParser.cpp -o CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.s

tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.requires

tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.provides: tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestMatrixParser.dir/build.make tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.provides

tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.provides.build: tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o


# Object files for target TestMatrixParser
TestMatrixParser_OBJECTS = \
"CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o"

# External object files for target TestMatrixParser
TestMatrixParser_EXTERNAL_OBJECTS =

tests/TestMatrixParser: tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o
tests/TestMatrixParser: tests/CMakeFiles/TestMatrixParser.dir/build.make
tests/TestMatrixParser: nsxlib/libnsx.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestMatrixParser: externals/c-blosc/blosc/libblosc.a
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestMatrixParser: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestMatrixParser: /usr/local/lib/libgsl.so
tests/TestMatrixParser: /usr/local/lib/libgslcblas.so
tests/TestMatrixParser: tests/CMakeFiles/TestMatrixParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestMatrixParser"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestMatrixParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestMatrixParser.dir/build: tests/TestMatrixParser

.PHONY : tests/CMakeFiles/TestMatrixParser.dir/build

tests/CMakeFiles/TestMatrixParser.dir/requires: tests/CMakeFiles/TestMatrixParser.dir/utils/TestMatrixParser.cpp.o.requires

.PHONY : tests/CMakeFiles/TestMatrixParser.dir/requires

tests/CMakeFiles/TestMatrixParser.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestMatrixParser.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestMatrixParser.dir/clean

tests/CMakeFiles/TestMatrixParser.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestMatrixParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestMatrixParser.dir/depend
