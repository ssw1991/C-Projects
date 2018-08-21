#ifndef HASHFUNCTIONS_HPP
#define HASHFUNCTIONS_HPP

#include <boost/functional/hash.hpp>

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

#endif