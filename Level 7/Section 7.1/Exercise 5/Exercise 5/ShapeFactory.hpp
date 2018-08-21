// Shape Factory

#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "PolyLine.hpp"

class ShapeFactory
{
public:

	virtual std::shared_ptr<Circle> CreateCirlce() const = 0;

	virtual std::shared_ptr<Line> CreateLine() const final
	{ // Cant label a Template Function final.  

		return std::shared_ptr<Line>(new Line(*CreatePoint(), *CreatePoint()));

	}
	virtual std::shared_ptr<Point> CreatePoint() const = 0;

	
};

#endif