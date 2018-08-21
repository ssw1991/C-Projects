#include <regex>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>

using regex = std::regex;

int main()
{
	regex ecmaReg
	("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
	 // Assumes it is a number in scientific notation, or plain
	// ie. may lead with +/-, one or digits
	//followed by period with one or more digits (optional)
	//e or E with option +- and one or more digits, optional

	std::string v1 = "2.34e-1";  // .234     valid
	std::string v2 = "2.34E4";    // 23,400  valid
	std::string v3 = "2.34";     //  valid
	std::string v4 = "2";        // valid

	std::string nv = "2,345,120";  // Not valid

	std::vector<std::string> v{ v1,v2,v3,v4, nv };  // Vector of strings

	for (auto i : v)
	{
		if (std::regex_match(i, ecmaReg))
		{
			std::cout << "Match: " << i << std::endl;
			std::cout << "As double: " << boost::lexical_cast<double>(i) << std::endl;
		}

		else
		{
			std::cout << "Not a match: " << i << std::endl;
		}
	}

}