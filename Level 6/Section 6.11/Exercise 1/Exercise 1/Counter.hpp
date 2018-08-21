// Counter Class

#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Subject.hpp"

class Counter: public Subject
{
private:
	int value;
public:
	Counter(): value(0) {};

	int GetCounter() override
	{
		return value;
	}

	void IncreaseCounter()
	{
		value += 1;
		this->Notify();
	}

	void DecreaseCounter()
	{
		value -= 1;
		this->Notify();
	}
};

#endif