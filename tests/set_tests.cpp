//
// Created by Tuan Perera on 27.02.21.
//

#include <set>
#include "gtest/gtest.h"
#include "../library.h"

TEST(SetTest, ContructorTests) {
	ft::set<int> fs1;
	std::set<int> ss1;

	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(20);

	ft::set<int> fs2(fs1.begin(), fs1.end());
	std::set<int> ss2(ss1.begin(), ss1.end());
	ft::set<int>::iterator fit = fs2.begin();
	std::set<int>::iterator sit = ss2.begin();
	while (fit != fs2.end()) {
		ASSERT_TRUE(*fit == *sit) << "Iterator constructor: ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(SetTest, IteratorTests) {
	ft::set<int> fs1;
	std::set<int> ss1;

	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(20);

	ft::set<int>::iterator fit = fs1.begin();
	std::set<int>::iterator sit = ss1.begin();
	while (fit != fs1.end()) {
		ASSERT_TRUE(*fit == *sit) << "Iterator: ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ft::set<int>::reverse_iterator rfit = fs1.rbegin();
	std::set<int>::reverse_iterator rsit = ss1.rbegin();
	while (rfit != fs1.rend()) {
		ASSERT_TRUE(*rfit == *rsit) << "Reverse iterator: ft: " << *fit << " std: " << *sit << "\n";
		rfit++;
		rsit++;
	}
}

TEST(SetTest, CapacityTests) {
	ft::set<int> fs1;
	std::set<int> ss1;

	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(20);

	ASSERT_TRUE(fs1.empty() == ss1.empty()) << "Size: ft: " << fs1.empty() << " std: " << ss1.empty() << "\n";
	ASSERT_TRUE(fs1.size() == ss1.size()) << "Size: ft: " << fs1.size() << " std: " << ss1.size() << "\n";
}

TEST(SetTest, InsertTests) {
	ft::set<int> fs1;
	std::set<int> ss1;

	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(20);

	ft::set<int> fs2;
	std::set<int> ss2;

	fs2.insert(fs1.begin(), fs1.end());
	ss2.insert(ss1.begin(), ss1.end());

	ft::set<int>::iterator fit = fs2.begin();
	std::set<int>::iterator sit = ss2.begin();
	while (fit != fs2.end()) {
		ASSERT_TRUE(*fit == *sit) << "Insert iterators: Failed with ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(SetTest, EraseTests) {
	ft::set<int> fs1;
	std::set<int> ss1;

	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(20);

	fs1.erase(fs1.begin());
	ss1.erase(ss1.begin());

	ft::set<int>::iterator fit = fs1.begin();
	std::set<int>::iterator sit = ss1.begin();
	while (fit != fs1.end()) {
		ASSERT_TRUE(*fit == *sit) << "Erase pos: Failed with ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}