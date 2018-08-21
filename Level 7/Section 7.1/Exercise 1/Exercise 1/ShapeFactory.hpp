// Shape Factory

#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>
#include "Shape.hpp"
#include <tuple>

using MyTuple = std::tuple<std::shared_ptr<Shape>, std::shared_ptr<Shape>, std::shared_ptr<Shape>>;
class ShapeFactory
{
private:
	virtual std::shared_ptr<Shape> CreateCirlce() const = 0;
	virtual std::shared_ptr<Shape> CreateLine() const = 0;
	virtual std::shared_ptr<Shape> CreatePoint() const = 0;
public:
	virtual MyTuple CreateShapes() const = 0;
};

#endif