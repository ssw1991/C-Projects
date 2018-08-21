#include <boost/functional/hash.hpp>
#include <iostream>
#include "Line.hpp"
#include "Point.hpp"


template<typename T>
void hash_value(std::size_t& seed, const T& val)
{
	boost::hash_combine(seed, val);
}

template<typename T, typename ... Types>
void hash_value(std::size_t& seed, const T& val, const Types& ... args)
{ // Variadic hash 
	boost::hash_combine(seed, val);   // combines has for seed with val
	hash_value(seed, args...);        // Calls seed on the rest of args
} 

template<typename ... Types>
std::size_t hash_value(const Types& ...args)
{
	std::size_t seed = 0;
	hash_value(seed, args ...);
	return seed;
}



struct LineHasher
{
	std::size_t operator()(Line const& l) const
	{
		return hash_value(l.start(), l.end());
	}
};

int main()
{

	std::size_t seed = 0;

	Point p1(1.0, 1.0);
	Point p2(1.2, 1.2);
	
	hash_value(seed, p1, p2);
	std::cout << "Using Variadic Hash, while setting seed: " << seed << std::endl;
	
	auto h1 = hash_value(p1, p2);
	std::cout << "Using Variadice with generic auxillary: " << h1 << std::endl;

	 //Using an object composed of heterogeneous objects

	std::cout << "Using a composit object: " << LineHasher()(Line(p1, p2));

	return 0;

}