# Containers
My implementation of the standard template library containers:
- [List](https://www.cplusplus.com/reference/list/list/)
- [Vector](https://www.cplusplus.com/reference/vector/vector/)
- [Map](https://www.cplusplus.com/reference/map/map/)
- [Stack](https://www.cplusplus.com/reference/stack/stack/)
- [Queue](https://www.cplusplus.com/reference/queue/queue/)
- [Set](https://www.cplusplus.com/reference/set/set/)
- [Multiset](https://www.cplusplus.com/reference/set/multiset/)
- [Multimap](https://www.cplusplus.com/reference/map/multimap/)
- [Deque](https://www.cplusplus.com/reference/deque/deque/)

## Usage
Run the following commands starting at the root of the repository:
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

This will result in two executables being built at the root of the repository:
- **containers**, which is the executable built using the library and the provided main.cpp file.
- **Google_Test_run**, which is the executable built using the library and the provided tests in the tests folder.