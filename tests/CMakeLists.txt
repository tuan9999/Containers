set(Boost_USE_STATIC_LIBS OFF) #enable dynamic linking
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# search for unit_test_framework
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

# create a list_tests target from test.cpp
add_executable(list_tests list_tests.cpp)

# link Boost libraries to the new target
target_link_libraries(list_tests ${Boost_LIBRARIES})

# link Boost with code library
target_link_libraries(list_tests _containers)

