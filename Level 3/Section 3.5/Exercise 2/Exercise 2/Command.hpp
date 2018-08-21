#ifndef COMMAND_H
#define COMMAND_H

#include<functional>
#include <iostream>

using FunctionType = std::function<double(double)>;

class Command
{
private:
	long ID; // priority of command
	FunctionType algo;

public:
	Command(const FunctionType& algorithm, long priority)
		: algo(algorithm), ID(priority) {}

	void Execute(double x) 
	{
	
		std::cout << ID <<" Priority:  "<< algo(x) << '\n';
	}

	int priority() const
	{
		return ID;
	}

	friend bool operator < (const Command& a, const Command b)
	{ // Comparator
		return a.ID < b.ID;
	}

	friend bool operator > (const Command& a, const Command b)
	{ // Comparator
		return a.ID > b.ID;
	}
};

#endif