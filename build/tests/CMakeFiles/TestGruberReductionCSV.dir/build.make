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
include tests/CMakeFiles/TestGruberReductionCSV.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestGruberReductionCSV.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestGruberReductionCSV.dir/flags.make

tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o: tests/CMakeFiles/TestGruberReductionCSV.dir/flags.make
tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o: ../tests/crystal/TestGruberReductionCSV.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestGruberReductionCSV.cpp

tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestGruberReductionCSV.cpp > CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.i

tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestGruberReductionCSV.cpp -o CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.s

tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.requires

tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.provides: tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestGruberReductionCSV.dir/build.make tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.provides

tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.provides.build: tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o


# Object files for target TestGruberReductionCSV
TestGruberReductionCSV_OBJECTS = \
"CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o"

# External object files for target TestGruberReductionCSV
TestGruberReductionCSV_EXTERNAL_OBJECTS =

tests/TestGruberReductionCSV: tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o
tests/TestGruberReductionCSV: tests/CMakeFiles/TestGruberReductionCSV.dir/build.make
tests/TestGruberReductionCSV: nsxlib/libnsx.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestGruberReductionCSV: externals/c-blosc/blosc/libblosc.a
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestGruberReductionCSV: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestGruberReductionCSV: /usr/local/lib/libgsl.so
tests/TestGruberReductionCSV: /usr/local/lib/libgslcblas.so
tests/TestGruberReductionCSV: tests/CMakeFiles/TestGruberReductionCSV.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestGruberReductionCSV"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestGruberReductionCSV.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestGruberReductionCSV.dir/build: tests/TestGruberReductionCSV

.PHONY : tests/CMakeFiles/TestGruberReductionCSV.dir/build

tests/CMakeFiles/TestGruberReductionCSV.dir/requires: tests/CMakeFiles/TestGruberReductionCSV.dir/crystal/TestGruberReductionCSV.cpp.o.requires

.PHONY : tests/CMakeFiles/TestGruberReductionCSV.dir/requires

tests/CMakeFiles/TestGruberReductionCSV.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestGruberReductionCSV.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestGruberReductionCSV.dir/clean

tests/CMakeFiles/TestGruberReductionCSV.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestGruberReductionCSV.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestGruberReductionCSV.dir/depend

