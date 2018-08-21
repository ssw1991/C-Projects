

#include <memory>
#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"
#include "NameDecorator.hpp"
#include <string>

int main()
{
	std::shared_ptr<Shape> ptr(new Point());
	NameDecorator dec(ptr, "Name");

	std::cout << dec << std::endl;
	std::cout << dec.GetShape()->ToString() << std::endl;
	std::cout << dec.GetName() << std::endl;

	dec.SetShape(std::shared_ptr<Shape>(new Point(1, 1)));
	dec.SetName("New Name");

	std::cout << dec << std::endl;

	auto dec2 = dec.Clone();

	std::cout << dec2->ToString() << std::endl;
	
}