// Observer

#ifndef OBSERVER_HPP
#define OBSERVER_HPP



#include <memory>
#include <iostream>
#include "Subject.hpp"


class Subject;
class Observer
{// In the new construct this is derived, but only as an interface?
	// ensuring that an update method is present
public:
	virtual void Update(Subject* s) 
	{};
};

#endif