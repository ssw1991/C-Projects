#ifndef S_HPP
#define S_HPP

#include <string>
#include "HashFunctions.hpp"


struct S
{
	std::string f; std::string s;
	S(const std::string& s1,
		const std::string& s2) : f(s1), s(s2) {}
};

class SHash // Hash for class S
{
public:
	std::size_t operator() (const S& s) const
	{
		return hash_value(s.f, s.s);
	}
};

class SEqual // Equality for S
{
public:
	bool operator()(const S& lhs, const S& rhs) const
	{
		return (rhs.f == lhs.f && rhs.s == lhs.s);
	}
};

#endif S_HPP