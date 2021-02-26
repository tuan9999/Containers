cmake_minimum_required(VERSION 3.17)
project(containers)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -O1 -fno-omit-frame-pointer -g")

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_executable(${PROJECT_NAME}
        main.cpp
        library.cpp
        library.h
        set/multiset.h
        set/multiset_tree_node.h
        set/multiset_tree.h
        set/set.h pair/pair.h
        deque/deque.h
        deque/random_access_iterator_deque.h
        stack/stack.h
        queue/queue.h
        list/list.hpp
        list/list_element.h
        iterators/iterator.h
        iterators/input_iterator.h
        iterators/output_iterator.h
        iterators/forward_iterator.h
        iterators/bidirectional_iterator.h
        iterators/random_access_iterator.h
        list/list_iterator.h
        list/reverse_list_iterator.h
        list/traits.h
        vector/vector.hpp
        vector/random_access_iterator.hpp
        map/map.h
        map/map_node.h
        utils/bidirectional_iterator.h
        map/rb_tree.h
        queue/queue.h
        stack/stack.h
        deque/deque.h
        deque/random_access_iterator_deque.h
        pair/pair.h
        set/set.h
        set/set_tree.h
        set/multiset_tree.h
        set/multiset.h
        set/multiset_tree_node.h
        map/multimap.h
        map/multimap_tree.h
        map/multimap_node.h)

#add_library(_containers STATIC library.cpp
#        library.h
#        set/multiset.h
#        set/multiset_tree_node.h
#        set/multiset_tree.h
#        set/set.h pair/pair.h
#        deque/deque.h
#        deque/random_access_iterator_deque.h
#        stack/stack.h
#        queue/queue.h
#        list/list.hpp
#        tests/list_tests.cpp
#        list/list_element.h
#        iterators/iterator.h
#        iterators/input_iterator.h
#        iterators/output_iterator.h
#        iterators/forward_iterator.h
#        iterators/bidirectional_iterator.h
#        iterators/random_access_iterator.h
#        list/list_iterator.h
#        list/reverse_list_iterator.h
#        list/traits.h
#        vector/vector.hpp
#        vector/random_access_iterator.hpp
#        map/map.h
#        map/map_node.h
#        utils/bidirectional_iterator.h
#        map/rb_tree.h
#        queue/queue.h
#        stack/stack.h
#        deque/deque.h
#        deque/random_access_iterator_deque.h
#        pair/pair.h
#        set/set.h
#        set/set_tree.h
#        set/multiset_tree.h
#        set/multiset.h
#        set/multiset_tree_node.h
#        map/multimap.h
#        map/multimap_tree.h
#        map/multimap_node.h
#        tests/list_tests.cpp
#        )

include_directories(list vector map utils queue stack deque pair set)

#find_library(LIB lib_containers cmake-build-debug)
#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${LIB})

add_subdirectory(tests)
