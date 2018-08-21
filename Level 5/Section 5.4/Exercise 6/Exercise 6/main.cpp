#include <functional>
#include <random>
#include <unordered_set>
#include <iostream>
#include "S.hpp"
#include "HashFunctions.hpp"


template<typename Key, typename Hash = std::hash<Key>, typename EqPred = std::equal_to<Key>>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c)
{ // Template with default hash and eq predicates 
	std::cout << "Bucket Count: " << c.bucket_count() << std::endl;

	for (int i = 0; i < c.bucket_count(); i++)
		std::cout << "\tBucket " << i << " Size: " << c.bucket_size(i) << std::endl;
	std::cout << "Max Bucket Count: " << c.max_bucket_count() << std::endl;
	std::cout << "Load Factor: " << c.load_factor() << std::endl;
	std::cout << "Max Load Factor: " << c.max_load_factor() << std::endl;
}



int main()
{
	std::unordered_set<S, SHash, SEqual> mySet;

	S s1("James", "Johnson");
	S s2("James", "Johnson");
	S s3("James", "Henry");
	S s4("John", "Johnson");
	S s5("Phil", "Thom");

	mySet.insert(s1); mySet.insert(s2); mySet.insert(s3); mySet.insert(s4); mySet.insert(s5);

	BucketInformation(mySet);
}






