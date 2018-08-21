//Protected Account.hpp


//Controls Access to Real Account


#ifndef PROTECTEDACCOUNT_HPP
#define PROTECTEDACCOUNT_HPP

#include "Account.hpp"
#include "RealAccount.hpp"
#include <string>

class ProtectedAccount: public Account
{

private:
	std::string m_password;
	RealAccount m_account;
	
public:
	
	ProtectedAccount() = delete; // Default ctor deleted
	ProtectedAccount(const ProtectedAccount& source); // Copy ctor
	ProtectedAccount(double initBal, std::string pwd);  // Account with initial balance
	ProtectedAccount& operator =(const ProtectedAccount& source); // Assignment
	double GetBalance() const override;
	double GetBalance(std::string pwd) const;
	void Withdraw(double amount) override;
	void Deposit(double amount) override;

};

#endif
