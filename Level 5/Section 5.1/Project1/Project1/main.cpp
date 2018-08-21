#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <cctype>



int main()
{

	// Trim leading and trailing blanks

	std::string s1 = "     This has spaces      ";
	std::string s2 = s1;
	
	std::cout << "Trim left - copy: " << boost::trim_left_copy(s1) << std::endl;
	std::cout << "Trim right - copy: " << boost::trim_left_copy(s1) << std::endl;
	std::cout << "Trim - copy: " << boost::trim_left_copy(s1) << std::endl;

	boost::trim_left(s1);  // Modifies s1
	boost::trim_right(s1);  // Modifies s1
	boost::trim(s2);        // Modifies s2;

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	s1 = "**@#$!# This contains non alphanumeric character @##$@";
	auto f = [](int ch) { return (!std::isalnum(ch)); };  // Negate isalnum
	
	
	std::cout << "Trim nonalphanumeric: " << boost::trim_left_copy_if(s1, f) << std::endl;
	std::cout << "Trim nonalphanumeric: " << boost::trim_right_copy_if(s1, f) << std::endl;
	std::cout << "Trim nonalphanumeric: " << boost::trim_copy_if(s1, f) << std::endl;
	
	s1 = "Date,open,close";

	std::cout << std::boolalpha;

	std::cout << "Stars with date, case sensitive: " << boost::starts_with(s1, "date") << std::endl;
	std::cout << "Stars with date, case insensitive: " << boost::istarts_with(s1, "date") << std::endl;


	std::cout << "Ends with Close, case sensitive: " << boost::ends_with(s1, "Close") << std::endl;
	std::cout << "Stars with Close, case insensitive: " << boost::iends_with(s1, "Close") << std::endl;


	std::cout << "Contains Open, case sensitive: " << boost::contains(s1, "Open") << std::endl;
	std::cout << "Contains Open, case insensitive: " << boost::icontains(s1, "Open") << std::endl;

	s2 = "DATE,OPEN,CLOSE";

	std::cout << "'Date,open,close == DATE,OPEN,CLOSE', case sensitive: " << boost::equals(s1, s2) << std::endl;
	std::cout << "'Date,open,close == DATE,OPEN,CLOSE', case sensitive: " << boost::iequals(s1, s2) << std::endl;
}