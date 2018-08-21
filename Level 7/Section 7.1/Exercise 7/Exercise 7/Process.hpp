#ifndef PROCESSING_HPP
#define PROCESSING_HPP


#include <vector>
#include <string>
#include <algorithm>
#include <cctype>


template <typename T1, typename T2> 
class Processing
{
private:
	static std::string str_toupper(std::string s)
	{ // helper function to convert string
		std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) {return std::toupper(c); });
		return s;
	}

public:
	
	std::vector<T2> convert(std::vector<T1> t)
	{
		std::transform(t.begin(), t.end(), t.begin(), [](std::string i) { return str_toupper(i); });
		return t;

	}

	
};

#endif