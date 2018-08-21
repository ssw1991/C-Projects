#ifndef LOCKFUNCS_H
#define LOCKFUNCS_H


#include <mutex>
#include <chrono>
/*

Functions implemented to use locks 

*/



void UniqueTryLock(std::timed_mutex& mtx)
{
		std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock);
		bool locked = false;  // used to ensure exception was caught
		while (!locked)
		{	
			try
			{
				if (lock.try_lock())
				{ // If lock succeeds control returns to calling thread					
					return;
				}
			}
			catch (std::system_error& e)
			{
				if (e.code() == std::make_error_code(std::errc::operation_not_permitted))
				{ // Error if no lock
					std::cout << "The unique_lock does not own a lock\n";
				}
				else if (e.code() == std::make_error_code(std::errc::resource_deadlock_would_occur))
				{ // Error if already Locked 
					std::cout << "Already Locked\n";
				}
			}

		}
}

void UniqueTryLockFor(std::timed_mutex& mtx)
{
	std::chrono::duration<int> d{ 1 };
	std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock);
	try
	{
		lock.try_lock_for(d);
	}
	catch (std::system_error& e)
	{
		if (e.code() == std::make_error_code(std::errc::operation_not_permitted))
		{ // Error if no lock
			std::cout << "The unique_lock does not own a lock\n";
		}
		else if (e.code() == std::make_error_code(std::errc::resource_deadlock_would_occur))
		{ // Error if already Locked 
			std::cout << "Already Locked\n";
		}
	}
	return;
}

#endif