#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>


// Base class

class Base
{
private:

public:
	Base() { }
	virtual void print() const = 0;
protected:
	virtual ~Base() 
	{ 
		std::cout << "Base destructor\n\n"; 
	}
};


// Derived class
class Derived : public Base
{
private:

public:
	Derived() : Base() { }
	~Derived() 
	{ 
		std::cout << "Derived destructor\n"; 
	}
	void print() const
	{ 
		std::cout << "derived object\n"; 
	}
};

#endif