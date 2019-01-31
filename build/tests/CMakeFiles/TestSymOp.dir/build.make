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
include tests/CMakeFiles/TestSymOp.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestSymOp.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestSymOp.dir/flags.make

tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o: tests/CMakeFiles/TestSymOp.dir/flags.make
tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o: ../tests/crystal/TestSymOp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestSymOp.cpp

tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestSymOp.cpp > CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.i

tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestSymOp.cpp -o CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.s

tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.requires

tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.provides: tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestSymOp.dir/build.make tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.provides

tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.provides.build: tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o


# Object files for target TestSymOp
TestSymOp_OBJECTS = \
"CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o"

# External object files for target TestSymOp
TestSymOp_EXTERNAL_OBJECTS =

tests/TestSymOp: tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o
tests/TestSymOp: tests/CMakeFiles/TestSymOp.dir/build.make
tests/TestSymOp: nsxlib/libnsx.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestSymOp: externals/c-blosc/blosc/libblosc.a
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestSymOp: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestSymOp: /usr/local/lib/libgsl.so
tests/TestSymOp: /usr/local/lib/libgslcblas.so
tests/TestSymOp: tests/CMakeFiles/TestSymOp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSymOp"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSymOp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestSymOp.dir/build: tests/TestSymOp

.PHONY : tests/CMakeFiles/TestSymOp.dir/build

tests/CMakeFiles/TestSymOp.dir/requires: tests/CMakeFiles/TestSymOp.dir/crystal/TestSymOp.cpp.o.requires

.PHONY : tests/CMakeFiles/TestSymOp.dir/requires

tests/CMakeFiles/TestSymOp.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestSymOp.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestSymOp.dir/clean

tests/CMakeFiles/TestSymOp.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestSymOp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestSymOp.dir/depend

