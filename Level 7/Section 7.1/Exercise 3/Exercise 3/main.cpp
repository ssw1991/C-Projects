#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "ConsoleFactor.hpp"
#include <memory>
#include <string>
#include "PolyLine.hpp"
#include <vector>
#include "ExactDistance.hpp"
#include "ApproximateDistance.hpp"


int main()
{
	PolyLine< std::vector, Point > myPoly; 

	myPoly.add(Point(1, 1));
	myPoly.add(Point(2, 5));
	myPoly.add(Point(3, 1));

	PolyLine< std::vector, Point > myPoly2 = myPoly;

	std::cout << myPoly;
	std::cout << myPoly2;

	

	std::cout << myPoly.Length(std::shared_ptr<DistanceStrategy>(new ApproximateDistance())) << std::endl;
	std::cout << myPoly.Length(std::shared_ptr<DistanceStrategy>(new ExactDistance())) << std::endl;

	ConsoleFactory myFac;

	auto myPoly3 = myFac.CreatePolyLine<std::vector, Point>();
	myPoly3->add(Point(1, 1));

	std::cout << *( myPoly3.get());
}