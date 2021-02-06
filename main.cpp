#include "library.h"
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <map>
#include "rb_tree.h"




int main() {
//	ft::rb_tree<std::pair<int, std::string> > bst;
//	bst.insert_data(std::pair<int, std::string>(61, "hola"));
//	bst.insert_data(std::pair<int, std::string>(52, "sup"));
//	bst.insert_data(std::pair<int, std::string>(85, "gme"));
//	bst.insert_data(std::pair<int, std::string>(20, "lol"));
//	bst.insert_data(std::pair<int, std::string>(55, "ans"));
//	bst.insert_data(std::pair<int, std::string>(76, "elo"));
//	bst.insert_data(std::pair<int, std::string>(93, "wsb"));
//	bst.insert_data(std::pair<int, std::string>(12, "wsb"));
//	bst.insert_data(std::pair<int, std::string>(71, "wsb"));
//	bst.insert_data(std::pair<int, std::string>(81, "wsb"));
//	bst.insert_data(std::pair<int, std::string>(90, "wsb"));
//	bst.insert_data(std::pair<int, std::string>(101, "wsb"));
//	bst.insert_data(std::pair<int, std::string>(65, "wsb"));
//
//	bst.print(bst.get_root(), 1);
//	bst.delete_node(std::pair<int, std::string>(85, "gme"));
//	std::cout << "----" << std::endl;
//	bst.print(bst.get_root(), 1);
//	bst.delete_node(std::pair<int, std::string>(55, "ans"));
//	std::cout << "----" << std::endl;
//	bst.print(bst.get_root(), 1);
//	bst.delete_node(std::pair<int, std::string>(76, "elo"));
//	std::cout << "----" << std::endl;
//	bst.print(bst.get_root(), 1);

	std::map<int, std::string> m;

	m.insert(std::pair<int, std::string>(1, "l"));
	m.insert(std::pair<int, std::string>(3, "s"));
	m.insert(std::pair<int, std::string>(4, "p"));
	m.insert(std::pair<int, std::string>(2, "n"));
	m.insert(std::pair<int, std::string>(5, "l"));

	for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	return (0);
}