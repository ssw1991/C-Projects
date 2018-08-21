#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include<boost/functional/hash.hpp>

template<typename T>
std::size_t myHash(T const& t)
{
	return std::hash<T>()(t);
}

template<typename T>
std::size_t myBoostHash(T const & t)
{
	return boost::hash<T>()(t);
}

int main()
{
	int a = 22;
	std::string s1 = "My string";
	std::string s2 = "My string2";
	std::shared_ptr<int> ptr(&a);
	long l(std::numeric_limits<long>::max());



	std::cout <<"Using Std::hash on int: " <<  myHash(a) << std::endl;
	std::cout << "Using boost::hash on int: " << myBoostHash(a) << std::endl;
	std::cout << "Using Std::hash on string: " << myHash(s1) << std::endl;
	std::cout << "Using boost::hash on string: " << myBoostHash(s1) << std::endl;
	std::cout << "Using Std::hash on ptr: " << myHash(ptr) << std::endl;
	std::cout << "Using boost::hash on ptr: " << myBoostHash(ptr) << std::endl;
	std::cout << "Using Std::hash on long: " << myHash(l) << std::endl;
	std::cout << "Using boost::hash on long: " << myBoostHash(l) << std::endl;

	auto compHash = myHash(s1) ^ (myHash(s2) << 1);
	std::cout << "h1^(h2<<1): " <<  compHash;

	return 0;
}

