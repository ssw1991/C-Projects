// Counter Class

#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Subject.hpp"
#include <list>
#include "Observer.hpp"


class Counter: public Subject, public Observer // Had to inherit from both so this could be an observer to the Propegator
{
private:
	int value;
	std::list<std::shared_ptr<Observer>> data;

public:
	Counter(): value(0) 
	{	
		std::shared_ptr<Observer> ptr = std::make_shared<Observer>(*this);
		Subject::Attach(ptr);
	};

	int GetCounter() override
	{
		return value;
	}

	void IncreaseCounter()
	{
		value += 1;
		Subject::Notify();  // This will have the parent class call update on all 
							// Observer, of which this one is.   In turn Counter will 
							// Call update on all its observers
	}

	void DecreaseCounter()
	{
		value -= 1;
		Subject::Notify();
	}
	
	void Attach(std::shared_ptr<Observer> o)
	{
		data.push_back(o);
	};

	void Remove(std::shared_ptr<Observer> o)
	{
		data.remove(o);
	};

	void Notify() override
	{
		std::cout << "Here" << std::endl;
		for (auto i : data)
		{
			i->Update(this);
		}
	};

	void Update(Subject* s) override
	{
		std::cout << "From Counter: " << GetCounter() << std::endl;
		Notify();
	};
};

#endif