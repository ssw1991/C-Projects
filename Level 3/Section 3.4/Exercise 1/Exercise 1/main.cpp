#include <iostream>
#include <future> 
#include <chrono>


void func1()
{
	std::cout << "Hello from Func 1" << std::endl;
}

double func2(double a, double b)
{
	return a * b;
}


int main()
{

	auto a = std::async(func1);
	auto b = std::async(func2, 1.5, 2.5);
	b.wait();  // giving a time to finish (they were printing on same line)
	if (b.valid())
		std::cout << b.get() << std::endl;

	auto a1 = std::async(std::launch::async, func1);
	auto b1 = std::async(std::launch::async, func2, 1.5, 2.5);
	if (b1.valid())
		std::cout << b1.get() << std::endl;

	// std::cout << b1.get();  runtime error

	/*
		With the launch policy, i didnt need to make b wait, otherwise I cant see 
		any difference
	*/
	auto a2 = std::async(std::launch::deferred, func1);
	std::this_thread::sleep_for(std::chrono::duration<int>(2));   // force a 2 second wait
	a2.get();   // make a2 compute  should see a delay on console.
}