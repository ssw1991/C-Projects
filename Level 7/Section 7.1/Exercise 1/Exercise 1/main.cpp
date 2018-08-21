#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "ConsoleFactor.hpp"
#include <memory>
#include <string>
#include <tuple>


int main()
{
	std::shared_ptr<Shape> l1;
	std::shared_ptr<Shape> c1;
	std::shared_ptr<Shape> p1;

	ConsoleFactory Factory = ConsoleFactory();

	auto t = Factory.CreateShapes();
	

	std::cout << std::get<0>(t)->ToString() << std::endl;
	std::cout << std::get<1>(t)->ToString() << std::endl;
	std::cout << std::get<2>(t)->ToString() << std::endl;

}


/*

I think this method is more cumbersom.  The same level of 
effort would be needed to write code to add shapes in any 
case,  and it would be easier to spot errors by having 
individual functions create shapes.



*/