//
// Created by Tuan Perera on 21.02.21.
//

#include <list>
#include "gtest/gtest.h"
#include "../library.h"

bool single_digit(const int val) {
	return (val < 10);
}

bool comp(const int v1, const int v2) {
	return (v1 == v2);
}

bool rev(const int v1, const int v2) {
	return (v1 > v2);
}

TEST(ListTest, ConstructorTests) {
	ft::list<int> ri = ft::list<int>(5, 10);
	std::list<int> si = std::list<int>(5, 10);

	ft::list<int>::iterator 	fit = ri.begin();
	std::list<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Fill: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	ft::list<int> ri1 = ft::list<int>(ri.begin(), ri.end());
	std::list<int> si1 = std::list<int>(si.begin(), si.end());
	fit = ri1.begin();
	sit = si1.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Range: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ft::list<int> cri = ft::list<int>(ri);
	std::list<int> csi = std::list<int>(si);
	fit = cri.begin();
	sit = csi.begin();
	while (sit != csi.end()) {
		ASSERT_TRUE(*fit == *sit) << "Copy: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(ListTest, OperatorTests) {
	ft::list<int> ri;
	std::list<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::list<int> ri2 = ri;
	std::list<int> si2 = si;

	ASSERT_TRUE((ri == ri2) == (si == si2)) << "Equality comparison: Failed with ft: " << (ri == ri2) << ", std: " << (si == si2) << "\n";
	ASSERT_TRUE((ri != ri2) == (si != si2)) << "Inequality comparison: Failed with ft: " << (ri != ri2) << ", std: " << (si != si2) << "\n";
	ASSERT_TRUE((ri >= ri2) == (si >= si2)) << "Greater than or equal comparison: Failed with ft: " << (ri >= ri2) << ", std: " << (si >= si2) << "\n";
	ASSERT_TRUE((ri <= ri2) == (si <= si2)) << "Less than or equal comparison: Failed with ft: " << (ri <= ri2) << ", std: " << (si <= si2) << "\n";
	ASSERT_TRUE((ri < ri2) == (si < si2)) << "Less than comparison: Failed with ft: " << (ri < ri2) << ", std: " << (si < si2) << "\n";
	ASSERT_TRUE((ri > ri2) == (si > si2)) << "Greater than comparison: Failed with ft: " << (ri > ri2) << ", std: " << (si > si2) << "\n";
}

TEST(ListTest, CapacityTests) {
	ft::list<int> ri = ft::list<int>(5, 10);
	std::list<int> si = std::list<int>(5, 10);

	ASSERT_TRUE(ri.empty() == si.empty()) << "Empty: Failed with ft: " << ri.empty() << ", std: " << si.empty() << "\n";
	ASSERT_TRUE(ri.size() == si.size()) << "Size: Failed with ft: " << ri.size() << ", std: " << si.size() << "\n";
	ASSERT_TRUE(ri.max_size() == si.max_size()) << "Max size: Failed with ft: " << ri.max_size() << ", std: " << si.max_size() << "\n";
}

TEST(ListTest, ElementAccessTests) {
	ft::list<int> ri;
	std::list<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ASSERT_TRUE(ri.front() == si.front()) << "Front: Failed with ft: " << ri.front() << ", std: " << si.front() << "\n";
	ASSERT_TRUE(ri.back() == si.back()) << "Front: Failed with ft: " << ri.back() << ", std: " << si.back() << "\n";
}

TEST(ListTest, AssignTests) {
	ft::list<int> ri;
	std::list<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::list<int> test_ft;
	std::list<int> test_std;

	test_ft.assign(ri.begin(), ri.end());
	test_std.assign(si.begin(), si.end());
	ft::list<int>::iterator 	fit = test_ft.begin();
	std::list<int>::iterator	sit = test_std.begin();
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

TEST(ListTest, PushPopClearTests) {
	ft::list<int> ri;
	std::list<int> si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::list<int>::iterator 	fit = ri.begin();
	std::list<int>::iterator	sit = si.begin();
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

TEST(ListTest, InsertTests) {
	ft::list<int> fi;
	std::list<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.insert(fi.begin(), 30);
	si.insert(si.begin(), 30);

	ft::list<int>::iterator 	fit = fi.begin();
	std::list<int>::iterator	sit = si.begin();
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

	ft::list<int> ftmp = ft::list<int>(5, 5);
	std::list<int> stmp = std::list<int>(5, 5);

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

TEST(ListTest, EraseTests) {
	ft::list<int> fi;
	std::list<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.erase(fi.begin());
	si.erase(si.begin());

	ft::list<int>::iterator 	fit = fi.begin();
	std::list<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Erase single: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	fi.erase(fi.begin(), fi.end());
	si.erase(si.begin(), si.end());
	ASSERT_TRUE(fi.size() == si.size()) << "Erase multiple: Failed with ft:" << fi.size() << ", std:" << si.size() << "\n";
}

//TEST(ListTest, SwapTests) {
//	ft::list<int> f1, f2;
//	std::list<int> s1, s2;
//
//	for (int i = 0; i < 10; i++) {
//		f1.push_back(i);
//		s1.push_back(i);
//	}
//
//	for (int i = 30; i != 40; i++) {
//		s2.push_back(i);
//		f2.push_back(i);
//	}
//
//	s1.swap(s2);
//	f1.swap(f2);
//
//	ft::list<int>::iterator 	fit = f1.begin();
//	std::list<int>::iterator	sit = s1.begin();
//
//	while (sit != s1.end()) {
//		ASSERT_TRUE(*sit == *fit) << "Swap internal: Failed with ft:" << *fit << ", std:" << *sit << "\n";
//		sit++;
//		fit++;
//	}
//}

TEST(ListTest, ResizeTests) {
	ft::list<int> fi;
	std::list<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.resize(5);
	si.resize(5);

	ft::list<int>::iterator 	fit = fi.begin();
	std::list<int>::iterator	sit = si.begin();
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

TEST(ListTest, SpliceTests) {
	ft::list<int> f1, f2;
	std::list<int> s1, s2;

	for (int i = 0; i < 10; i++) {
		f1.push_back(i);
		s1.push_back(i);
		f2.push_back(i*2);
		s2.push_back(i*2);
	}

	f1.splice(f1.begin(), f2);
	s1.splice(s1.begin(), s2);

	ft::list<int>::iterator 	fit = f1.begin();
	std::list<int>::iterator	sit = s1.begin();

	while (sit != s1.end()) {
		ASSERT_TRUE(*sit == *fit) << "Splice whole list: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		sit++;
		fit++;
	}

	for (int i = 0; i < 10; i++) {
		f2.push_back(i*2);
		s2.push_back(i*2);
	}

	f1.splice(f1.begin(), f2, f2.begin());
	s1.splice(s1.begin(), s2, s2.begin());

	fit = f1.begin();
	sit = s1.begin();
	while (sit != s1.end()) {
		ASSERT_TRUE(*sit == *fit) << "Splice single item: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		sit++;
		fit++;
	}

	f1.splice(f1.begin(), f2, f2.begin(), f2.end());
	s1.splice(s1.begin(), s2, s2.begin(), s2.end());

	fit = f1.begin();
	sit = s1.begin();
	while (sit != s1.end()) {
		ASSERT_TRUE(*sit == *fit) << "Splice range: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		sit++;
		fit++;
	}
}

TEST(ListTest, RemoveTests) {
	ft::list<int> fi;
	std::list<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.remove(5);
	si.remove(5);

	ft::list<int>::iterator 	fit = fi.begin();
	std::list<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Remove: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	fi.remove_if(single_digit);
	si.remove_if(single_digit);

	fit = fi.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Remove if: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}

//TEST(ListTest, UniqueTests) {
//	ft::list<int> fi;
//	std::list<int> si;
//
//	for (int i = 0; i < 10; i++) {
//		fi.push_back(i);
//		fi.push_back(i);
//		si.push_back(i);
//		si.push_back(i);
//	}
//
//	fi.unique();
//	si.unique();
//
//	ft::list<int>::iterator 	fit = fi.begin();
//	std::list<int>::iterator	sit = si.begin();
//	while (sit != si.end()) {
//		ASSERT_TRUE(*fit == *sit) << "Unique: Failed with ft:" << *fit << ", std:" << *sit << "\n";
//		fit++;
//		sit++;
//	}
//}

TEST(ListTest, MergeTests) {
	ft::list<int> f1, f2;
	std::list<int> s1, s2;

	for (int i = 0; i < 10; i++) {
		f1.push_back(i);
		s1.push_back(i);
		f2.push_back(i*2);
		s2.push_back(i*2);
	}

	f1.merge(f2);
	s1.merge(s2);

	ft::list<int>::iterator 	fit = f1.begin();
	std::list<int>::iterator	sit = s1.begin();

	while (sit != s1.end()) {
		ASSERT_TRUE(*sit == *fit) << "Merge: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		sit++;
		fit++;
	}

	f1.clear();
	f2.clear();
	s1.clear();
	s2.clear();

	for (int i = 0; i < 10; i++) {
		f1.push_back(i);
		s1.push_back(i);
		f2.push_back(i*2);
		s2.push_back(i*2);
	}

	f1.merge(f2, comp);
	s1.merge(s2, comp);

	fit = f1.begin();
	sit = s1.begin();

	while (sit != s1.end()) {
		ASSERT_TRUE(*sit == *fit) << "Merge with compare: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		sit++;
		fit++;
	}
}

TEST(ListTest, SortTests) {
	ft::list<int> fi;
	std::list<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.push_back(3);
	fi.push_back(2);
	fi.push_back(12);
	si.push_back(3);
	si.push_back(2);
	si.push_back(12);

	fi.sort();
	si.sort();

	ft::list<int>::iterator 	fit = fi.begin();
	std::list<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Sort: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	fi.sort(rev);
	si.sort(rev);

	fit = fi.begin();
	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Sort with compare: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(ListTest, ReverseTests) {
	ft::list<int> fi;
	std::list<int> si;

	for (int i = 0; i < 10; i++) {
		fi.push_back(i);
		si.push_back(i);
	}

	fi.reverse();
	si.reverse();

	ft::list<int>::iterator 	fit = fi.begin();
	std::list<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Reverse: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(ListTest, IteratorTests) {
	ft::list<int>	ft_l;
	std::list<int>	std_l;
	for (int i = 0; i < 10; i++) {
		ft_l.push_back(i);
		std_l.push_back(i);
	}

	ft::list<int>::iterator 	ft_l_it = ft_l.begin();
	std::list<int>::iterator	std_l_it = std_l.begin();
	while (std_l_it != std_l.end()) {
		ASSERT_TRUE(*ft_l_it == *std_l_it);
		ft_l_it++;
		std_l_it++;
	}

	ft::list<int>::reverse_iterator 	fr_it = ft_l.rbegin();
	std::list<int>::reverse_iterator 	sr_it = std_l.rbegin();
	while (sr_it != std_l.rend()) {
		ASSERT_TRUE(*fr_it == *sr_it);
		fr_it++;
		sr_it++;
	}
}

int main() {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}