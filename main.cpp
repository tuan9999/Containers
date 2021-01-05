#include "library.h"
#include <list>

int main() {
    ft::list<int> l1;
    ft::list<int> l2;
    ft::list<int>::iterator it1;
	ft::list<int>::iterator it2;
	l1.push_back(50);
	l1.push_front(2);
	l1.push_front(10);
	ft::list<int> l3(l1.begin(), l1.end());
	it1 = l1.end();
	it1--;
	l2.insert(l2.begin(), l1.begin(), l1.end());
	int i = 1;
//	std::cout << "Before swap" << std::endl;
//	for (it1 = l1.begin(); it1 != l1.end(); ++it1) {
//		std::cout << i++ << " L1 = " << *it1 << std::endl;
//	}
//	std::cout << std::endl;
	for (it2 = l3.begin(); it2 != l3.end(); ++it2) {
		std::cout << i++ << " l3 = " << *it2 << std::endl;
	}

	std::cout << "\n--------STL--------" << std::endl;
	std::list<int> lt;
    std::list<int>::iterator itl;
    lt.push_back(50);
	lt.push_front(2);
	lt.push_front(10);
	itl = lt.end();
	itl--;
	std::list<int> lt2(lt.begin(), lt.end());
    for (itl = lt2.begin(); itl != lt2.end(); itl++) {
		std::cout << "STL = " << *itl << std::endl;
	}
    itl = lt.begin();
    itl++;
	lt.erase(itl, lt.end());
	for (itl = lt.begin(); itl != lt.end(); itl++) {
		std::cout << "STL = " << *itl << std::endl;
	}

    return 0;
}