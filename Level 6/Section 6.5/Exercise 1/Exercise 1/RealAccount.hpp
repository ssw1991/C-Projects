// RealAccount.hpp
//
// Base class to model Realaccount


#ifndef REALACCOUNT_HPP
#define REALACCOUNT_HPP

#include "Account.hpp"
class RealAccount: public Account
{
private:
	double m_balance;
public:
	RealAccount(); // Default ctor
	RealAccount(const RealAccount& source); // Copy ctor
	RealAccount(double initBal);  // Account with initial balance
	RealAccount& operator =(const RealAccount& source); // Assignment
	double GetBalance() const override;
	void Withdraw(double amount) override;  // Withdraw money
	void Deposit(double amount) override;   // Deposit money
};

#endif
