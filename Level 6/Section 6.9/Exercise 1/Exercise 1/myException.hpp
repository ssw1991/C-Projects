// Generic Exception


#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <string>
struct myException
{
	std::string message;
	myException(std::string s) :message(s) {};
};
#endif