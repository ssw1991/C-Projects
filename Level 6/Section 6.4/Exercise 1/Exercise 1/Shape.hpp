// Shape.hpp
//
// Base class for Shapes.


#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>
#include <memory>
using namespace std;

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

	virtual string ToString() const;

	// Accessing functions
	int ID() const;

	virtual void Print() const;

	virtual std::shared_ptr<Shape> Clone() const = 0; // Pure Virtual Function
};

#endif
