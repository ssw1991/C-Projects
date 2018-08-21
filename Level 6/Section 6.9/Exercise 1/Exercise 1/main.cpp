#include "Stack.hpp"
#include "myException.hpp"
#include "StackState.hpp"
#include<iostream>
#include <string>

int main()
{
	Stack s(1);

	try
	{
		s.Pop();
	}
	catch (myException& e)
	{
		std::cout << e.message << std::endl;
	}

	s.Push(1);


	try
	{
		s.Push(1);
	}
	catch (myException& e)
	{
		std::cout << e.message << std::endl;
	}

	std::cout << s.Pop() << std::endl;

	

}