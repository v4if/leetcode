# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /root/Software/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /root/Software/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Workspace/Clion/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Workspace/Clion/leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include Line/CMakeFiles/Line.dir/depend.make

# Include the progress variables for this target.
include Line/CMakeFiles/Line.dir/progress.make

# Include the compile flags for this target's objects.
include Line/CMakeFiles/Line.dir/flags.make

Line/CMakeFiles/Line.dir/Line.o: Line/CMakeFiles/Line.dir/flags.make
Line/CMakeFiles/Line.dir/Line.o: ../Line/Line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Line/CMakeFiles/Line.dir/Line.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Line.dir/Line.o -c /root/Workspace/Clion/leetcode/Line/Line.cpp

Line/CMakeFiles/Line.dir/Line.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Line.dir/Line.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/Line/Line.cpp > CMakeFiles/Line.dir/Line.i

Line/CMakeFiles/Line.dir/Line.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Line.dir/Line.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/Line/Line.cpp -o CMakeFiles/Line.dir/Line.s

Line/CMakeFiles/Line.dir/Line.o.requires:

.PHONY : Line/CMakeFiles/Line.dir/Line.o.requires

Line/CMakeFiles/Line.dir/Line.o.provides: Line/CMakeFiles/Line.dir/Line.o.requires
	$(MAKE) -f Line/CMakeFiles/Line.dir/build.make Line/CMakeFiles/Line.dir/Line.o.provides.build
.PHONY : Line/CMakeFiles/Line.dir/Line.o.provides

Line/CMakeFiles/Line.dir/Line.o.provides.build: Line/CMakeFiles/Line.dir/Line.o


# Object files for target Line
Line_OBJECTS = \
"CMakeFiles/Line.dir/Line.o"

# External object files for target Line
Line_EXTERNAL_OBJECTS =

Line/libLine.a: Line/CMakeFiles/Line.dir/Line.o
Line/libLine.a: Line/CMakeFiles/Line.dir/build.make
Line/libLine.a: Line/CMakeFiles/Line.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLine.a"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line && $(CMAKE_COMMAND) -P CMakeFiles/Line.dir/cmake_clean_target.cmake
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Line.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Line/CMakeFiles/Line.dir/build: Line/libLine.a

.PHONY : Line/CMakeFiles/Line.dir/build

Line/CMakeFiles/Line.dir/requires: Line/CMakeFiles/Line.dir/Line.o.requires

.PHONY : Line/CMakeFiles/Line.dir/requires

Line/CMakeFiles/Line.dir/clean:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line && $(CMAKE_COMMAND) -P CMakeFiles/Line.dir/cmake_clean.cmake
.PHONY : Line/CMakeFiles/Line.dir/clean

Line/CMakeFiles/Line.dir/depend:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Workspace/Clion/leetcode /root/Workspace/Clion/leetcode/Line /root/Workspace/Clion/leetcode/cmake-build-debug /root/Workspace/Clion/leetcode/cmake-build-debug/Line /root/Workspace/Clion/leetcode/cmake-build-debug/Line/CMakeFiles/Line.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Line/CMakeFiles/Line.dir/depend

