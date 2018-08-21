#include <functional>
#include <random>
#include <unordered_set>
#include <iostream>

template<typename Key, typename Hash = std::hash<Key>, typename EqPred = std::equal_to<Key>>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c)
{ // Template with default hash and eq predicates 
	std::cout << "Bucket Count: " << c.bucket_count() << std::endl;

	for(int i = 0; i < c.bucket_count(); i++)
		std::cout << "\tBucket "<< i << " Size: " << c.bucket_size(i) << std::endl;
	std::cout << "Max Bucket Count: " << c.max_bucket_count() << std::endl;
	std::cout << "Load Factor: " << c.load_factor() << std::endl;
	std::cout << "Max Load Factor: " << c.max_load_factor() << std::endl;
}




int main()
{
	auto eng = std::mt19937();

	auto dist = std::uniform_real_distribution<double>(0.0, 100.0); 
	
	std::unordered_set<double> c;
	
	for (int i = 0; i <= 100;i++)
	{
		c.insert(dist(eng));
	}

	BucketInformation(c);
	c.rehash(500);
	BucketInformation(c);



}