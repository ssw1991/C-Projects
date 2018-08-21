// Account.hpp
//
// Base class to model account


#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{

public:
	Account() {}; // Default ctor
	virtual void Withdraw(double amount) = 0;  // Withdraw money
	virtual void Deposit(double amount) = 0;   // Deposit money
	virtual double GetBalance() const = 0;
};

#endif
