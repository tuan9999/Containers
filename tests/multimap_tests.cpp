//
// Created by Tuan Perera on 08.04.21.
//

#include <map>
#include "gtest/gtest.h"
#include "../library.h"

TEST(MultiMapTest, ConstructorTests) {
	std::string str = "multiMapped";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;

	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));


	ft::multimap<int, std::string> mf2(mf1.begin(), mf1.end());
	std::multimap<int, std::string> ms2(ms1.begin(), ms1.end());
	ft::multimap<int, std::string>::iterator itf = mf2.begin();
	std::multimap<int, std::string>::iterator its = ms2.begin();

	while (itf != mf2.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Iterator constructor: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}
}

TEST(MultiMapTest, IteratorTests) {
	std::string str = "multiMapped";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::multimap<int, std::string>::iterator itf = mf1.begin();
	std::multimap<int, std::string>::iterator its = ms1.begin();
	while (itf != mf1.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Iterator: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}

	ft::multimap<int, std::string>::reverse_iterator ritf = mf1.rbegin();
	std::multimap<int, std::string>::reverse_iterator rits = ms1.rbegin();
	while (ritf != mf1.rend()) {
		ASSERT_TRUE((ritf->first == rits->first) && (ritf->second == rits->second)) << "Iterator: Failed with ft: " << ritf->first << " " << ritf->second << " std: " << rits->first << " " << rits->second << "\n";
		ritf++;
		rits++;
	}
}

TEST(MultiMapTest, CapacityTests) {
	std::string str = "multiMapped";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));
	ASSERT_TRUE(mf1.empty() == ms1.empty()) << "Empty: Failed with ft: " << mf1.empty() << " std: " << ms1.empty() << "\n";
	ASSERT_TRUE(mf1.size() == ms1.size()) << "Size: Failed with ft: " << mf1.size() << " std: " << ms1.size() << "\n";
}

TEST(MultiMapTest, InsertEraseTests) {
	std::string str = "multiMapped";
	std::string str1 = "lol";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str1));
	ms1.insert(std::pair<int, std::string>(16, str1));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));
	ft::multimap<int, std::string> mf2;
	std::multimap<int, std::string> ms2;
	mf2.insert(mf1.begin(), mf1.end());
	ms2.insert(ms1.begin(), ms1.end());
	ft::multimap<int, std::string>::iterator itf = mf2.begin();
	std::multimap<int, std::string>::iterator its = ms2.begin();
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

TEST(MultiMapTest, SwapTests) {
	std::string str = "multiMapped";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::multimap<int, std::string> mf2;
	std::multimap<int, std::string> ms2;

	mf2.insert(ft::pair<int, std::string>(12, str));
	ms2.insert(std::pair<int, std::string>(12, str));

	mf2.insert(ft::pair<int, std::string>(89, str));
	ms2.insert(std::pair<int, std::string>(89, str));

	mf2.swap(mf1);
	ms2.swap(ms1);

	ft::multimap<int, std::string>::iterator itf = mf2.begin();
	std::multimap<int, std::string>::iterator its = ms2.begin();
	while (its != ms2.end()) {
		ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Insert iterator: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
		itf++;
		its++;
	}
}

TEST(MultiMapTest, FindTests) {
	std::string str = "multiMapped";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));

	ft::multimap<int, std::string>::iterator itf = mf1.find(16);
	std::multimap<int, std::string>::iterator its = ms1.find(16);
	ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Find: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
}

TEST(MultiMapTest, CountTest) {
	std::string str = "multiMapped";
	ft::multimap<int, std::string> mf1;
	std::multimap<int, std::string> ms1;
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));
	mf1.insert(ft::pair<int, std::string>(16, str));
	ms1.insert(std::pair<int, std::string>(16, str));

	mf1.insert(ft::pair<int, std::string>(23, str));
	ms1.insert(std::pair<int, std::string>(23, str));
	ASSERT_TRUE(mf1.count(16) == ms1.count(16)) << "Count: Failed with ft: " << mf1.count(16) << " std: " << ms1.count(16) << "\n";
}

//TEST(MultiMapTest, BoundTest) {
//	std::string str = "multiMapped";
//	ft::multimap<int, std::string> mf1;
//	std::multimap<int, std::string> ms1;
//	mf1.insert(ft::pair<int, std::string>(16, str));
//	ms1.insert(std::pair<int, std::string>(16, str));
//	mf1.insert(ft::pair<int, std::string>(16, str));
//	ms1.insert(std::pair<int, std::string>(16, str));
//
//	mf1.insert(ft::pair<int, std::string>(23, str));
//	ms1.insert(std::pair<int, std::string>(23, str));
//
//	ft::multimap<int, std::string>::iterator itf = mf1.lower_bound(16);
//	std::multimap<int, std::string>::iterator its = ms1.lower_bound(16);
//	ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Lower Bound: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
//
//	itf = mf1.upper_bound(16);
//	its = ms1.upper_bound(16);
//	ASSERT_TRUE((itf->first == its->first) && (itf->second == its->second)) << "Upper Bound: Failed with ft: " << itf->first << " " << itf->second << " std: " << its->first << " " << its->second << "\n";
//}

//TEST(MultiMapTest, EqualRangeTest) {
//	std::string str = "multiMapped";
//	ft::multimap<int, std::string> mf1;
//	std::multimap<int, std::string> ms1;
//	mf1.insert(ft::pair<int, std::string>(16, str));
//	ms1.insert(std::pair<int, std::string>(16, str));
//	mf1.insert(ft::pair<int, std::string>(16, str));
//	ms1.insert(std::pair<int, std::string>(16, str));
//
//	mf1.insert(ft::pair<int, std::string>(23, str));
//	ms1.insert(std::pair<int, std::string>(23, str));
//
//	ft::pair<ft::multimap<int, std::string>::iterator, ft::multimap<int, std::string>::iterator>itpair = mf1.equal_range(16);
//	std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator>stitpair = ms1.equal_range(16);
//	ASSERT_TRUE((itpair.first->first == stitpair.first->first) && (itpair.first->second == stitpair.first->second) && (itpair.second->first == stitpair.second->first) && (itpair.second->second == stitpair.second->second)) << "Equal range: Failed with ft: " << itpair.first->first << " " << itpair.first->second << "; " << itpair.second->first << " " << itpair.second->second << " std: " << stitpair.first->first << " " << stitpair.first->second << "; " << stitpair.second->first << " " << stitpair.second->second << "\n";
//}
