// Header File to for Shape Heirarchy

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include "IODevice.hpp"

class Shape
{
public:
	virtual void display() const = 0;
};

class Circle : public Shape
{
public:
	Circle()
	{
		std::cout << "Circle construct";
	}
	void display() const override
	{
		std::cout << "Hello from circle\n";
	}
};


class Line : public Shape
{
public:
	void display() const override
	{
		std::cout << "Hello from Line\n";
	}
};

#endif