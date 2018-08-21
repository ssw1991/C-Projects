#include <regex>
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <map>


using regex = std::regex;

void NameVal(std::string& s, std::map<std::string, int>& m)
{ // string is of form [name] = [val]
	std::vector<std::string> v;

	boost::trim(s);  // so the outside spaces are removed
	boost::split(v, s, boost::is_any_of(" = "), boost::token_compress_on);  // Token compress on allows it to split on multiple delim together

	m[v[0]] = boost::lexical_cast<int>(v[1]);
}


int main()
{
	regex myReg(",");
	std::string mystring = "a = 1, b = 2, c = 3";

	std::map<std::string, int> myMap;

	auto val_begin = std::sregex_token_iterator(mystring.begin(), mystring.end(), myReg, -1);


	for (std::sregex_token_iterator i = val_begin; i != std::sregex_token_iterator(); i++)
	{
		std::string match = *i;
		NameVal(match, myMap);
	}

	for (auto i : myMap)
		std::cout << i.first << ": " << i.second << std::endl;


}