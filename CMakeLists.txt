cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")


add_executable(containers_test main.cpp)

add_library(_containers STATIC library.cpp library.h list/list.hpp tests/list_tests.cpp list/list_element.h iterators/iterator.h iterators/input_iterator.h iterators/output_iterator.h iterators/forward_iterator.h iterators/bidirectional_iterator.h iterators/random_access_iterator.h list/list_iterator.h list/reverse_list_iterator.h list/traits.h vector/vector.hpp vector/random_access_iterator.hpp map/map.h map/map_node.h utils/bidirectional_iterator.h map/rb_tree.h)

include_directories(list vector map)

find_library(LIB lib_containers cmake-build-debug)
target_link_libraries(containers_test LINK_PUBLIC ${LIB})

add_subdirectory(tests)
