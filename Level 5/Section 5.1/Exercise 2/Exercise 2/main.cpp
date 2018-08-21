#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <boost/regex.hpp>

bool PasswordCheck(std::string& s)
{
	auto alnum = [](auto ch) { return boost::is_alnum()(ch); };  // Ensure there is a letter
	auto cntrl = [](auto ch) { return !(boost::is_cntrl()(ch)); };  // Ensure there is no control character
	auto space = [](auto ch) { return !(boost::is_space()(ch)); };  // Ensure there is no space

	bool size = (s.size() >= 8);
	bool cntrlcheck = boost::all(s, cntrl);
	bool spacecheck = boost::all(s, space);
	bool alnumcheck = boost::all(s, alnum);
	 
	// Still need to verify that there is an upper case letter, and a digit,  all doesnt work because 
	// it just needs to be present

	boost::regex upper("[A-Z]");
	boost::regex digit("[0-9]");

	boost::match_results<std::string::iterator> what;
	bool uppercheck = boost::regex_search(s.begin(), s.end(), what, upper, boost::match_default);   // ensure at least 1 uppercase
	bool digitcheck = boost::regex_search(s.begin(), s.end(), what, digit, boost::match_default);   // ensure at least 1 digit

	return (size & cntrlcheck & spacecheck & alnumcheck & uppercheck & digitcheck);
}


int main()
{
	/*
		Using predicates in the following lambdas:
			boost::is_alnum returns a function object which takes a character
			it does not take a character its self.  Hence the boost::is_alnum()(ch)
	*/
	auto alnum = [](auto ch) { return boost::is_alnum()(ch); };  // P1
	auto digit = [](auto ch) { return boost::is_digit()(ch); };  // P2
	auto lower = [](auto ch) { return ( boost::is_lower()(ch) & boost::is_alpha()(ch)); };  // P3

	std::string s1 = "abd1 234\*";

	std::cout << std::boolalpha;

	std::cout <<" Is it all digits or letters: " << boost::all(s1, alnum) << std::endl;  //false
	std::cout << " Is it all digits: " << boost::all(s1, digit) << std::endl; // false
	std::cout << " Is it all withing ['a', 'z']: " << boost::all(s1, lower) << std::endl;  //false
	
	std::string pwd = "DanialDuffy1952";  // Valid
	std::cout << "Does " << pwd << " pass: " << PasswordCheck(pwd) << std::endl;

	pwd = "DanielDuffy";  // Not valid - no digit
	std::cout << "Does " << pwd << " pass: " << PasswordCheck(pwd) << std::endl;

	pwd = "U19520829";  // Valid
	std::cout << "Does " << pwd << " pass: " << PasswordCheck(pwd) << std::endl;

	pwd = "19520829U";  // Valid 
	std::cout << "Does " << pwd << " pass: " << PasswordCheck(pwd) << std::endl;

	return 0;
}