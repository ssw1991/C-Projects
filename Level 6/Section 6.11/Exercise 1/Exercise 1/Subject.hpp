// Subject


#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <list>
#include <memory>
#include "Observer.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

class Subject
{
private:
	std::vector<std::shared_ptr<Observer>> data;

public:

	void Attach(std::shared_ptr<Observer> o)
	{
		data.push_back(o);
	};

	void Remove(std::shared_ptr<Observer> o)
	{
		data.remove(o);
	};

	void Notify()
	{
		//for(std::vector<std::shared_ptr<Observer>>::iterator i =data.begin(); i != data.end(); i++)
		for(auto i: data)
		{
			i->Update(this);
		}
	};
	
	virtual int GetCounter() =0;  // Had to include in base so that it can be called from a subject pointer
};
#endif