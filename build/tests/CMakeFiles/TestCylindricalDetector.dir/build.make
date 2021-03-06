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
include tests/CMakeFiles/TestCylindricalDetector.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestCylindricalDetector.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestCylindricalDetector.dir/flags.make

tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o: tests/CMakeFiles/TestCylindricalDetector.dir/flags.make
tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o: ../tests/instrument/TestCylindricalDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/instrument/TestCylindricalDetector.cpp

tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/instrument/TestCylindricalDetector.cpp > CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.i

tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/instrument/TestCylindricalDetector.cpp -o CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.s

tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.requires

tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.provides: tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestCylindricalDetector.dir/build.make tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.provides

tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.provides.build: tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o


# Object files for target TestCylindricalDetector
TestCylindricalDetector_OBJECTS = \
"CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o"

# External object files for target TestCylindricalDetector
TestCylindricalDetector_EXTERNAL_OBJECTS =

tests/TestCylindricalDetector: tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o
tests/TestCylindricalDetector: tests/CMakeFiles/TestCylindricalDetector.dir/build.make
tests/TestCylindricalDetector: nsxlib/libnsx.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestCylindricalDetector: externals/c-blosc/blosc/libblosc.a
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestCylindricalDetector: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestCylindricalDetector: /usr/local/lib/libgsl.so
tests/TestCylindricalDetector: /usr/local/lib/libgslcblas.so
tests/TestCylindricalDetector: tests/CMakeFiles/TestCylindricalDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestCylindricalDetector"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestCylindricalDetector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestCylindricalDetector.dir/build: tests/TestCylindricalDetector

.PHONY : tests/CMakeFiles/TestCylindricalDetector.dir/build

tests/CMakeFiles/TestCylindricalDetector.dir/requires: tests/CMakeFiles/TestCylindricalDetector.dir/instrument/TestCylindricalDetector.cpp.o.requires

.PHONY : tests/CMakeFiles/TestCylindricalDetector.dir/requires

tests/CMakeFiles/TestCylindricalDetector.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestCylindricalDetector.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestCylindricalDetector.dir/clean

tests/CMakeFiles/TestCylindricalDetector.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestCylindricalDetector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestCylindricalDetector.dir/depend

