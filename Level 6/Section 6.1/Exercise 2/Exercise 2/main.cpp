#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include <iostream>
#include <string>


// File to test additional features

int main()
{
	
	Point p1(1.0, 2.0);
	Point p2(4.3,2.9);
	Line l2(p1, p2);
	
	std::cout << "Length: " << l2.Length() << std::endl;  // This test Points Distance function
	std::cout << "Dist from Origin: " << p1.Distance();

}