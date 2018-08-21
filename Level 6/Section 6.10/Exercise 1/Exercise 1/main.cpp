
#include <iostream>
#include <string>
#include "ShapeComposite.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "PrintVisitor.hpp"
#include "ShapeVisitor.hpp"
#include "TranslateVisitor.hpp"
// File to test additional features

int main()
{

	ShapeComposite s2;
	// std::shared_ptr<ShapeVisitor> v(new PrintVisitor());
	// The above line should work, and I cant see why it doesnt
	std::shared_ptr<PrintVisitor> v(new PrintVisitor());
	std::shared_ptr<TranslateVisitor> t(new TranslateVisitor(1,1));

	std::shared_ptr<Shape> pt1(new Circle());
	std::shared_ptr<Shape> pt2(new Line());
	std::shared_ptr<Shape> pt3(new Point());

	std::shared_ptr<ShapeComposite> s(new ShapeComposite());

	s->AddShape(pt1);
	s->AddShape(pt2);
	s->AddShape(pt3);

	s2.AddShape(s);
	
	t->Visit(s2);
	v->Visit(s2);

	v->Visit(s2);
	return 0;
}