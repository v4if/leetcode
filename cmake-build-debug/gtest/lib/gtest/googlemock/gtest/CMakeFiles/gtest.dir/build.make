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
include gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../gtest/lib/gtest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /root/Workspace/Clion/leetcode/gtest/lib/gtest/googletest/src/gtest-all.cc

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/lib/gtest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/lib/gtest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build.make gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

gtest/lib/gtest/googlemock/gtest/libgtest.a: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
gtest/lib/gtest/googlemock/gtest/libgtest.a: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build.make
gtest/lib/gtest/googlemock/gtest/libgtest.a: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build: gtest/lib/gtest/googlemock/gtest/libgtest.a

.PHONY : gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/build

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/requires: gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/requires

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/clean

gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Workspace/Clion/leetcode /root/Workspace/Clion/leetcode/gtest/lib/gtest/googletest /root/Workspace/Clion/leetcode/cmake-build-debug /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest/lib/gtest/googlemock/gtest/CMakeFiles/gtest.dir/depend

