#include <regex>
#include <iostream>
#include <string>



int main()
{
	std::string text("Quick brown fox");
	std::regex vowels("a|e|i|o|u");

	std::cout << std::regex_replace(text, vowels, "*");



	return 0;
}