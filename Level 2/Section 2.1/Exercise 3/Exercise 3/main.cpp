#include "Shape.hpp"
#include <iostream>




int main()
{
	std::cout << std::boolalpha;

	// Check if empty

	std::cout << "Is empty: " << std::endl;
	std::cout << "Shape: " <<  std::is_empty<Shape>::value << std::endl;
	std::cout << "Base: " << std::is_empty<Base>::value << std::endl;
	std::cout << "Point: " << std::is_empty<Point>::value << std::endl;

	// Check if Polymorphic

	std::cout << std::endl << "Is Polymorphic: " << std::endl;
	std::cout << "Shape: " << std::is_polymorphic<Shape>::value << std::endl;
	std::cout << "Base: " << std::is_polymorphic<Base>::value << std::endl;
	std::cout << "Point: " << std::is_polymorphic<Point>::value << std::endl;

	// Check if Abstract

	std::cout << std::endl << "Is Abstract: " << std::endl;
	std::cout << "Shape: " << std::is_abstract<Shape>::value << std::endl;
	std::cout << "Base: " << std::is_abstract<Base>::value << std::endl;
	std::cout << "Point: " << std::is_abstract<Point>::value << std::endl;

	// Which are the same

	std::cout << std::endl << "Is Same: " << std::endl;
	std::cout << "Shape, Point: " << std::is_same<Shape, Point>::value << std::endl;
	std::cout << "Shape, Base: " << std::is_same<Shape, Base>::value << std::endl;
	std::cout << "Base, Point: " << std::is_same<Base, Point>::value << std::endl;


	// Base / Derived relationship
	
	std::cout << std::endl << "X base of Y:" << std::endl;
	std::cout << "Shape, Point: " << std::is_same<Shape, Point>::value << std::endl;
	std::cout << "Point, Shape: " << std::is_same<Point, Shape>::value << std::endl;
	std::cout << "Shape, Base: " << std::is_same<Shape, Base>::value << std::endl;
	std::cout << "Base, Shape: " << std::is_same<Base, Shape>::value << std::endl;
	std::cout << "Base, Point: " << std::is_same<Base, Point>::value << std::endl;
	std::cout << "Point, Base: " << std::is_same<Point, Base>::value << std::endl;

	// Convertible

	std::cout << std::endl<< "X convertible to Y:" << std::endl;
	std::cout << "Shape, Point: " << std::is_convertible<Shape, Point>::value << std::endl;
	std::cout << "Point, Shape: " << std::is_convertible<Point, Shape>::value << std::endl;
	std::cout << "Shape, Base: " << std::is_convertible<Shape, Base>::value << std::endl;
	std::cout << "Base, Shape: " << std::is_convertible<Base, Shape>::value << std::endl;
	std::cout << "Base, Point: " << std::is_convertible<Base, Point>::value << std::endl;
	std::cout << "Point, Base: " << std::is_convertible<Point, Base>::value << std::endl;
	return 0;
}