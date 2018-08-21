// Account Exception
//
// Base class for AccountException


#ifndef AccountException_HPP
#define AccountException_HPP

#include <iostream>
using namespace std;

class AccountException
{
public:
	// Constructor and destructor
	AccountException()
	{ // Default constructor
	}

	virtual ~AccountException()
	{ // Destructor
	}

	virtual string GetMessage() = 0;
};

#endif