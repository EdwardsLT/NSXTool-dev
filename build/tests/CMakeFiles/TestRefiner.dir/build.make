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
include tests/CMakeFiles/TestRefiner.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestRefiner.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestRefiner.dir/flags.make

tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o: tests/CMakeFiles/TestRefiner.dir/flags.make
tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o: ../tests/crystal/TestRefiner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o -c /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestRefiner.cpp

tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestRefiner.cpp > CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.i

tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/tests/crystal/TestRefiner.cpp -o CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.s

tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.requires:

.PHONY : tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.requires

tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.provides: tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/TestRefiner.dir/build.make tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.provides.build
.PHONY : tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.provides

tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.provides.build: tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o


# Object files for target TestRefiner
TestRefiner_OBJECTS = \
"CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o"

# External object files for target TestRefiner
TestRefiner_EXTERNAL_OBJECTS =

tests/TestRefiner: tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o
tests/TestRefiner: tests/CMakeFiles/TestRefiner.dir/build.make
tests/TestRefiner: nsxlib/libnsx.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libpthread.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libsz.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libdl.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libm.so
tests/TestRefiner: externals/c-blosc/blosc/libblosc.a
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libz.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libfftw3.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so
tests/TestRefiner: /usr/lib/x86_64-linux-gnu/libtiff.so
tests/TestRefiner: /usr/local/lib/libgsl.so
tests/TestRefiner: /usr/local/lib/libgslcblas.so
tests/TestRefiner: tests/CMakeFiles/TestRefiner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestRefiner"
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestRefiner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestRefiner.dir/build: tests/TestRefiner

.PHONY : tests/CMakeFiles/TestRefiner.dir/build

tests/CMakeFiles/TestRefiner.dir/requires: tests/CMakeFiles/TestRefiner.dir/crystal/TestRefiner.cpp.o.requires

.PHONY : tests/CMakeFiles/TestRefiner.dir/requires

tests/CMakeFiles/TestRefiner.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestRefiner.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestRefiner.dir/clean

tests/CMakeFiles/TestRefiner.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/tests /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/tests /home/lewisedwards/bin/nsxtool-dev/build/tests/CMakeFiles/TestRefiner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestRefiner.dir/depend

