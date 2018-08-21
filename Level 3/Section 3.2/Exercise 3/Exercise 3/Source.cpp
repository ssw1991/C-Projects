#include <iostream>
#include <thread>
#include "ActiveObject.cpp"


void iPrint(int n)
{
	for (int i = 0; i <= n; i++)
		std::cout << i << ": Hello" << std::endl;
}



int main()
{
	std::thread t;
	std::thread t1(iPrint, 10);
	auto lambdaFunc = []() {std::cout << "Lamdba Here" << std::endl; };
	try
	{
		ActiveObject a(t);
	}
	catch (std::system_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		ActiveObject a1(t1);
	}
	catch (std::system_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::thread t3(lambdaFunc);
	try
	{
		ActiveObject a2(t3);
	}
	catch (std::system_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	
}