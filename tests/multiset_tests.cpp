//
// Created by Tuan Perera on 08.04.21.
//

#include <set>
#include "gtest/gtest.h"
#include "../library.h"

TEST(MultiSetTest, ContructorTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);

	ft::multiset<int> fs2(fs1.begin(), fs1.end());
	std::multiset<int> ss2(ss1.begin(), ss1.end());
	ft::multiset<int>::iterator fit = fs2.begin();
	std::multiset<int>::iterator sit = ss2.begin();
	while (fit != fs2.end()) {
		ASSERT_TRUE(*fit == *sit) << "Iterator constructor: ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(MultiSetTest, IteratorTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);

	ft::multiset<int>::iterator fit = fs1.begin();
	std::multiset<int>::iterator sit = ss1.begin();
	while (fit != fs1.end()) {
		ASSERT_TRUE(*fit == *sit) << "Iterator: ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ft::multiset<int>::reverse_iterator rfit = fs1.rbegin();
	std::multiset<int>::reverse_iterator rsit = ss1.rbegin();
	while (rfit != fs1.rend()) {
		ASSERT_TRUE(*rfit == *rsit) << "Reverse iterator: ft: " << *fit << " std: " << *sit << "\n";
		rfit++;
		rsit++;
	}
}

TEST(MultiSetTest, CapacityTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);

	ASSERT_TRUE(fs1.empty() == ss1.empty()) << "Size: ft: " << fs1.empty() << " std: " << ss1.empty() << "\n";
	ASSERT_TRUE(fs1.size() == ss1.size()) << "Size: ft: " << fs1.size() << " std: " << ss1.size() << "\n";
}

TEST(MultiSetTest, InsertTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);

	ft::multiset<int> fs2;
	std::multiset<int> ss2;

	fs2.insert(fs1.begin(), fs1.end());
	ss2.insert(ss1.begin(), ss1.end());

	ft::multiset<int>::iterator fit = fs2.begin();
	std::multiset<int>::iterator sit = ss2.begin();
	while (fit != fs2.end()) {
		ASSERT_TRUE(*fit == *sit) << "Insert iterators: Failed with ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(MultiSetTest, EraseTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);

	fs1.erase(fs1.begin());
	ss1.erase(ss1.begin());

	ft::multiset<int>::iterator fit = fs1.begin();
	std::multiset<int>::iterator sit = ss1.begin();
	while (fit != fs1.end()) {
		ASSERT_TRUE(*fit == *sit) << "Erase pos: Failed with ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(MultiSetTest, SwapTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;
	ft::multiset<int> fs2;
	std::multiset<int> ss2;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);

	fs2.insert(11);
	fs2.insert(14);

	ss2.insert(11);
	ss2.insert(14);

	fs1.swap(fs2);
	ss1.swap(ss2);

	ft::multiset<int>::iterator fit = fs1.begin();
	std::multiset<int>::iterator sit = ss1.begin();
	while (fit != fs1.end()) {
		ASSERT_TRUE(*fit == *sit) << "Swap: Failed with ft: " << *fit << " std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(MultiSetTest, ClearTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(20);

	fs1.clear();
	ss1.clear();

	ASSERT_TRUE(fs1.size() == ss1.size()) << "Clear: Failed with ft: " << fs1.size() << " std: " << ss1.size() << "\n";
}

TEST(MultiSetTest, FindTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);


	ASSERT_TRUE(*(fs1.find(20)) == *(ss1.find(20))) << "Find: Failed with ft: " << *(fs1.find(20)) << " std: " << *(ss1.find(20)) << "\n";
}

TEST(MultiSetTest, CountTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);


	ASSERT_TRUE((fs1.count(20)) == (ss1.count(20))) << "Count: Failed with ft: " << (fs1.count(20)) << " std: " << (ss1.count(20)) << "\n";
}

TEST(MultiSetTest, BoundTests) {
	ft::multiset<int> fs1;
	std::multiset<int> ss1;

	fs1.insert(230);
	fs1.insert(230);
	fs1.insert(20);

	ss1.insert(230);
	ss1.insert(230);
	ss1.insert(20);


	ASSERT_TRUE(*(fs1.lower_bound(20)) == *(ss1.lower_bound(20))) << "Lower bound: Failed with ft: " << *(fs1.lower_bound(20)) << " std: " << *(ss1.lower_bound(20)) << "\n";
}
