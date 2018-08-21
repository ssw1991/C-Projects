#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>
#include <string>


// File to test shape heirachy

int main()
{
	// Test point

	// Constructors
	Point p1;
	Point p2(1.0, 2.0);
	Point p3(p1);

	std::cout << p1 << p2 << p3 << std::endl;

	// Accessors
	p1.X(4.3);
	p1.Y(2.9);

	std::cout << p1 << std::endl;

	// Functions 
	std::cout << p1.ToString() << std::endl;
	std::cout << p1.X() << ", " << p1.Y() << std::endl;
	
	// Test Line

	Line l1;
	Line l2(p1, p2);
	Line l3(l1);

	std::cout << l1 << l2 << l3 << std::endl;

	// Accessors

	l1.P1(p1);
	l1.P2(p2);

	std::cout << l1 << std::endl;

	// Functions

	std::cout << l1.ToString() << std::endl;
	std::cout << l1.P1() << ", " << l1.P2() << std::endl;


	// Test Circle

	Circle c1;
	Circle c2(p1, 1.0);
	Circle c3(c1);

	std::cout << c1 << c2 << c3 << std::endl;

	//Accessors

	c1.CenterPoint(p1);
	c1.Radius(2.0);
	std::cout << c1 << std::endl;

	// Functions

	std::cout << c1.ToString() << std::endl;
	std::cout << c1.CenterPoint() << ", " << c1.Radius() << std::endl;

}