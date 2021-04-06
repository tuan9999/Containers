//
// Created by Tuan Perera on 27.02.21.
//

#include <map>
#include "gtest/gtest.h"
#include "../library.h"
#include "pair.h"

TEST(MapTest, ConstructorTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));


	ft::map<int, std::string> mf2(mf1.begin(), mf1.end());
	std::map<int, std::string> ms2(ms1.begin(), ms1.end());
	ft::map<int, std::string>::iterator itf = mf2.begin();
	std::map<int, std::string>::iterator its = ms2.begin();
	while (itf != mf2.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Iterator constructor: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}
}

TEST(MapTest, IteratorTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::map<int, std::string>::iterator itf = mf1.begin();
	std::map<int, std::string>::iterator its = ms1.begin();
	while (itf != mf1.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Iterator: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}

	ft::map<int, std::string>::reverse_iterator ritf = mf1.rbegin();
	std::map<int, std::string>::reverse_iterator rits = ms1.rbegin();
	while (ritf != mf1.rend()) {
		ASSERT_TRUE((ritf->first == rits->first) && (ritf->second == rits->second)) << "Iterator: Failed with ft: " << ritf->first << " " << ritf->second << " std: " << rits->first << " " << rits->second << "\n";
		ritf++;
		rits++;
	}
}

TEST(MapTest, CapacityTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));
	ASSERT_TRUE(mf1.empty() == ms1.empty()) << "Empty: Failed with ft: " << mf1.empty() << " std: " << ms1.empty() << "\n";
	ASSERT_TRUE(mf1.size() == ms1.size()) << "Size: Failed with ft: " << mf1.size() << " std: " << ms1.size() << "\n";
}

TEST(MapTest, OperatorTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));
	ASSERT_TRUE(mf1[16] == ms1[16]) << "Operator[]: Failed with ft: " << mf1[16] << " std: " << ms1[16] << "\n";
}

TEST(MapTest, InsertEraseTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::map<int, std::string> mf2;
	std::map<int, std::string> ms2;
	mf2.insert(mf1.begin(), mf1.end());
	ms2.insert(ms1.begin(), ms1.end());
	ft::map<int, std::string>::iterator itf = mf2.begin();
	std::map<int, std::string>::iterator its = ms2.begin();
	while (itf != mf2.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Insert iterator: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}

	mf2.erase(mf2.begin());
	ms2.erase(ms2.begin());
	itf = mf2.begin();
	its = ms2.begin();
	while (itf != mf2.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Erase iterator: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}

	mf2.erase(23);
	ms2.erase(23);
	ASSERT_TRUE(mf2.size() == ms2.size());
}

TEST(MapTest, SwapTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::map<int, std::string> mf2;
	std::map<int, std::string> ms2;

	mf2.insert(ft::pair<int, std::string>(12, str));
	ms2.insert(std::pair<int, std::string>(12, str));

	mf2.insert(ft::pair<int, std::string>(89, str));
	ms2.insert(std::pair<int, std::string>(89, str));

	mf2.swap(mf1);
	ms2.swap(ms1);

	ft::map<int, std::string>::iterator itf = mf2.begin();
	std::map<int, std::string>::iterator its = ms2.begin();
	while (its != ms2.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Insert iterator: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}
}

TEST(MapTest, FindTests) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::map<int, std::string>::iterator itf = mf1.find(16);
	std::map<int, std::string>::iterator its = ms1.find(16);
	ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Find: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
}

TEST(MapTest, CountTest) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));
	ASSERT_TRUE(mf1.count(16) == ms1.count(16)) << "Count: Failed with ft: " << mf1.count(16) << " std: " << ms1.count(16) << "\n";
}

TEST(MapTest, BoundTest) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::map<int, std::string>::iterator itf = mf1.lower_bound(16);
	std::map<int, std::string>::iterator its = ms1.lower_bound(16);
	ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Lower Bound: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";

	itf = mf1.upper_bound(16);
	its = ms1.upper_bound(16);
	ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Upper Bound: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
}

TEST(MapTest, EqualRangeTest) {
	std::string str = "Mapped";
	ft::map<int, std::string> mf1;
	std::map<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator>itpair = mf1.equal_range(16);
	std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>stitpair = ms1.equal_range(16);
	ASSERT_TRUE((itpair.first->first == stitpair.first->first) && (itpair.first->second == stitpair.first->second) && (itpair.second->first == stitpair.second->first) && (itpair.second->second == stitpair.second->second)) << "Equal range: Failed with ft: " << itpair.first->first << " " << itpair.first->second << "; " << itpair.second->first << " " << itpair.second->second << " std: " << stitpair.first->first << " " << stitpair.first->second << "; " << stitpair.second->first << " " << stitpair.second->second << "\n";
}
