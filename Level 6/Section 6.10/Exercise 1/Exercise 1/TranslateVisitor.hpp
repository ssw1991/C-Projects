// Shape Visitor

#ifndef TRANSLATEVISITOR_HPP
#define TRANSLATEVISITOR_HPP

class TranslateVisitor;   // Forward Declaration
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "ShapeComposite.hpp"
#include <iostream>
#include "ShapeVisitor.hpp"


class TranslateVisitor : ShapeVisitor
{
private:
	double x, y; // move
public:
	TranslateVisitor(double _x, double _y) : x(_x), y(_y) {};
	~TranslateVisitor() {};

	void Visit(Point& p) const override
	{
		p.Translate(x, y);
	}

	void Visit(Line& l) const override
	{
		l.Translate(x, y);
	}

	void Visit(Circle& c) const override
	{
		c.Translate(x, y);
	}

	void Visit(ShapeComposite& sc) const override
	{
		sc.Translate(x, y);
	}
};

#endif