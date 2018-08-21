// OutOfBoundsException.hpp
//
// Base class for no funds exception.


#ifndef NoFundsBoundsException_HPP
#define NoFundsException_HPP

#include "AccountException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

class NoAccessException : public AccountException
{
public:
	// Constructors and destructor
	NoAccessException() : AccountException()
	{ // Default constructor
	}

	~NoAccessException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "Incorrect Password" << std::endl;
		return stream.str();
	}
};

#endif