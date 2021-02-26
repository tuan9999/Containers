//
// Created by Tuan Perera on 26.02.21.
//

#include <vector>
#include "gtest/gtest.h"
#include "../library.h"

TEST(VectorTest, ConstructorTests) {
	ft::vector<int> ri = ft::vector<int>(5, 10);
	std::vector<int> si = std::vector<int>(5, 10);

	ft::vector<int>::iterator 	fit = ri.begin();
	std::vector<int>::iterator	sit = si.begin();
	while (sit != si.end()) {
		ASSERT_TRUE(*fit == *sit) << "Fill: Failed with ft:" << *fit << ", std:" << *sit << "\n";
		fit++;
		sit++;
	}

	ft::vector<int> ri1 = ft::vector<int>(ri.begin(), ri.end());
	std::vector<int> si1 = std::vector<int>(si.begin(), si.end());
	fit = ri1.begin();
	sit = si1.begin();
	ASSERT_TRUE(ri1.size() == si1.size()) << "Range: Failed with size difference ft: " << ri1.size() << ", std: " << si1.size() << "\n";
	while (fit != ri1.end()) {
		ASSERT_TRUE(*fit == *sit) << "Range: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ft::vector<int> cri = ft::vector<int>(ri);
	std::vector<int> csi = std::vector<int>(si);
	fit = cri.begin();
	sit = csi.begin();
	while (sit != csi.end()) {
		ASSERT_TRUE(*fit == *sit) << "Copy: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, IteratorTests) {
	ft::vector<int>		ft_l;
	std::vector<int>	std_l;
	for (int i = 0; i < 10; i++) {
		ft_l.push_back(i);
		std_l.push_back(i);
	}

	ft::vector<int>::iterator 	ft_l_it = ft_l.begin();
	std::vector<int>::iterator	std_l_it = std_l.begin();
	while (std_l_it != std_l.end()) {
		ASSERT_TRUE(*ft_l_it == *std_l_it);
		ft_l_it++;
		std_l_it++;
	}

	ft::vector<int>::reverse_iterator 	fr_it = ft_l.rbegin();
	std::vector<int>::reverse_iterator 	sr_it = std_l.rbegin();
	while (sr_it != std_l.rend()) {
		ASSERT_TRUE(*fr_it == *sr_it);
		fr_it++;
		sr_it++;
	}
}

TEST(VectorTest, CapacityTests) {
	ft::vector<int>		ft_l;
	std::vector<int>	std_l;
	for (int i = 0; i < 10; i++) {
		ft_l.push_back(i);
		std_l.push_back(i);
	}

	ASSERT_TRUE(ft_l.size() == std_l.size());
	ASSERT_TRUE(ft_l.max_size() == std_l.max_size());
	ASSERT_TRUE(ft_l.empty() == std_l.empty());

	ft_l.resize(5, 5);
	std_l.resize(5, 5);

	ft::vector<int>::iterator fit = ft_l.begin();
	std::vector<int>::iterator sit = std_l.begin();
	while (fit != ft_l.end()) {
		ASSERT_TRUE(*fit == *sit) << "Resize to smaller: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ft_l.resize(15, 5);
	std_l.resize(15, 5);
	fit = ft_l.begin();
	sit = std_l.begin();
	while (fit != ft_l.end()) {
		ASSERT_TRUE(*fit == *sit) << "Resize to smaller: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, ElementAccessTests) {
	ft::vector<int>		ftv;
	std::vector<int>	stdv;
	for (int i = 0; i < 10; i++) {
		ftv.push_back(i);
		stdv.push_back(i);
	}

	ASSERT_TRUE(ftv[5] == stdv[5]);
	ASSERT_TRUE(ftv.at(5) == stdv.at(5));
	ASSERT_TRUE(ftv.front() == stdv.front());
	ASSERT_TRUE(ftv.back() == stdv.back());
}

TEST(VectorTest, AssignTests) {
	ft::vector<int>		ftv;
	std::vector<int>	stdv;
	for (int i = 0; i < 10; i++) {
		ftv.push_back(i);
		stdv.push_back(i);
	}

	ftv.assign(20, 20);
	stdv.assign(20, 20);

	ft::vector<int>::iterator fit = ftv.begin();
	std::vector<int>::iterator sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Assign: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ft::vector<int>		ftv1;
	std::vector<int>	stdv1;
	for (int i = 0; i < 10; i++) {
		ftv1.push_back(i);
		stdv1.push_back(i);
	}

	ftv.assign(ftv1.begin(), ftv1.end());
	stdv.assign(stdv1.begin(), stdv1.end());

	fit = ftv.begin();
	sit = stdv.begin();
	ASSERT_TRUE(ftv.size() == stdv.size()) << "Assign: Failed with incorrect size ft: " << ftv.size() << " std: " << stdv.size() << "\n";
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Assign: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, PushPopTests) {
	ft::vector<int>		ftv;
	std::vector<int>	stdv;
	for (int i = 0; i < 10; i++) {
		ftv.push_back(i);
		stdv.push_back(i);
	}

	ft::vector<int>::iterator fit = ftv.begin();
	std::vector<int>::iterator sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Push back: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ftv.pop_back();
	stdv.pop_back();

	fit = ftv.begin();
	sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Pop back: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, InsertTests) {
	ft::vector<int>		ftv;
	std::vector<int>	stdv;

	ftv.insert(ftv.begin(), 10);
	stdv.insert(stdv.begin(), 10);
	ASSERT_TRUE(ftv.size() == stdv.size()) << "Insert: Failed with incorrect size ft: " << ftv.size() << " std: " << stdv.size() << "\n";
	ASSERT_TRUE(ftv.front() == stdv.front()) << "Insert: Failed with incorrect size ft: " << ftv.front() << " std: " << stdv.front() << "\n";
	ftv.clear();
	stdv.clear();

	ftv.insert(ftv.begin(), 5, 5);
	stdv.insert(stdv.begin(), 5, 5);

	ASSERT_TRUE(ftv.size() == stdv.size()) << "Insert: Failed with incorrect size ft: " << ftv.size() << " std: " << stdv.size() << "\n";
	ft::vector<int>::iterator fit = ftv.begin();
	std::vector<int>::iterator sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Insert: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, EraseTests) {
	ft::vector<int>		ftv;
	std::vector<int>	stdv;
	for (int i = 0; i < 10; i++) {
		ftv.push_back(i);
		stdv.push_back(i);
	}
	ftv.erase(ftv.begin());
	stdv.erase(stdv.begin());
	ASSERT_TRUE(ftv.size() == stdv.size()) << "Erase: Failed with incorrect size ft: " << ftv.size() << " std: " << stdv.size() << "\n";
	ft::vector<int>::iterator fit = ftv.begin();
	std::vector<int>::iterator sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Erase: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}

	ftv.erase(ftv.begin(), ftv.end());
	stdv.erase(stdv.begin(), stdv.end());
	ASSERT_TRUE(ftv.size() == stdv.size()) << "Erase: Failed with incorrect size ft: " << ftv.size() << " std: " << stdv.size() << "\n";
	fit = ftv.begin();
	sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Erase: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, SwapTests) {
	ft::vector<int>		ftv;
	std::vector<int>	stdv;
	for (int i = 0; i < 10; i++) {
		ftv.push_back(i);
		stdv.push_back(i);
	}

	ft::vector<int>		ftv1;
	std::vector<int>	stdv1;
	for (int i = 10; i < 20; i++) {
		ftv1.push_back(i);
		stdv1.push_back(i);
	}

	ftv.swap(ftv1);
	stdv.swap(stdv1);

	ASSERT_TRUE(ftv.size() == stdv.size()) << "Swap: Failed with incorrect size ft: " << ftv.size() << " std: " << stdv.size() << "\n";
	ft::vector<int>::iterator fit = ftv.begin();
	std::vector<int>::iterator sit = stdv.begin();
	while (fit != ftv.end()) {
		ASSERT_TRUE(*fit == *sit) << "Swap: Failed with ft: " << *fit << ", std: " << *sit << "\n";
		fit++;
		sit++;
	}
}

TEST(VectorTest, OperatorsTests) {
	ft::vector<int>		ri;
	std::vector<int>	si;
	for (int i = 0; i < 10; i++) {
		ri.push_back(i);
		si.push_back(i);
	}

	ft::vector<int>		ri2;
	std::vector<int>	si2;
	for (int i = 10; i < 20; i++) {
		ri2.push_back(i);
		si2.push_back(i);
	}

	ASSERT_TRUE((ri == ri2) == (si == si2)) << "Equality comparison: Failed with ft: " << (ri == ri2) << ", std: " << (si == si2) << "\n";
	ASSERT_TRUE((ri != ri2) == (si != si2)) << "Inequality comparison: Failed with ft: " << (ri != ri2) << ", std: " << (si != si2) << "\n";
	ASSERT_TRUE((ri >= ri2) == (si >= si2)) << "Greater than or equal comparison: Failed with ft: " << (ri >= ri2) << ", std: " << (si >= si2) << "\n";
	ASSERT_TRUE((ri <= ri2) == (si <= si2)) << "Less than or equal comparison: Failed with ft: " << (ri <= ri2) << ", std: " << (si <= si2) << "\n";
	ASSERT_TRUE((ri < ri2) == (si < si2)) << "Less than comparison: Failed with ft: " << (ri < ri2) << ", std: " << (si < si2) << "\n";
	ASSERT_TRUE((ri > ri2) == (si > si2)) << "Greater than comparison: Failed with ft: " << (ri > ri2) << ", std: " << (si > si2) << "\n";
}