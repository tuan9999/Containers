# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tuanperera/Documents/42/gh_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug

# Utility rule file for NightlyMemoryCheck.

# Include the progress variables for this target.
include tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/progress.make

tests/Catch2/CMakeFiles/NightlyMemoryCheck:
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/Catch2 && /Applications/CLion.app/Contents/bin/cmake/mac/bin/ctest -D NightlyMemoryCheck

NightlyMemoryCheck: tests/Catch2/CMakeFiles/NightlyMemoryCheck
NightlyMemoryCheck: tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/build.make

.PHONY : NightlyMemoryCheck

# Rule to build all files generated by this target.
tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/build: NightlyMemoryCheck

.PHONY : tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/build

tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/clean:
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/Catch2 && $(CMAKE_COMMAND) -P CMakeFiles/NightlyMemoryCheck.dir/cmake_clean.cmake
.PHONY : tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/clean

tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/depend:
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tuanperera/Documents/42/gh_containers /Users/tuanperera/Documents/42/gh_containers/tests/Catch2 /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/Catch2 /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/Catch2/CMakeFiles/NightlyMemoryCheck.dir/depend

