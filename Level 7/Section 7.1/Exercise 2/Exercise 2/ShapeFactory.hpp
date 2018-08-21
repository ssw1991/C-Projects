// Shape Factory

#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>
#include "Shape.hpp"
#include <functional>

using Func = std::function<std::shared_ptr<Shape>()>;
class ShapeFactory
{
private:
	Func pFunc;
	Func cFunc;
	Func lFunc;
public:
	ShapeFactory(Func p, Func c, Func l): pFunc(p), cFunc(c), lFunc(l) {};

	std::shared_ptr<Shape> CreatePoint()
	{
		return pFunc();
	}

	std::shared_ptr<Shape> CreateLine()
	{
		return lFunc();
	}

	std::shared_ptr<Shape> CreateCircle()
	{
		return cFunc();
	}
};

#endif