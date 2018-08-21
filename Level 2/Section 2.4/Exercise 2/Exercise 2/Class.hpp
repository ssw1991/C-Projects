#ifndef CLASS_H
#define CLASS_H


#include <memory>
#include <iostream>
class C1
{
private:

	std::shared_ptr<double> d;
public:
	C1(std::shared_ptr<double>& value) : d(value) 
	{
		std::cout << d.use_count() << std::endl;
	}

	int use_count()
	{
		return d.use_count();
	}

	virtual ~C1() 
	{ 
		d.reset();
		
		std::cout << "\nC1 destructor\n";
	}
	void print() const { std::cout << "Value " << *d; }
};

class C2
{
private:
	
	std::shared_ptr<double> d;
public:
	C2(std::shared_ptr<double>& value) : d(value) 
	{
		std::cout << d.use_count() << std::endl;
	}

	int use_count()
	{
		return d.use_count();
	}

	virtual ~C2() { std::cout << "\nC2 destructor\n"; }
	void print() const { std::cout << "Value " << *d; }
};



#endif