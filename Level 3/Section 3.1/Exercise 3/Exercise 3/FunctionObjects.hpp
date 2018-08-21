#ifndef FUNCTIONOBJECTS_H
#define FUNCTIONOBJECTS_H
#include <string>
#include <mutex>
#include <memory>
#include "LockFuncs.hpp"
/*
This file includes two function objects
1. is callable and has a static function
2. has a member function

Intent is to test std::threading with these callables


*/


class FunctionObject
{
public:
	static std::timed_mutex* mtx;  // Pointer to a lock to controll access to terminal
	
	static void Iprint(const std::string& s, int count)
	{ // Static Function to print s, count # of times to terminal
		
		for (int i = 0; i <= count; i++)
		{
			UniqueTryLock(*mtx); // Wait for Trylock to succeed
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
			mtx->unlock(); // Unlock 
		}
	}
	void operator () (const std::string& s, int count)
	{ // Callable Object to print s, count # of times to terminal

		for (int i = 0; i <= count; i++)
		{
			UniqueTryLockFor(*mtx); // Wait for Trylock to succeed
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
			mtx->unlock();
		}
	}
};

class FunctionObject2
{
private:
	std::timed_mutex* mtx;  // Pointer to lock

public:
	FunctionObject2(std::timed_mutex* newmtx) : mtx(newmtx)
	{}// Assign Lock;
	void Iprint(const std::string& s, int count)
	{ // Function to print s, count # of times to terminal
		for (int i = 0; i <= count; i++)
		{
			std::lock_guard<std::timed_mutex> lock(*mtx); // Guarded Lock
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
		}
	}
};



#endif

