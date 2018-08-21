// Implements RealAccount


#include "RealAccount.hpp"
#include "NoFundsException.hpp"


RealAccount::RealAccount()
{
};// Default ctor calls Base default

RealAccount::RealAccount(const RealAccount& source)
{// Copy ctor
	m_balance = source.m_balance;
};

RealAccount::RealAccount(double initBal) 
{ // RealAccount with initial balance
	m_balance = initBal;
};

RealAccount& RealAccount::operator =(const RealAccount& source)
{// Assignment
 // Exit if same object
	if (this == &source)
		return *this;

	m_balance = source.m_balance;
	return *this;
}

void RealAccount::Withdraw(double amount)
{// Withdraw money
	if (m_balance >= amount)
		m_balance -= amount;
	else
	{
		throw NoFundsException(m_balance);
	}
}
void RealAccount::Deposit(double amount)
{// Deposit money
	m_balance += amount;
}

double RealAccount::GetBalance() const
{ // Private to control access
	return m_balance;
}