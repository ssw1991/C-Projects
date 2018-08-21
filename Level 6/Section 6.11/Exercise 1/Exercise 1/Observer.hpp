// Observer

#ifndef OBSERVER_HPP
#define OBSERVER_HPP



#include <memory>
//#include "Subject.hpp"


class Subject;
class Observer
{
public:
	virtual void Update(Subject* s) = 0;
};

#endif