#ifndef TRYLOCK_H
#define TRYLOCK_H
#include <mutex>
/*
This class will encapuslate std::try_lock to keep a count of failed attempts
*/

class TryLock
{
public:
	static int count;

	bool operator () (std::mutex& lock)
	{
		bool locked = false;
		while (!locked)
		{
			if (!lock.try_lock())
				TryLock::count++;
			else
				return true;
		}
	}
};

#endif