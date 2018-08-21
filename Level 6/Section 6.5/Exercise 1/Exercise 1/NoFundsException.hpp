// OutOfBoundsException.hpp
//
// Base class for no funds exception.


#ifndef NoFundsBoundsException_HPP
#define NoFundsException_HPP

#include "AccountException.hpp"
#include <sstream>
#include <iostream>

using namespace std;

class NoFundsException : public AccountException
{
private:
	double m_balance;

public:
	// Constructors and destructor
	NoFundsException() : AccountException()
	{ // Default constructor
	}

	NoFundsException(double balance) : AccountException()
	{ // Constructor accepting erroneous array index
		m_balance = balance;
	}

	~NoFundsException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "Not enough funds, balance is: " << m_balance << std::endl;

		return stream.str();
	}
};

#endif