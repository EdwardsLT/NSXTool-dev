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
include externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/depend.make

# Include the progress variables for this target.
include externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/progress.make

# Include the compile flags for this target's objects.
include externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o: ../externals/c-blosc/blosc/blosc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/blosc_shared.dir/blosc.c.o   -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/blosc.c

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/blosc_shared.dir/blosc.c.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/blosc.c > CMakeFiles/blosc_shared.dir/blosc.c.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/blosc_shared.dir/blosc.c.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/blosc.c -o CMakeFiles/blosc_shared.dir/blosc.c.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o: ../externals/c-blosc/blosc/blosclz.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/blosc_shared.dir/blosclz.c.o   -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/blosclz.c

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/blosc_shared.dir/blosclz.c.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/blosclz.c > CMakeFiles/blosc_shared.dir/blosclz.c.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/blosc_shared.dir/blosclz.c.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/blosclz.c -o CMakeFiles/blosc_shared.dir/blosclz.c.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o: ../externals/c-blosc/blosc/shuffle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/blosc_shared.dir/shuffle.c.o   -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/shuffle.c

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/blosc_shared.dir/shuffle.c.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/shuffle.c > CMakeFiles/blosc_shared.dir/shuffle.c.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/blosc_shared.dir/shuffle.c.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc/shuffle.c -o CMakeFiles/blosc_shared.dir/shuffle.c.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o: ../externals/c-blosc/internal-complibs/lz4-r123/lz4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o   -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/lz4-r123/lz4.c

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/lz4-r123/lz4.c > CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/lz4-r123/lz4.c -o CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o: ../externals/c-blosc/internal-complibs/lz4-r123/lz4hc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o   -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/lz4-r123/lz4hc.c

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/lz4-r123/lz4hc.c > CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/lz4-r123/lz4hc.c -o CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o: ../externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-c.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-c.cc

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-c.cc > CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-c.cc -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o: ../externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-sinksource.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-sinksource.cc

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-sinksource.cc > CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-sinksource.cc -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o: ../externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc > CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o


externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/flags.make
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o: ../externals/c-blosc/internal-complibs/snappy-1.1.1/snappy.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o -c /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy.cc

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.i"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy.cc > CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.i

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.s"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/internal-complibs/snappy-1.1.1/snappy.cc -o CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.s

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.requires:

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.provides: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.requires
	$(MAKE) -f externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.provides.build
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.provides

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.provides.build: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o


# Object files for target blosc_shared
blosc_shared_OBJECTS = \
"CMakeFiles/blosc_shared.dir/blosc.c.o" \
"CMakeFiles/blosc_shared.dir/blosclz.c.o" \
"CMakeFiles/blosc_shared.dir/shuffle.c.o" \
"CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o" \
"CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o" \
"CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o" \
"CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o" \
"CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o" \
"CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o"

# External object files for target blosc_shared
blosc_shared_EXTERNAL_OBJECTS =

externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build.make
externals/c-blosc/blosc/libblosc.so.1.5.0: /usr/lib/x86_64-linux-gnu/libz.so
externals/c-blosc/blosc/libblosc.so.1.5.0: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewisedwards/bin/nsxtool-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library libblosc.so"
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blosc_shared.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && $(CMAKE_COMMAND) -E cmake_symlink_library libblosc.so.1.5.0 libblosc.so.1 libblosc.so

externals/c-blosc/blosc/libblosc.so.1: externals/c-blosc/blosc/libblosc.so.1.5.0
	@$(CMAKE_COMMAND) -E touch_nocreate externals/c-blosc/blosc/libblosc.so.1

externals/c-blosc/blosc/libblosc.so: externals/c-blosc/blosc/libblosc.so.1.5.0
	@$(CMAKE_COMMAND) -E touch_nocreate externals/c-blosc/blosc/libblosc.so

# Rule to build all files generated by this target.
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build: externals/c-blosc/blosc/libblosc.so

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/build

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosc.c.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/blosclz.c.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/shuffle.c.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4.c.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/lz4-r123/lz4hc.c.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-c.cc.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-sinksource.cc.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy-stubs-internal.cc.o.requires
externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires: externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/__/internal-complibs/snappy-1.1.1/snappy.cc.o.requires

.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/requires

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/clean:
	cd /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc && $(CMAKE_COMMAND) -P CMakeFiles/blosc_shared.dir/cmake_clean.cmake
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/clean

externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/depend:
	cd /home/lewisedwards/bin/nsxtool-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewisedwards/bin/nsxtool-dev /home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc /home/lewisedwards/bin/nsxtool-dev/build /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc /home/lewisedwards/bin/nsxtool-dev/build/externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : externals/c-blosc/blosc/CMakeFiles/blosc_shared.dir/depend

