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

# Include any dependencies generated for this target.
include CMakeFiles/_containers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_containers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_containers.dir/flags.make

CMakeFiles/_containers.dir/library.cpp.o: CMakeFiles/_containers.dir/flags.make
CMakeFiles/_containers.dir/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_containers.dir/library.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_containers.dir/library.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/library.cpp

CMakeFiles/_containers.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_containers.dir/library.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/library.cpp > CMakeFiles/_containers.dir/library.cpp.i

CMakeFiles/_containers.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_containers.dir/library.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/library.cpp -o CMakeFiles/_containers.dir/library.cpp.s

CMakeFiles/_containers.dir/tests/list_tests.cpp.o: CMakeFiles/_containers.dir/flags.make
CMakeFiles/_containers.dir/tests/list_tests.cpp.o: ../tests/list_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/_containers.dir/tests/list_tests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_containers.dir/tests/list_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/list_tests.cpp

CMakeFiles/_containers.dir/tests/list_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_containers.dir/tests/list_tests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/list_tests.cpp > CMakeFiles/_containers.dir/tests/list_tests.cpp.i

CMakeFiles/_containers.dir/tests/list_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_containers.dir/tests/list_tests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/list_tests.cpp -o CMakeFiles/_containers.dir/tests/list_tests.cpp.s

# Object files for target _containers
_containers_OBJECTS = \
"CMakeFiles/_containers.dir/library.cpp.o" \
"CMakeFiles/_containers.dir/tests/list_tests.cpp.o"

# External object files for target _containers
_containers_EXTERNAL_OBJECTS =

lib_containers.a: CMakeFiles/_containers.dir/library.cpp.o
lib_containers.a: CMakeFiles/_containers.dir/tests/list_tests.cpp.o
lib_containers.a: CMakeFiles/_containers.dir/build.make
lib_containers.a: CMakeFiles/_containers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library lib_containers.a"
	$(CMAKE_COMMAND) -P CMakeFiles/_containers.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_containers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_containers.dir/build: lib_containers.a

.PHONY : CMakeFiles/_containers.dir/build

CMakeFiles/_containers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_containers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_containers.dir/clean

CMakeFiles/_containers.dir/depend:
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tuanperera/Documents/42/gh_containers /Users/tuanperera/Documents/42/gh_containers /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles/_containers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_containers.dir/depend

