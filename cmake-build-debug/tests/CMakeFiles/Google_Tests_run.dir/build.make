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
include tests/CMakeFiles/Google_Tests_run.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/Google_Tests_run.dir/flags.make

tests/CMakeFiles/Google_Tests_run.dir/list_tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/list_tests.cpp.o: ../tests/list_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/list_tests.cpp.o"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/list_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/list_tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/list_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/list_tests.cpp.i"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/list_tests.cpp > CMakeFiles/Google_Tests_run.dir/list_tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/list_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/list_tests.cpp.s"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/list_tests.cpp -o CMakeFiles/Google_Tests_run.dir/list_tests.cpp.s

tests/CMakeFiles/Google_Tests_run.dir/set_tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/set_tests.cpp.o: ../tests/set_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/set_tests.cpp.o"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/set_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/set_tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/set_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/set_tests.cpp.i"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/set_tests.cpp > CMakeFiles/Google_Tests_run.dir/set_tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/set_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/set_tests.cpp.s"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/set_tests.cpp -o CMakeFiles/Google_Tests_run.dir/set_tests.cpp.s

tests/CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.o: ../tests/vector_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.o"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/vector_tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.i"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/vector_tests.cpp > CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.s"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/vector_tests.cpp -o CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.s

tests/CMakeFiles/Google_Tests_run.dir/map_tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/map_tests.cpp.o: ../tests/map_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/map_tests.cpp.o"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/map_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/map_tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/map_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/map_tests.cpp.i"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/map_tests.cpp > CMakeFiles/Google_Tests_run.dir/map_tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/map_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/map_tests.cpp.s"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/map_tests.cpp -o CMakeFiles/Google_Tests_run.dir/map_tests.cpp.s

tests/CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.o: ../tests/stack_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.o"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/stack_tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.i"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/stack_tests.cpp > CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.s"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/stack_tests.cpp -o CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.s

tests/CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.o: ../tests/queue_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.o"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.o -c /Users/tuanperera/Documents/42/gh_containers/tests/queue_tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.i"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuanperera/Documents/42/gh_containers/tests/queue_tests.cpp > CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.s"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuanperera/Documents/42/gh_containers/tests/queue_tests.cpp -o CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/list_tests.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/set_tests.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/map_tests.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/list_tests.cpp.o
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/set_tests.cpp.o
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/vector_tests.cpp.o
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/map_tests.cpp.o
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/stack_tests.cpp.o
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/queue_tests.cpp.o
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/build.make
../Google_Tests_run: lib/libgtestd.a
../Google_Tests_run: lib/libgtest_maind.a
../Google_Tests_run: lib/libgtestd.a
../Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../../Google_Tests_run"
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/Google_Tests_run.dir/build: ../Google_Tests_run

.PHONY : tests/CMakeFiles/Google_Tests_run.dir/build

tests/CMakeFiles/Google_Tests_run.dir/clean:
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Google_Tests_run.dir/clean

tests/CMakeFiles/Google_Tests_run.dir/depend:
	cd /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tuanperera/Documents/42/gh_containers /Users/tuanperera/Documents/42/gh_containers/tests /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Google_Tests_run.dir/depend

