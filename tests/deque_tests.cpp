//
// Created by Tuan Perera on 08.04.21.
//

#include <deque>
#include "gtest/gtest.h"
#include "../library.h"

TEST(DequeTest, ConstructorTests) {
	ft::deque<int> ri = ft::deque<int>(5, 10);
	std::deque<int> si = std::deque<int>(5, 10);

	ft::deque<int>::iterator 	fit = ri.begin();
	std::deque<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Fill: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	ft::deque<int> cri = ft::deque<int>(ri);
	std::deque<int> csi = std::deque<int>(si);
	fit = cri.begin();
	sit = csi.begin();
	while (sit != csi.end()) {
		ASSERT_TRUE(*fit == *sit) << "Copy: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(DequeTest, OperatorTests) {
	ft::deque<int> ri;
	std::deque<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::deque<int> ri2 = ri;
	std::deque<int> si2 = si;

	ASSERT_TRUE((ri == ri2) == (si == si2)) << "Equality comparison: Failed with ft: " << (ri == ri2) << ", std: " << (si == si2) << "\n";
	ASSERT_TRUE((ri != ri2) == (si != si2)) << "Inequality comparison: Failed with ft: " << (ri != ri2) << ", std: " << (si != si2) << "\n";
	ASSERT_TRUE((ri >= ri2) == (si >= si2)) << "Greater than or equal comparison: Failed with ft: " << (ri >= ri2) << ", std: " << (si >= si2) << "\n";
	ASSERT_TRUE((ri <= ri2) == (si <= si2)) << "Less than or equal comparison: Failed with ft: " << (ri <= ri2) << ", std: " << (si <= si2) << "\n";
	ASSERT_TRUE((ri < ri2) == (si < si2)) << "Less than comparison: Failed with ft: " << (ri < ri2) << ", std: " << (si < si2) << "\n";
	ASSERT_TRUE((ri > ri2) == (si > si2)) << "Greater than comparison: Failed with ft: " << (ri > ri2) << ", std: " << (si > si2) << "\n";
}

TEST(DequeTest, CapacityTests) {
	ft::deque<int> ri = ft::deque<int>(5, 10);
	std::deque<int> si = std::deque<int>(5, 10);

	ASSERT_TRUE(ri.empty() == si.empty()) << "Empty: Failed with ft: " << ri.empty() << ", std: " << si.empty() << "\n";
	ASSERT_TRUE(ri.size() == si.size()) << "Size: Failed with ft: " << ri.size() << ", std: " << si.size() << "\n";
}

TEST(DequeTest, ElementAccessTests) {
	ft::deque<int> ri;
	std::deque<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ASSERT_TRUE(ri.front() == si.front()) << "Front: Failed with ft: " << ri.front() << ", std: " << si.front() << "\n";
	ASSERT_TRUE(ri.back() == si.back()) << "Front: Failed with ft: " << ri.back() << ", std: " << si.back() << "\n";
}

TEST(DequeTest, AssignTests) {
	ft::deque<int> ri;
	std::deque<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::deque<int> test_ft;
	std::deque<int> test_std;

	test_ft.assign(ri.begin(), ri.end());
	test_std.assign(si.begin(), si.end());
	ft::deque<int>::iterator 	fit = test_ft.begin();
	std::deque<int>::iterator	sit = test_std.begin();
	while (sit != test_std.end()) {
		ASSERT_TRUE(*fit == *sit) << "Assign: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	test_ft.assign(20, 1);
	test_std.assign(20, 1);
	ASSERT_TRUE(test_std.size() == test_ft.size()) << "Size after assign: Failed with ft:" << test_ft.size() << ", std:" << test_std.size() << "\n";
	fit = test_ft.begin();
	sit = test_std.begin();
	while (sit != test_std.end()) {
		ASSERT_TRUE(*fit == *sit) << "Assign: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(DequeTest, PushPopClearTests) {
	ft::deque<int> ri;
	std::deque<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::deque<int>::iterator 	fit = ri.begin();
	std::deque<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Push back: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
	si.clear();
	ri.clear();
	ASSERT_TRUE(ri.size() == si.size()) << "Push back: Failed with ft:" << ri.size() << ", std:" << si.size() << "\n";
	for (int i = 0; i < 10; i++) {
		ri.push_front(i);
		si.push_front(i);
	}

	fit = ri.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Push front: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	si.pop_back();
	ri.pop_back();

	fit = ri.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Pop back: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	si.pop_front();
	ri.pop_front();

	fit = ri.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Pop front: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(DequeTest, InsertTests) {
	ft::deque<int> fi;
	std::deque<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.insert(fi.begin(), 30);
	si.insert(si.begin(), 30);

	ft::deque<int>::iterator 	fit = fi.begin();
	std::deque<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Insert single: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	fi.insert(fi.end(), 5, 30);
	si.insert(si.end(), 5, 30);

	fit = fi.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Insert multiple: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	ft::deque<int> ftmp = ft::deque<int>(5, 5);
	std::deque<int> stmp = std::deque<int>(5, 5);

	fi.insert(fi.begin(), ftmp.begin(), ftmp.end());
	si.insert(si.begin(), stmp.begin(), stmp.end());

	fit = fi.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Insert iterators: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(DequeTest, EraseTests) {
	ft::deque<int> fi;
	std::deque<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.erase(fi.begin());
	si.erase(si.begin());

	ft::deque<int>::iterator 	fit = fi.begin();
	std::deque<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Erase single: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	fi.erase(fi.begin(), fi.end());
	si.erase(si.begin(), si.end());
	ASSERT_TRUE(fi.size() == si.size()) << "Erase multiple: Failed with ft:" << fi.size() << ", std:" << si.size() << "\n";
}

TEST(DequeTest, SwapTests) {
	ft::deque<int> f1, f2;
	std::deque<int> s1, s2;

	for (int i = 0; i < 10; i++) {
		f1.push_back(i);
		s1.push_back(i);
	}

	for (int i = 30; i != 40; i++) {
		s2.push_back(i);
		f2.push_back(i);
	}

	s1.swap(s2);
	f1.swap(f2);

	ft::deque<int>::iterator 	fit = f1.begin();
	std::deque<int>::iterator	sit = s1.begin();

	while (fit != f1.end()) {
		ASSERT_TRUE(*sit == *fit) << "Swap internal: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		sit++;
		fit++;
	}
}

TEST(DequeTest, ResizeTests) {
	ft::deque<int> fi;
	std::deque<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.resize(5);
	si.resize(5);

	ft::deque<int>::iterator 	fit = fi.begin();
	std::deque<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Resize to smaller: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	fi.resize(15, 30);
	si.resize(15, 30);

	fit = fi.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Resize to larger: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}
