// Shape Visitor

#ifndef PRINTVISITOR_HPP
#define PRINTVISITOR_HPP

class PrintVisitor;   // Forward Declaration
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "ShapeComposite.hpp"
#include <iostream>
#include "ShapeVisitor.hpp"


class PrintVisitor: ShapeVisitor
{

public:
	PrintVisitor() {};
	~PrintVisitor() {};

	void Visit(Point& p) const override
	{
		std::cout << p << std::endl;
	}

	void Visit(Line& l) const override
	{
		std::cout << l << std::endl;
	}
	
	void Visit(Circle& c) const override
	{
		std::cout << c << std::endl;
	}

	void Visit(ShapeComposite& sc) const override
	{
		sc.Print();
	}
};

#endif