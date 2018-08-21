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

	s2.Print();

	std::cout << "s1 size: " << s->count() << " s2 size: " << s2.count() << std::endl;

	/*
	This hangs, and I believe it is because there is a memory leak somewhere but I cannot find it
	*/
	return 0;
}