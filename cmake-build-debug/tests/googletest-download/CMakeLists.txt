cmake_minimum_required(VERSION 2.8.12)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/googletest-src"
        BINARY_DIR        "/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt googletest-download/CMakeLists.txt)
execute_process(COMMAND /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -G "Unix Makefiles" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ")
endif()
execute_process(COMMAND /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(/Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/googletest-src
        /Users/tuanperera/Documents/42/gh_containers/cmake-build-debug/tests/googletest-build
        EXCLUDE_FROM_ALL)

add_executable(Google_Tests_run list_tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)

target_link_libraries(Google_Tests_run _containers)



