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
include Line_Test/tests/CMakeFiles/run_tests.dir/depend.make

# Include the progress variables for this target.
include Line_Test/tests/CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include Line_Test/tests/CMakeFiles/run_tests.dir/flags.make

Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o: Line_Test/tests/CMakeFiles/run_tests.dir/flags.make
Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o: ../Line_Test/tests/line_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/line_tests.o -c /root/Workspace/Clion/leetcode/Line_Test/tests/line_tests.cpp

Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/line_tests.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/Line_Test/tests/line_tests.cpp > CMakeFiles/run_tests.dir/line_tests.i

Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/line_tests.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/Line_Test/tests/line_tests.cpp -o CMakeFiles/run_tests.dir/line_tests.s

Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.requires:

.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.requires

Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.provides: Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.requires
	$(MAKE) -f Line_Test/tests/CMakeFiles/run_tests.dir/build.make Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.provides.build
.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.provides

Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.provides.build: Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o


Line_Test/tests/CMakeFiles/run_tests.dir/main.o: Line_Test/tests/CMakeFiles/run_tests.dir/flags.make
Line_Test/tests/CMakeFiles/run_tests.dir/main.o: ../Line_Test/tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Line_Test/tests/CMakeFiles/run_tests.dir/main.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/main.o -c /root/Workspace/Clion/leetcode/Line_Test/tests/main.cpp

Line_Test/tests/CMakeFiles/run_tests.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/main.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/Line_Test/tests/main.cpp > CMakeFiles/run_tests.dir/main.i

Line_Test/tests/CMakeFiles/run_tests.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/main.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/Line_Test/tests/main.cpp -o CMakeFiles/run_tests.dir/main.s

Line_Test/tests/CMakeFiles/run_tests.dir/main.o.requires:

.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/main.o.requires

Line_Test/tests/CMakeFiles/run_tests.dir/main.o.provides: Line_Test/tests/CMakeFiles/run_tests.dir/main.o.requires
	$(MAKE) -f Line_Test/tests/CMakeFiles/run_tests.dir/build.make Line_Test/tests/CMakeFiles/run_tests.dir/main.o.provides.build
.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/main.o.provides

Line_Test/tests/CMakeFiles/run_tests.dir/main.o.provides.build: Line_Test/tests/CMakeFiles/run_tests.dir/main.o


# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/line_tests.o" \
"CMakeFiles/run_tests.dir/main.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

Line_Test/tests/run_tests: Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o
Line_Test/tests/run_tests: Line_Test/tests/CMakeFiles/run_tests.dir/main.o
Line_Test/tests/run_tests: Line_Test/tests/CMakeFiles/run_tests.dir/build.make
Line_Test/tests/run_tests: Line_Test/lib/gtest/googlemock/gtest/libgtest.a
Line_Test/tests/run_tests: Line_Test/lib/gtest/googlemock/gtest/libgtest_main.a
Line_Test/tests/run_tests: src/libLine.a
Line_Test/tests/run_tests: Line_Test/lib/gtest/googlemock/gtest/libgtest.a
Line_Test/tests/run_tests: Line_Test/tests/CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_tests"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Line_Test/tests/CMakeFiles/run_tests.dir/build: Line_Test/tests/run_tests

.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/build

Line_Test/tests/CMakeFiles/run_tests.dir/requires: Line_Test/tests/CMakeFiles/run_tests.dir/line_tests.o.requires
Line_Test/tests/CMakeFiles/run_tests.dir/requires: Line_Test/tests/CMakeFiles/run_tests.dir/main.o.requires

.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/requires

Line_Test/tests/CMakeFiles/run_tests.dir/clean:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests && $(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/clean

Line_Test/tests/CMakeFiles/run_tests.dir/depend:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Workspace/Clion/leetcode /root/Workspace/Clion/leetcode/Line_Test/tests /root/Workspace/Clion/leetcode/cmake-build-debug /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests /root/Workspace/Clion/leetcode/cmake-build-debug/Line_Test/tests/CMakeFiles/run_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Line_Test/tests/CMakeFiles/run_tests.dir/depend

