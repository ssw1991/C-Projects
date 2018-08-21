#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <regex>

using regex = std::regex;  // To avoid having to edit the code to be pasted

int main()
{
	regex myReg("[a-z]*");  // Matches any alpha numeric character 0 or more times
	regex myReg2("[a-z]+"); // Matches and alpha numeric character 1 or more times 

	std::string s1("aza");
	std::string s2("1");
	std::string s3("b");
	std::string s4("ZZ TOP");


	if (std::regex_match(s1, myReg))
		std::cout << s1 << ": Matched" << std::endl;  //true

	if (std::regex_match(s1, myReg2))
		std::cout << s1 << ": Matched" << std::endl;  //true


	if (std::regex_match(s2, myReg))            
		std::cout << s2 << ": Matched" << std::endl; //false

	if (std::regex_match(s2, myReg2))
		std::cout << s2 << ": Matched" << std::endl; // false 

	if (std::regex_match(s3, myReg))
		std::cout << s3 << ": Matched" << std::endl;  //true

	if (std::regex_match(s3, myReg2))
		std::cout << s3 << ": Matched" << std::endl; // true

	if (std::regex_match(s4, myReg))
		std::cout << s4 << ": Matched" << std::endl;  // false (upper case)

	if (std::regex_match(s4, myReg2))
		std::cout << s4 << ": Matched" << std::endl;  // false 

	
	regex myNumericReg("\\d{2}");   // Matches a sequence of 2 digits 
	std::string f("34");
	std::string s("345");

	if (std::regex_match(f, myNumericReg))
		std::cout << f << ": Matched" << std::endl;  // True
	if (std::regex_match(f, myNumericReg))
		std::cout << f << ": Matched" << std::endl;  // True 
	
	regex myAltReg("(new)|(delete)");   // Matches the word new or delete
	std::string s4A("new");
	std::string s5("delete");
	std::string s6("malloc");

	if (std::regex_match(s4A, myAltReg))
		std::cout << s4A << ": Matched" << std::endl; // true

	if (std::regex_match(s5, myAltReg))
		std::cout << s5 << ": Matched" << std::endl;  // true

	if (std::regex_match(s6, myAltReg))
		std::cout << s6 << ": Matched" << std::endl;  // false 
	
	regex myReg3("A*");    // matches A 0 or more times
	regex myReg4("A+");    // matches A 1 or more times 
	regex myReg5("(\\d{2})"); // matches sequence of 2 digits 
	regex myReg6("\\d{2,4}");  // matches a sequence of 2 - 4 digits 
	regex myReg7("\\d{1,}");    // matches 1 or more  digit 
	
	std::string testA("1");

	if (std::regex_match(testA, myReg3))
		std::cout << testA << ": Matched" << std::endl; // false

	if (std::regex_match(testA, myReg4))
		std::cout << testA << ": Matched" << std::endl; // false

	if (std::regex_match(testA, myReg5))
		std::cout << testA << ": Matched" << std::endl; // false

	if (std::regex_match(testA, myReg6))
		std::cout << testA << ": Matched" << std::endl; // false

	if (std::regex_match(testA, myReg7))
		std::cout << testA << ": Matched" << std::endl; // true


	regex rC("(\\w)*"); // Alphanumeric (word) A-Za-z0-9
	regex rC1("(\\W)*"); // Not a word
	regex rC2("[A-Za-z0-9_]*"); // Alphanumeric (word) A-Za-z0-9

	std::string sC1("abc");
	std::string sC2("A12678Z909za"); 

	if (std::regex_match(sC1, rC))
		std::cout << sC1 << ": Matched" << std::endl; // true

	if (std::regex_match(sC1, rC1))
		std::cout << sC1 << ": Matched" << std::endl; // false

	if (std::regex_match(sC1, rC2))
		std::cout << sC1 << ": Matched" << std::endl; // true


	if (std::regex_match(sC2, rC))
		std::cout << sC2 << ": Matched" << std::endl; // true

	if (std::regex_match(sC2, rC1))
		std::cout << sC2 << ": Matched" << std::endl; // false

	if (std::regex_match(sC2, rC2))
		std::cout << sC2 << ": Matched" << std::endl; // true


	regex myTimeseries("(\\d{4}-\\d{2}-\\d{2}),(\\d{1,}\\.\\d{2},){4}(\\d+),(\\d{1,}\\.\\d{2})");
	/*
	Matches the timeseries data from previous example
		(\\d{4}-\\d{2}-\\d{2})  - group to match date ####-##-##
		, - match comma
		(\\d{1,}\\.\\d{2},){4} - matches something to be cast to double, repeated 4 times seperated by comma
								(one or more digits).(two digits) '.' escaped because it also means any character
		(\\d{1,})   - group to match volume
		
		Final group matches double again
	*/						
	std::string data = "2013-02-01,54.87,55.20,54.67,54.92,2347600,54.92";
	std::cout << std::regex_match(data, myTimeseries);
	if (std::regex_match(data, myTimeseries))
		std::cout << data << ": Matched" << std::endl; // true

}
