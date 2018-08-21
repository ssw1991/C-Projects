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

class ConsoleFactory: public ShapeFactory
{
public:

	std::shared_ptr<Circle> CreateCirlce() const
	{
		double x, y, rad;
		std::cout << "Enter the radius\n";
		std::cin >> rad;
		std::cout << "Enter the CenterPoint x\n";
		std::cin >> x;
		std::cout << "Enter the CenterPoint y\n";
		std::cin >> y;

		return std::shared_ptr<Circle>(new Circle(Point(x, y), rad));
	}
	
	std::shared_ptr<Point> CreatePoint() const
	{
		double x1, y1;

		std::cout << "Enter the Point x\n";
		std::cin >> x1;
		std::cout << "Enter the Point y\n";
		std::cin >> y1;

		return std::shared_ptr<Point>(new Point(x1, y1));
	};

	template< template<class, class> class Container, typename TPoint, typename Alloc = std::allocator<TPoint>>
	std::shared_ptr<PolyLine<Container, TPoint>> CreatePolyLine() const
	{
		return std::shared_ptr<PolyLine<Container, TPoint>>(new PolyLine<Container, TPoint>());

	}
};
#endif