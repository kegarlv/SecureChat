# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/ivan/Projects/SecureChat/SecureChat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/Projects/SecureChat/SecureChat/build

# Utility rule file for testUser_autogen.

# Include the progress variables for this target.
include test/CMakeFiles/testUser_autogen.dir/progress.make

test/CMakeFiles/testUser_autogen: test/gtest-1.6.0/libgtest.a
test/CMakeFiles/testUser_autogen: test/gtest-1.6.0/libgtest_main.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ivan/Projects/SecureChat/SecureChat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and RCC for target testUser"
	cd /home/ivan/Projects/SecureChat/SecureChat/build/test && /usr/bin/cmake -E cmake_autogen /home/ivan/Projects/SecureChat/SecureChat/build/test/CMakeFiles/testUser_autogen.dir ""

testUser_autogen: test/CMakeFiles/testUser_autogen
testUser_autogen: test/CMakeFiles/testUser_autogen.dir/build.make

.PHONY : testUser_autogen

# Rule to build all files generated by this target.
test/CMakeFiles/testUser_autogen.dir/build: testUser_autogen

.PHONY : test/CMakeFiles/testUser_autogen.dir/build

test/CMakeFiles/testUser_autogen.dir/clean:
	cd /home/ivan/Projects/SecureChat/SecureChat/build/test && $(CMAKE_COMMAND) -P CMakeFiles/testUser_autogen.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/testUser_autogen.dir/clean

test/CMakeFiles/testUser_autogen.dir/depend:
	cd /home/ivan/Projects/SecureChat/SecureChat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/Projects/SecureChat/SecureChat /home/ivan/Projects/SecureChat/SecureChat/test /home/ivan/Projects/SecureChat/SecureChat/build /home/ivan/Projects/SecureChat/SecureChat/build/test /home/ivan/Projects/SecureChat/SecureChat/build/test/CMakeFiles/testUser_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testUser_autogen.dir/depend
