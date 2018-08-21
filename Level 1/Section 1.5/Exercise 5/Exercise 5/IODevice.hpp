

#ifndef IODEVICE_HPP
#define IODEVICE_HPP

#include "Shapes.hpp"
#include <iostream>

/*

This project wont compile without the << operator overloads commented out.

The errors include that "void operator << (const int) has already been declared, 
which is confusing because in all cases the function parameter is either a line or 
a circle.

Additionally, it is saying that these functions are missing a type specifier when they all say void

The error file is included in this folder 
Any feedback on the issues here would be greatly appreciated. 
*/


class IODevice
{ // Interface for displaying CAD objects 
public:
	

	/*
	virtual void operator << (const Circle& c) const = 0;
	virtual void operator << (const Line& l) const = 0;
	*/
};


class Graphics : public IODevice
{
	
	/*
	void operator << (const Circle& c) const override
	{
		std::cout << "From Graphics: ";
		//c.display(*this);
	}

	void operator << (const Line& l) const override
	{
		std::cout << "From Graphics: ";
		//l.display(*this);
	}
	*/
	
};

class Mobile : public IODevice
{
	/*
	void operator << (const Circle& c) const override
	{
		std::cout << "From Mobile: ";// c.display;
	}

	void operator << (const Line& l) const override
	{
		std::cout << "From Mobile: ";// l.display;
	}
	*/
};


#endif