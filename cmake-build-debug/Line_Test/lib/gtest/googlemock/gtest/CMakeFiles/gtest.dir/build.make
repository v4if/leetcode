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
include Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../Line_Test/lib/gtest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /root/Workspace/Clion/leetcode/Line_Test/lib/gtest/googletest/src/gtest-all.cc

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/Line_Test/lib/gtest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/Line_Test/lib/gtest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build.make Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

Line_Test/lib/gtest/googlemock/gtest/libgtest.a: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
Line_Test/lib/gtest/googlemock/gtest/libgtest.a: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build.make
Line_Test/lib/gtest/googlemock/gtest/libgtest.a: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build: Line_Test/lib/gtest/googlemock/gtest/libgtest.a

.PHONY : Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/requires: Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/requires

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/clean

Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Workspace/Clion/leetcode /root/Workspace/Clion/leetcode/Line_Test/lib/gtest/googletest /root/Workspace/Clion/leetcode/cmake-build-debug /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Line_Test/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/depend

