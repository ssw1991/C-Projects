#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "ConsoleFactor.hpp"
#include <memory>
#include <string>


int main()
{
	std::shared_ptr<Shape> l1;
	std::shared_ptr<Shape> c1;
	std::shared_ptr<Shape> p1;

	ConsoleFactory Factory = ConsoleFactory();


	l1 = Factory.CreateLine();
	c1 = Factory.CreateCirlce();
	p1 = Factory.CreatePoint();

	std::cout << l1->ToString() << std::endl;
	std::cout << c1->ToString() << std::endl;
	std::cout << p1->ToString() << std::endl;

}