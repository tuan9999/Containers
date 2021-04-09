#include "library.h"
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <map>
#include <set>
#include "rb_tree.h"

void test_tree2() {
	ft::multimap_tree<int, std::string, std::pair<int, std::string> > bst;
	bst.insert_data(std::pair<int, std::string>(10, "hola"));
	bst.insert_data(std::pair<int, std::string>(10, "lola"));
	bst.insert_data(std::pair<int, std::string>(15, "sup"));
	bst.insert_data(std::pair<int, std::string>(85, "gme"));
	bst.print(bst.get_root(), 1);

	bst.delete_node(std::pair<int, std::string>(85, "ans"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(15, "ans"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
}


int main() {
	test_tree2();


	return (0);
}