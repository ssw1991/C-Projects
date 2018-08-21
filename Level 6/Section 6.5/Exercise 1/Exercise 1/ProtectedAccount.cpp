//Protected Account.hpp


//Controls Access to Real Account



#include "Account.hpp"
#include "RealAccount.hpp"
#include "NoAccessException.hpp"
#include "ProtectedAccount.hpp"
#include <string>


	
ProtectedAccount::ProtectedAccount(const ProtectedAccount& source)
{// Copy ctor
	m_account = source.m_account;
	m_password = source.m_password;
}; 
	
ProtectedAccount::ProtectedAccount(double initBal, std::string pwd): m_account(RealAccount(initBal)), m_password(pwd)
{// Initialize owned real account
};  
	
ProtectedAccount& ProtectedAccount::operator =(const ProtectedAccount& source)
{// Assignment
	// Exit if same object
	if (this == &source)
		return *this;

	m_account = source.m_account;
	m_password = source.m_password;
	return *this;
}; 

double ProtectedAccount::GetBalance(std::string password) const
{
	if (password == m_password)
		return(m_account.GetBalance());
	else
		throw(NoAccessException());
};

double ProtectedAccount::GetBalance() const
{// Throw exception if no pwd provided
	throw(NoAccessException());
};

void ProtectedAccount::Withdraw(double amount)
{// Withdraw money
	m_account.Withdraw(amount);
}

void ProtectedAccount::Deposit(double amount)
{// Deposit money
	m_account.Deposit(amount);
}

