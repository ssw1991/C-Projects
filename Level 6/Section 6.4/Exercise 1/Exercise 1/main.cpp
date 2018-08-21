#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "OriginPoint.hpp"
#include <iostream>
#include <string>
#include "ShapeComposite.hpp"


// File to test additional features




int main()
{
	ShapeComposite s2;


	std::shared_ptr<Circle> pt1(new Circle());
	std::shared_ptr<Line> pt2(new Line());
	std::shared_ptr<Point> pt3(new Point());

	std::shared_ptr<ShapeComposite> s(new ShapeComposite());

	s->AddShape(pt1);
	s->AddShape(pt2);
	s->AddShape(pt3);
	s->Print();

	s2.AddShape(s);

	auto s3 = s2.Clone();
	(*s3).Clone();  // This will test all clones

	auto s4 = s2;  // Checks assignment
	
	return 0;
}