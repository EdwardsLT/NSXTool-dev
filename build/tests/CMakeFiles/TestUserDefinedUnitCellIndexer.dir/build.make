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
include tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/flags.make

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/flags.make
tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o: ../tests/auto-indexer/TestUserDefinedUnitCellIndexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/auto-indexer/TestUserDefinedUnitCellIndexer.cpp

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/auto-indexer/TestUserDefinedUnitCellIndexer.cpp > CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.i

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/auto-indexer/TestUserDefinedUnitCellIndexer.cpp -o CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.s

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.requires

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.provides: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/build.make tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.provides

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.provides.build: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o


# Object files for target TestUserDefinedUnitCellIndexer
TestUserDefinedUnitCellIndexer_OBJECTS = \
"CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o"

# External object files for target TestUserDefinedUnitCellIndexer
TestUserDefinedUnitCellIndexer_EXTERNAL_OBJECTS =

tests/TestUserDefinedUnitCellIndexer: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o
tests/TestUserDefinedUnitCellIndexer: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/build.make
tests/TestUserDefinedUnitCellIndexer: nsxlib/libnsx.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestUserDefinedUnitCellIndexer: externals/c-blosc/blosc/libblosc.a
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestUserDefinedUnitCellIndexer: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestUserDefinedUnitCellIndexer: /usr/local/lib/libgsl.so
tests/TestUserDefinedUnitCellIndexer: /usr/local/lib/libgslcblas.so
tests/TestUserDefinedUnitCellIndexer: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestUserDefinedUnitCellIndexer"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestUserDefinedUnitCellIndexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/build: tests/TestUserDefinedUnitCellIndexer

.PHONY : tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/build

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/requires: tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/auto-indexer/TestUserDefinedUnitCellIndexer.cpp.o.requires

.PHONY : tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/requires

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestUserDefinedUnitCellIndexer.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/clean

tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestUserDefinedUnitCellIndexer.dir/depend

