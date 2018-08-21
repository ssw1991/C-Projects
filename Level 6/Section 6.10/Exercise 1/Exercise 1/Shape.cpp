// Shape.cpp
//
// Base class for Shapes.

#include "Shape.hpp"
#include <sstream>
#include <iostream>

// Constructors and destructor
Shape::Shape() : m_id(rand())
{ // Default constructor
}

Shape::Shape(const Shape& source) : m_id(source.m_id)
{ // Copy constructor
}

Shape::~Shape()
{ // Destructor
	std::cout << "Shape destructor." << std::endl;
}

// Operator overloading
Shape& Shape::operator = (const Shape& source)
{// Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_id = source.m_id;

	return *this;
}

std::string Shape::ToString() const
{
	std::stringstream stream;

	stream << "ID: " << m_id;

	return stream.str();
}

// Accessing functions
int Shape::ID() const
{
	return m_id;
}

void Shape::Print() const
{
	std::cout << ToString() << std::endl;
};