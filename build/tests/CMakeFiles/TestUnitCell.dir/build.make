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
include tests/CMakeFiles/TestUnitCell.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestUnitCell.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestUnitCell.dir/flags.make

tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o: tests/CMakeFiles/TestUnitCell.dir/flags.make
tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o: ../tests/crystal/TestUnitCell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestUnitCell.cpp

tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestUnitCell.cpp > CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.i

tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestUnitCell.cpp -o CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.s

tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.requires

tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.provides: tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestUnitCell.dir/build.make tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.provides

tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.provides.build: tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o


# Object files for target TestUnitCell
TestUnitCell_OBJECTS = \
"CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o"

# External object files for target TestUnitCell
TestUnitCell_EXTERNAL_OBJECTS =

tests/TestUnitCell: tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o
tests/TestUnitCell: tests/CMakeFiles/TestUnitCell.dir/build.make
tests/TestUnitCell: nsxlib/libnsx.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestUnitCell: externals/c-blosc/blosc/libblosc.a
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestUnitCell: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestUnitCell: /usr/local/lib/libgsl.so
tests/TestUnitCell: /usr/local/lib/libgslcblas.so
tests/TestUnitCell: tests/CMakeFiles/TestUnitCell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestUnitCell"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestUnitCell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestUnitCell.dir/build: tests/TestUnitCell

.PHONY : tests/CMakeFiles/TestUnitCell.dir/build

tests/CMakeFiles/TestUnitCell.dir/requires: tests/CMakeFiles/TestUnitCell.dir/crystal/TestUnitCell.cpp.o.requires

.PHONY : tests/CMakeFiles/TestUnitCell.dir/requires

tests/CMakeFiles/TestUnitCell.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestUnitCell.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestUnitCell.dir/clean

tests/CMakeFiles/TestUnitCell.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestUnitCell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestUnitCell.dir/depend

