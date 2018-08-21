#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include <functional>
#include <memory>
#include <string>
#include <tuple>
#include "ShapeFactory.hpp"

struct CircleMaker
{ // Function object
	std::shared_ptr<Shape> operator () (double rad, double x, double y)
	{
		return std::shared_ptr<Shape>(new Circle(Point(x, y), rad));
	}
};


int main()
{

	auto clambda = [](double rad, double x, double y) {return std::shared_ptr<Shape>
		(new Circle(Point(x, y), rad)); };  // Function to create circle
	
	auto plambda = [](double x, double y) {return std::shared_ptr<Shape>
		(new Point(x,y)); };  // Function to create Point

	auto llambda = [](double x1, double y1, double x2, double y2) {return std::shared_ptr<Shape>
		(new Line(Point(x1, y1), Point(x2,y2))); };  // Function to create Line

	double x1 = 1.0;
	double x2 = 3.0;
	double y1 = 4.0;
	double y2 = 3.2;
	double rad = 1.5;

	// Functions for Factory
	auto cFunc = std::bind(clambda, rad, x1, y1);
	auto pFunc = std::bind(plambda, x1, y1);
	auto lFunc = std::bind(llambda, x1, y1, x2, y2);

	ShapeFactory Factory(pFunc, cFunc, lFunc);

	std::shared_ptr<Shape> l1 = Factory.CreateLine();
	std::shared_ptr<Shape> c1 = Factory.CreateCircle();
	std::shared_ptr<Shape> p1 = Factory.CreatePoint();


	std::cout << l1->ToString() << std::endl;
	std::cout << c1->ToString() << std::endl;
	std::cout << p1->ToString() << std::endl;

	CircleMaker cm;
	ShapeFactory Factory2(pFunc, std::bind(cm, rad, x1, y1), lFunc); // Using a Function object
	c1 = Factory.CreateCircle();
	std::cout << c1->ToString() << std::endl;

}


/*

This is similar to strategy in the sense we are telling the factory how and object should be created




*/