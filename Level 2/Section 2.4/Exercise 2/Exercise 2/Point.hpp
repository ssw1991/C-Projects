#ifndef POINT_H
#define POINT_H

#include <iostream>
class Point
{
private:
	double m_x;
	double m_y;
public:

	Point() // Default constructor
	{
		std::cout << "Default Constructor Called." << std::endl;
	}

	Point(const Point& point) : m_x(point.m_x), m_y(point.m_y) // Copy constructor
	{
		std::cout << "Copy Constructor Called." << std::endl;
	}

	Point(double xValue, double yValue) : m_x(xValue), m_y(yValue) // Constructor that accepts x- and y-coordinates
	{
		std::cout << "Constructor Accepting x- and y-coordinates Called." << std::endl;
	}

	~Point() // Destructor
	{
		std::cout << "Destructor Called." << std::endl;
	}

	void X(double newX)
	{
		m_x = newX;
	}

	void Y(double newY)
	{
		m_y = newY;
	}

	void Print()
	{
		std::cout << "x: " << m_x << ", y: " << m_y << std::endl;
	}
};


#endif