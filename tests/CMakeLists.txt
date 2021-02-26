cmake_minimum_required(VERSION 2.8.12)

project(googletest-download)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run list_tests.cpp vector_tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)



