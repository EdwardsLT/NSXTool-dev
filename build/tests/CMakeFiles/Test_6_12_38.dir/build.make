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
include tests/CMakeFiles/Test_6_12_38.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/Test_6_12_38.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/Test_6_12_38.dir/flags.make

tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o: tests/CMakeFiles/Test_6_12_38.dir/flags.make
tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o: ../tests/integrate/Test_6_12_38.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/integrate/Test_6_12_38.cpp

tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/integrate/Test_6_12_38.cpp > CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.i

tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/integrate/Test_6_12_38.cpp -o CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.s

tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.requires:

.PHONY : tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.requires

tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.provides: tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/Test_6_12_38.dir/build.make tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.provides.build
.PHONY : tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.provides

tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.provides.build: tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o


# Object files for target Test_6_12_38
Test_6_12_38_OBJECTS = \
"CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o"

# External object files for target Test_6_12_38
Test_6_12_38_EXTERNAL_OBJECTS =

tests/Test_6_12_38: tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o
tests/Test_6_12_38: tests/CMakeFiles/Test_6_12_38.dir/build.make
tests/Test_6_12_38: nsxlib/libnsx.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libsz.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libdl.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libm.so
tests/Test_6_12_38: externals/c-blosc/blosc/libblosc.a
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libz.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/Test_6_12_38: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/Test_6_12_38: /usr/local/lib/libgsl.so
tests/Test_6_12_38: /usr/local/lib/libgslcblas.so
tests/Test_6_12_38: tests/CMakeFiles/Test_6_12_38.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test_6_12_38"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_6_12_38.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/Test_6_12_38.dir/build: tests/Test_6_12_38

.PHONY : tests/CMakeFiles/Test_6_12_38.dir/build

tests/CMakeFiles/Test_6_12_38.dir/requires: tests/CMakeFiles/Test_6_12_38.dir/integrate/Test_6_12_38.cpp.o.requires

.PHONY : tests/CMakeFiles/Test_6_12_38.dir/requires

tests/CMakeFiles/Test_6_12_38.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/Test_6_12_38.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Test_6_12_38.dir/clean

tests/CMakeFiles/Test_6_12_38.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/Test_6_12_38.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Test_6_12_38.dir/depend

