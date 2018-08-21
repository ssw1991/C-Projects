#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "OriginPoint.hpp"
#include <iostream>
#include <string>


// File to test additional features

int main()
{
	Point p(1.0, 1.0);
	


	
	std::cout << p.Distance() << std::endl; //Sqrt 2

	(*op.instance()).X(15.0);
	(*op.instance()).Y(13.0);

	std::cout << p.Distance() << std::endl;
	return 0;
}