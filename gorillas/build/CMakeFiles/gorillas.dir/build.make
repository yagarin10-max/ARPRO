# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_SOURCE_DIR = /home/ecn/ARPRO/gorillas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ecn/ARPRO/gorillas/build

# Include any dependencies generated for this target.
include CMakeFiles/gorillas.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gorillas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gorillas.dir/flags.make

CMakeFiles/gorillas.dir/gorillas.cpp.o: CMakeFiles/gorillas.dir/flags.make
CMakeFiles/gorillas.dir/gorillas.cpp.o: ../gorillas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ecn/ARPRO/gorillas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gorillas.dir/gorillas.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gorillas.dir/gorillas.cpp.o -c /home/ecn/ARPRO/gorillas/gorillas.cpp

CMakeFiles/gorillas.dir/gorillas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gorillas.dir/gorillas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ecn/ARPRO/gorillas/gorillas.cpp > CMakeFiles/gorillas.dir/gorillas.cpp.i

CMakeFiles/gorillas.dir/gorillas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gorillas.dir/gorillas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ecn/ARPRO/gorillas/gorillas.cpp -o CMakeFiles/gorillas.dir/gorillas.cpp.s

# Object files for target gorillas
gorillas_OBJECTS = \
"CMakeFiles/gorillas.dir/gorillas.cpp.o"

# External object files for target gorillas
gorillas_EXTERNAL_OBJECTS =

gorillas: CMakeFiles/gorillas.dir/gorillas.cpp.o
gorillas: CMakeFiles/gorillas.dir/build.make
gorillas: /usr/lib/x86_64-linux-gnu/libzmq.so
gorillas: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so.0.6.2
gorillas: CMakeFiles/gorillas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ecn/ARPRO/gorillas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gorillas"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gorillas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gorillas.dir/build: gorillas

.PHONY : CMakeFiles/gorillas.dir/build

CMakeFiles/gorillas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gorillas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gorillas.dir/clean

CMakeFiles/gorillas.dir/depend:
	cd /home/ecn/ARPRO/gorillas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ecn/ARPRO/gorillas /home/ecn/ARPRO/gorillas /home/ecn/ARPRO/gorillas/build /home/ecn/ARPRO/gorillas/build /home/ecn/ARPRO/gorillas/build/CMakeFiles/gorillas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gorillas.dir/depend
