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
include tests/CMakeFiles/TestStringIO.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestStringIO.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestStringIO.dir/flags.make

tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o: tests/CMakeFiles/TestStringIO.dir/flags.make
tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o: ../tests/utils/TestStringIO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/utils/TestStringIO.cpp

tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/utils/TestStringIO.cpp > CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.i

tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/utils/TestStringIO.cpp -o CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.s

tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.requires

tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.provides: tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestStringIO.dir/build.make tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.provides

tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.provides.build: tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o


# Object files for target TestStringIO
TestStringIO_OBJECTS = \
"CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o"

# External object files for target TestStringIO
TestStringIO_EXTERNAL_OBJECTS =

tests/TestStringIO: tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o
tests/TestStringIO: tests/CMakeFiles/TestStringIO.dir/build.make
tests/TestStringIO: nsxlib/libnsx.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestStringIO: externals/c-blosc/blosc/libblosc.a
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestStringIO: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestStringIO: /usr/local/lib/libgsl.so
tests/TestStringIO: /usr/local/lib/libgslcblas.so
tests/TestStringIO: tests/CMakeFiles/TestStringIO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestStringIO"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestStringIO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestStringIO.dir/build: tests/TestStringIO

.PHONY : tests/CMakeFiles/TestStringIO.dir/build

tests/CMakeFiles/TestStringIO.dir/requires: tests/CMakeFiles/TestStringIO.dir/utils/TestStringIO.cpp.o.requires

.PHONY : tests/CMakeFiles/TestStringIO.dir/requires

tests/CMakeFiles/TestStringIO.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestStringIO.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestStringIO.dir/clean

tests/CMakeFiles/TestStringIO.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestStringIO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestStringIO.dir/depend

