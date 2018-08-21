// Shape.hpp
//
// Base class for Shapes.


#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape; // Forward Declaration

#include <iostream>
#include <memory>
//#include "ShapeVisitor.hpp"
class ShapeVisitor;

class Shape
{
private:
	int m_id; // ID

public:
	// Constructors and destructor
	Shape(); // Constructor
	Shape(const Shape& source); // Copy constructor
	virtual ~Shape(); // Destructor

	// Operator overloading
	Shape& operator = (const Shape& source); // Assignment operator

	virtual std::string ToString() const;

	// Accessing functions
	int ID() const;

	virtual void Print() const;

	virtual void Accept(std::shared_ptr<ShapeVisitor> v) = 0;

	virtual std::shared_ptr<Shape> Clone() const = 0; // Pure Virtual Function

	virtual void Translate(double x, double y) = 0;
};

#endif
