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
include CMakeFiles/gorillas_ai.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gorillas_ai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gorillas_ai.dir/flags.make

CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.o: CMakeFiles/gorillas_ai.dir/flags.make
CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.o: ../gorillas_ai.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ecn/ARPRO/gorillas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.o -c /home/ecn/ARPRO/gorillas/gorillas_ai.cpp

CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ecn/ARPRO/gorillas/gorillas_ai.cpp > CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.i

CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ecn/ARPRO/gorillas/gorillas_ai.cpp -o CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.s

# Object files for target gorillas_ai
gorillas_ai_OBJECTS = \
"CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.o"

# External object files for target gorillas_ai
gorillas_ai_EXTERNAL_OBJECTS =

gorillas_ai: CMakeFiles/gorillas_ai.dir/gorillas_ai.cpp.o
gorillas_ai: CMakeFiles/gorillas_ai.dir/build.make
gorillas_ai: CMakeFiles/gorillas_ai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ecn/ARPRO/gorillas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gorillas_ai"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gorillas_ai.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gorillas_ai.dir/build: gorillas_ai

.PHONY : CMakeFiles/gorillas_ai.dir/build

CMakeFiles/gorillas_ai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gorillas_ai.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gorillas_ai.dir/clean

CMakeFiles/gorillas_ai.dir/depend:
	cd /home/ecn/ARPRO/gorillas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ecn/ARPRO/gorillas /home/ecn/ARPRO/gorillas /home/ecn/ARPRO/gorillas/build /home/ecn/ARPRO/gorillas/build /home/ecn/ARPRO/gorillas/build/CMakeFiles/gorillas_ai.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gorillas_ai.dir/depend
