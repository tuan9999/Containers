#include "library.h"
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <map>
#include "rb_tree.h"
#include "pair.h"

void testtree() {
	ft::rb_tree<int, std::string, std::pair<int, std::string> > bst;
	bst.insert_data(std::pair<int, std::string>(61, "hola"));
	bst.insert_data(std::pair<int, std::string>(52, "sup"));
	bst.insert_data(std::pair<int, std::string>(85, "gme"));
	bst.insert_data(std::pair<int, std::string>(20, "lol"));
	bst.insert_data(std::pair<int, std::string>(55, "ans"));
	bst.insert_data(std::pair<int, std::string>(76, "elo"));
	bst.insert_data(std::pair<int, std::string>(93, "wsb"));
	bst.insert_data(std::pair<int, std::string>(12, "wsb"));
	bst.insert_data(std::pair<int, std::string>(71, "wsb"));
	bst.insert_data(std::pair<int, std::string>(81, "wsb"));
	bst.insert_data(std::pair<int, std::string>(90, "wsb"));
	bst.insert_data(std::pair<int, std::string>(101, "wsb"));
	bst.insert_data(std::pair<int, std::string>(65, "wsb"));
	bst.print(bst.get_root(), 1);


	bst.delete_node(std::pair<int, std::string>(85, "gme"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(61, "ans"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(55, "elo"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(101, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(12, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(81, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(76, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(65, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(90, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(20, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(93, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(71, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(52, "wsb"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
}

void test_tree2() {
	ft::rb_tree<int, std::string, std::pair<int, std::string> > bst;
	bst.insert_data(std::pair<int, std::string>(10, "hola"));
	bst.insert_data(std::pair<int, std::string>(15, "sup"));
	bst.insert_data(std::pair<int, std::string>(85, "gme"));
	bst.print(bst.get_root(), 1);

	bst.delete_node(std::pair<int, std::string>(61, "ans"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
	bst.delete_node(std::pair<int, std::string>(52, "ans"));
	std::cout << "----" << std::endl;
	bst.print(bst.get_root(), 1);
}


int main() {
//	testtree();
	ft::map<int, std::string> m;
	ft::pair<int, std::string> v = ft::pair<int, std::string>(10, "one");
	m.insert(v);
	v = ft::pair<int, std::string>(15, "two");
	m.insert(v);
	m.insert(ft::pair<int, std::string>(5, "two"));
	m.print();
	m.insert(ft::pair<int, std::string>(35, "two"));
	m.erase(35);
	std::cout << (m.count(80)) << std::endl;
	m.print();
	for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
//	m.insert(ft::pair<int, std::string>(25, "two"));
//	m.insert(ft::pair<int, std::string>(50, "two"));

	return (0);
}