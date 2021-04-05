//
// Created by Tuan Perera on 27.02.21.
//

#include <stack>
#include "gtest/gtest.h"
#include "../library.h"

TEST(StackTest, CapacityTests) {
	ft::stack<int> fs;
	std::stack<int> ss;

	for (int i = 0; i < 20; i++) {
		fs.push(i);
		ss.push(i);
	}

	ASSERT_TRUE(fs.size() == ss.size()) << "Size: incorrect return";
	ASSERT_TRUE(fs.empty() == ss.empty()) << "Empty: incorrect return";
}

TEST(StackTest, AccessTests) {
	ft::stack<int> fs;
	std::stack<int> ss;

	for (int i = 0; i < 20; i++) {
		fs.push(i);
		ss.push(i);
	}

	ASSERT_TRUE(fs.top() == ss.top()) << "Top: incorrect return";
	fs.pop();
	ss.pop();
	ASSERT_TRUE(fs.size() == ss.size()) << "Size: incorrect return after pop";
}

TEST(StackTest, OperatorTests) {
	ft::stack<int> fs1;
	std::stack<int> ss1;
	ft::stack<int> fs;
	std::stack<int> ss;

	for (int i = 0; i < 20; i++) {
		fs.push(i);
		ss.push(i);
	}

	for (int i = 0; i < 20; i++) {
		fs1.push(i);
		ss1.push(i);
	}
	ASSERT_TRUE((fs1 == fs) == (ss1 == ss));
	ASSERT_TRUE((fs1 != fs) == (ss1 != ss));
	ASSERT_TRUE((fs1 >= fs) == (ss1 >= ss));
	ASSERT_TRUE((fs1 > fs) == (ss1 > ss));
	ASSERT_TRUE((fs1 <= fs) == (ss1 <= ss));
	ASSERT_TRUE((fs1 < fs) == (ss1 < ss));
}
