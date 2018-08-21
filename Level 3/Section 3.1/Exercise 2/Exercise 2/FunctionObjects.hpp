#ifndef FUNCTIONOBJECTS_H
#define FUNCTIONOBJECTS_H
#include <string>
#include <mutex>
#include <memory>
#include "TryLock.hpp"

/*
This file includes two function objects
1. is callable and has a static function
2. has a member function

Intent is to test std::threading with these callables


*/

TryLock counter1;

class FunctionObject
{
public:
	static std::mutex* mtx;  // Pointer to a lock to controll access to terminal
	
	static void Iprint(const std::string& s, int count)
	{ // Static Function to print s, count # of times to terminal

		for (int i = 0; i <= count; i++)
		{
			counter1(*mtx); // Wait for Trylock to succeed
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
			mtx->unlock(); // Unlock 
		}
	}
	void operator () (const std::string& s, int count)
	{ // Callable Object to print s, count # of times to terminal

		for (int i = 0; i <= count; i++)
		{
			counter1(*mtx); // Wait for Trylock to succeed
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
			mtx->unlock();
		}
	}
};

class FunctionObject2
{
private:
	std::mutex* mtx;  // Pointer to lock

public:
	FunctionObject2(std::mutex* newmtx) : mtx(newmtx)
	{}// Assign Lock};
	void Iprint(const std::string& s, int count)
	{ // Function to print s, count # of times to terminal
		for (int i = 0; i <= count; i++)
		{
			counter1(*mtx); // Wait for Trylock to succeed
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
			mtx->unlock();
		}
	}
};



#endif

