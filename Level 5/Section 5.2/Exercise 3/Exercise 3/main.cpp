#include <regex>
#include <string>
#include <iostream>
#include <set>
#include <boost/lexical_cast.hpp>

using regex = std::regex;


int main()
{
	regex myReg("\\d+");
	std::string myText("1,1,2,3,4,8,13,21");

	std::set<int> mySet;

	auto nums_begin =
		std::sregex_iterator(myText.begin(), myText.end(), myReg);

	for (std::sregex_iterator i = nums_begin; i != std::sregex_iterator(); i++)
	{
		std::smatch match = *i;
		mySet.insert(boost::lexical_cast<int>(match.str()));
	}

	for (auto i : mySet)
	{
		std::cout << i << std::endl;
	}
}