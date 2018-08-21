// Shape Factory

#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>
#include "Shape.hpp"

class ShapeFactory
{
public:

	virtual std::shared_ptr<Shape> CreateCirlce() const = 0;
	virtual std::shared_ptr<Shape> CreateLine() const = 0;
	virtual std::shared_ptr<Shape> CreatePoint() const = 0;
};

#endif