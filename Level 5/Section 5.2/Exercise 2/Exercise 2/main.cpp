#include <regex>
#include <string>
#include <iostream>


using regex = std::regex;


int main()
{
	regex mySearchReg("(rain)|(Spain)");
	std::string myText("The rain in Spain stays mainly on the plain");

	std::smatch s;

	std::regex_search(myText, s, mySearchReg);

	for(int i = 0; i<s.size(); i++) 
	{
		std::cout << "Match " << i << ": " << s[i] << std::endl;

	}  // Only returns the first match

	auto words_begin =
		std::sregex_iterator(myText.begin(), myText.end(), mySearchReg);

	for (std::sregex_iterator i = words_begin; i != std::sregex_iterator(); i++)
	{
		std::smatch match = *i;
		std::cout << "Found: " << match.str() << std::endl;
	}
}