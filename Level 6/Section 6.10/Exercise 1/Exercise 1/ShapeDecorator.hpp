// File to decorate Shape with name

#ifndef SHAPEDECORATOR_HPP
#define SHAPEDECORATOR_hpp

class ShapeDecorator; // Forward declaration
#include "Shape.hpp"
#include <memory>


class ShapeDecorator : public Shape
{
private:
	std::shared_ptr<Shape> m_shape;
public:
	ShapeDecorator(std::shared_ptr<Shape> ptr): m_shape(ptr) {};
	virtual ~ShapeDecorator() {};

	std::shared_ptr<Shape> GetShape() const
	{
		return m_shape;
	};

	void SetShape(std::shared_ptr<Shape> s)
	{
		m_shape = s;
	};

	// Class is still ABC because it does not implement Clone
};
#endif