#include <iostream>
#include "AccountException.hpp"
#include "ProtectedAccount.hpp"


int main()
{

	ProtectedAccount p1(0.0, "password1");

	try
	{ // Should throw exception
		p1.Withdraw(100.00);
	}
	catch (AccountException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

	p1.Deposit(300.00);


	try
	{ // Should throw exception
		p1.GetBalance();
	}
	catch (AccountException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

	try
	{ // Should throw exception
		p1.GetBalance("ps");
	}
	catch (AccountException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

	try
	{ // Should not throw exception
		std::cout << "balance: " << p1.GetBalance("password1") << std::endl;
	}
	catch (AccountException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

	try
	{ // Should not throw exception
		p1.Withdraw(200.00);
	}
	catch (AccountException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

	try
	{ // Should not throw exception
		std::cout << "balance: " << p1.GetBalance("password1") << std::endl;
	}
	catch (AccountException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

}