// Console Factory

#ifndef CONSOLEFACTORY_HPP
#define CONSOLEFACTORY_HPP

#include <memory>
#include "Shape.hpp"
#include "ShapeFactory.hpp"
#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include <tuple>

using MyTuple = std::tuple<std::shared_ptr<Shape>, std::shared_ptr<Shape>, std::shared_ptr<Shape>>;

class ConsoleFactory: public ShapeFactory
{
private:
	std::shared_ptr<Shape> CreateCirlce() const override
	{
		double x, y, rad;
		std::cout << "Enter the radius\n";
		std::cin >> rad;
		std::cout << "Enter the CenterPoint x\n";
		std::cin >> x;
		std::cout << "Enter the CenterPoint y\n";
		std::cin >> y;

		return std::shared_ptr<Shape>(new Circle(Point(x, y), rad));
	}

	std::shared_ptr<Shape> CreateLine() const override
	{
		double x1, y1, x2, y2;

		std::cout << "Enter the StartPoint x\n";
		std::cin >> x1;
		std::cout << "Enter the StartPoint y\n";
		std::cin >> y1;

		std::cout << "Enter the EndPoint x\n";
		std::cin >> x2;
		std::cout << "Enter the EndPoint y\n";
		std::cin >> y2;

		return std::shared_ptr<Shape>(new Line(Point(x1, y1), Point(x2, y2)));

	}
	std::shared_ptr<Shape> CreatePoint() const override
	{
		double x1, y1;

		std::cout << "Enter the Point x\n";
		std::cin >> x1;
		std::cout << "Enter the Point y\n";
		std::cin >> y1;

		return std::shared_ptr<Shape>(new Point(x1, y1));
	};
public:

	virtual MyTuple CreateShapes()const override
	{
		std::shared_ptr<Shape> l = CreateLine();
		std::shared_ptr<Shape> c = CreateCirlce();
		std::shared_ptr<Shape> p = CreatePoint();

		MyTuple t{ l,c,p };
		return(t);
		
	};
};
#endif