// Shape Visitor

#ifndef SHAPEVISITOR_HPP
#define SHAPEVISITOR_HPP

class ShapeVisitor;

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "ShapeComposite.hpp"


class ShapeVisitor 
{
public:
	ShapeVisitor() {};
	~ShapeVisitor() {};

	virtual void Visit(Line& s) const = 0;
	virtual void Visit(Circle& s) const = 0;
	virtual void Visit(ShapeComposite& s) const = 0;
	virtual void Visit(Point& s) const = 0;
};



#endif
