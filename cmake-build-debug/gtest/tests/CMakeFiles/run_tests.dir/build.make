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
include gtest/tests/CMakeFiles/run_tests.dir/depend.make

# Include the progress variables for this target.
include gtest/tests/CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/tests/CMakeFiles/run_tests.dir/flags.make

gtest/tests/CMakeFiles/run_tests.dir/main.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/main.o: ../gtest/tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/main.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/main.o -c /root/Workspace/Clion/leetcode/gtest/tests/main.cpp

gtest/tests/CMakeFiles/run_tests.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/main.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/main.cpp > CMakeFiles/run_tests.dir/main.i

gtest/tests/CMakeFiles/run_tests.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/main.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/main.cpp -o CMakeFiles/run_tests.dir/main.s

gtest/tests/CMakeFiles/run_tests.dir/main.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/main.o.requires

gtest/tests/CMakeFiles/run_tests.dir/main.o.provides: gtest/tests/CMakeFiles/run_tests.dir/main.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/main.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/main.o.provides

gtest/tests/CMakeFiles/run_tests.dir/main.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/main.o


gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o: ../gtest/tests/001_two_sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/001_two_sum.o -c /root/Workspace/Clion/leetcode/gtest/tests/001_two_sum.cpp

gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/001_two_sum.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/001_two_sum.cpp > CMakeFiles/run_tests.dir/001_two_sum.i

gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/001_two_sum.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/001_two_sum.cpp -o CMakeFiles/run_tests.dir/001_two_sum.s

gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.requires

gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.provides: gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.provides

gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o


gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o: ../gtest/tests/002_add_two_nums.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/002_add_two_nums.o -c /root/Workspace/Clion/leetcode/gtest/tests/002_add_two_nums.cpp

gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/002_add_two_nums.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/002_add_two_nums.cpp > CMakeFiles/run_tests.dir/002_add_two_nums.i

gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/002_add_two_nums.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/002_add_two_nums.cpp -o CMakeFiles/run_tests.dir/002_add_two_nums.s

gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.requires

gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.provides: gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.provides

gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o


gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o: ../gtest/tests/003_longest_substr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/003_longest_substr.o -c /root/Workspace/Clion/leetcode/gtest/tests/003_longest_substr.cpp

gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/003_longest_substr.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/003_longest_substr.cpp > CMakeFiles/run_tests.dir/003_longest_substr.i

gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/003_longest_substr.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/003_longest_substr.cpp -o CMakeFiles/run_tests.dir/003_longest_substr.s

gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.requires

gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.provides: gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.provides

gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o


gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o: ../gtest/tests/004_median_of_two_sorted_array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o -c /root/Workspace/Clion/leetcode/gtest/tests/004_median_of_two_sorted_array.cpp

gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/004_median_of_two_sorted_array.cpp > CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.i

gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/004_median_of_two_sorted_array.cpp -o CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.s

gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.requires

gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.provides: gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.provides

gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o


gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o: ../gtest/tests/005_longest_palindromic_substr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o -c /root/Workspace/Clion/leetcode/gtest/tests/005_longest_palindromic_substr.cpp

gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/005_longest_palindromic_substr.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/005_longest_palindromic_substr.cpp > CMakeFiles/run_tests.dir/005_longest_palindromic_substr.i

gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/005_longest_palindromic_substr.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/005_longest_palindromic_substr.cpp -o CMakeFiles/run_tests.dir/005_longest_palindromic_substr.s

gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.requires

gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.provides: gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.provides

gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o


gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o: ../gtest/tests/006_zigzag_conversion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/006_zigzag_conversion.o -c /root/Workspace/Clion/leetcode/gtest/tests/006_zigzag_conversion.cpp

gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/006_zigzag_conversion.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/006_zigzag_conversion.cpp > CMakeFiles/run_tests.dir/006_zigzag_conversion.i

gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/006_zigzag_conversion.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/006_zigzag_conversion.cpp -o CMakeFiles/run_tests.dir/006_zigzag_conversion.s

gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.requires

gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.provides: gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.provides

gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o


gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o: ../gtest/tests/007_reverse_integer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/007_reverse_integer.o -c /root/Workspace/Clion/leetcode/gtest/tests/007_reverse_integer.cpp

gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/007_reverse_integer.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/007_reverse_integer.cpp > CMakeFiles/run_tests.dir/007_reverse_integer.i

gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/007_reverse_integer.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/007_reverse_integer.cpp -o CMakeFiles/run_tests.dir/007_reverse_integer.s

gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.requires

gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.provides: gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.provides

gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o


gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o: ../gtest/tests/008_string2integer_atoi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/008_string2integer_atoi.o -c /root/Workspace/Clion/leetcode/gtest/tests/008_string2integer_atoi.cpp

gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/008_string2integer_atoi.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/008_string2integer_atoi.cpp > CMakeFiles/run_tests.dir/008_string2integer_atoi.i

gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/008_string2integer_atoi.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/008_string2integer_atoi.cpp -o CMakeFiles/run_tests.dir/008_string2integer_atoi.s

gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.requires

gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.provides: gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.provides

gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o


gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o: ../gtest/tests/009_palindrome_number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/009_palindrome_number.o -c /root/Workspace/Clion/leetcode/gtest/tests/009_palindrome_number.cpp

gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/009_palindrome_number.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/009_palindrome_number.cpp > CMakeFiles/run_tests.dir/009_palindrome_number.i

gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/009_palindrome_number.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/009_palindrome_number.cpp -o CMakeFiles/run_tests.dir/009_palindrome_number.s

gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.requires

gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.provides: gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.provides

gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o


gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o: ../gtest/tests/010_regular_expression_matching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/010_regular_expression_matching.o -c /root/Workspace/Clion/leetcode/gtest/tests/010_regular_expression_matching.cpp

gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/010_regular_expression_matching.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/010_regular_expression_matching.cpp > CMakeFiles/run_tests.dir/010_regular_expression_matching.i

gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/010_regular_expression_matching.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/010_regular_expression_matching.cpp -o CMakeFiles/run_tests.dir/010_regular_expression_matching.s

gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.requires

gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.provides: gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.provides

gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o


gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o: gtest/tests/CMakeFiles/run_tests.dir/flags.make
gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o: ../gtest/tests/011_container_with_most_water.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/011_container_with_most_water.o -c /root/Workspace/Clion/leetcode/gtest/tests/011_container_with_most_water.cpp

gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/011_container_with_most_water.i"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Workspace/Clion/leetcode/gtest/tests/011_container_with_most_water.cpp > CMakeFiles/run_tests.dir/011_container_with_most_water.i

gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/011_container_with_most_water.s"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Workspace/Clion/leetcode/gtest/tests/011_container_with_most_water.cpp -o CMakeFiles/run_tests.dir/011_container_with_most_water.s

gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.requires:

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.requires

gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.provides: gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.requires
	$(MAKE) -f gtest/tests/CMakeFiles/run_tests.dir/build.make gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.provides.build
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.provides

gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.provides.build: gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o


# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/main.o" \
"CMakeFiles/run_tests.dir/001_two_sum.o" \
"CMakeFiles/run_tests.dir/002_add_two_nums.o" \
"CMakeFiles/run_tests.dir/003_longest_substr.o" \
"CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o" \
"CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o" \
"CMakeFiles/run_tests.dir/006_zigzag_conversion.o" \
"CMakeFiles/run_tests.dir/007_reverse_integer.o" \
"CMakeFiles/run_tests.dir/008_string2integer_atoi.o" \
"CMakeFiles/run_tests.dir/009_palindrome_number.o" \
"CMakeFiles/run_tests.dir/010_regular_expression_matching.o" \
"CMakeFiles/run_tests.dir/011_container_with_most_water.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/main.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/build.make
gtest/tests/run_tests: gtest/lib/gtest/googlemock/gtest/libgtest.a
gtest/tests/run_tests: gtest/lib/gtest/googlemock/gtest/libgtest_main.a
gtest/tests/run_tests: src/libMain.a
gtest/tests/run_tests: gtest/lib/gtest/googlemock/gtest/libgtest.a
gtest/tests/run_tests: gtest/tests/CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Workspace/Clion/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable run_tests"
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest/tests/CMakeFiles/run_tests.dir/build: gtest/tests/run_tests

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/build

gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/main.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/001_two_sum.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/002_add_two_nums.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/003_longest_substr.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/004_median_of_two_sorted_array.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/005_longest_palindromic_substr.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/006_zigzag_conversion.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/007_reverse_integer.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/008_string2integer_atoi.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/009_palindrome_number.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/010_regular_expression_matching.o.requires
gtest/tests/CMakeFiles/run_tests.dir/requires: gtest/tests/CMakeFiles/run_tests.dir/011_container_with_most_water.o.requires

.PHONY : gtest/tests/CMakeFiles/run_tests.dir/requires

gtest/tests/CMakeFiles/run_tests.dir/clean:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests && $(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/clean

gtest/tests/CMakeFiles/run_tests.dir/depend:
	cd /root/Workspace/Clion/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Workspace/Clion/leetcode /root/Workspace/Clion/leetcode/gtest/tests /root/Workspace/Clion/leetcode/cmake-build-debug /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests /root/Workspace/Clion/leetcode/cmake-build-debug/gtest/tests/CMakeFiles/run_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest/tests/CMakeFiles/run_tests.dir/depend

