//
// Created by Tuan Perera on 27.02.21.
//

#include <queue>
#include "gtest/gtest.h"
#include "../library.h"

TEST(QueueTest, CapacityTests) {
	ft::queue<int> fs;
	std::queue<int> ss;

	for (int i = 0; i < 20; i++) {
		fs.push(i);
		ss.push(i);
	}

	ASSERT_TRUE(fs.size() == ss.size()) << "Size: incorrect return";
	ASSERT_TRUE(fs.empty() == ss.empty()) << "Empty: incorrect return";
	fs.pop();
	ss.pop();
	ASSERT_TRUE(fs.size() == ss.size()) << "Size: incorrect return after pop";
}

TEST(QueueTest, ElementAccessTests) {
	ft::queue<int> fs;
	std::queue<int> ss;

	for (int i = 0; i < 20; i++) {
		fs.push(i);
		ss.push(i);
	}

	ASSERT_TRUE(fs.front() == ss.front()) << "Front: incorrect return";
	ASSERT_TRUE(fs.back() == ss.back()) << "Back: incorrect return";
}

TEST(QueueTest, OperatorTests) {
	ft::queue<int> fs1;
	std::queue<int> ss1;
	ft::queue<int> fs;
	std::queue<int> ss;

	for (int i = 0; i < 20; i++) {
		fs.push(i);
		ss.push(i);
	}

	for (int i = 0; i < 10; i++) {
		fs1.push(i);
		ss1.push(i);
	}
	ASSERT_TRUE((fs1 == fs) == (ss1 == ss));
	ASSERT_TRUE((fs1 != fs) == (ss1 != ss));
	ASSERT_TRUE((fs1 >= fs) == (ss1 >= ss));
	ASSERT_TRUE((fs1 > fs) == (ss1 > ss));
	ASSERT_TRUE((fs1 <= fs) == (ss1 <= ss));
	ASSERT_TRUE((fs1 < fs) == (ss1 < ss)) << "Less than: ft: " << (fs1 < fs) << " std: " << (ss1 < ss) << "\n";
}