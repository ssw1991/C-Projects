// Circle.cpp
// Models a Circle with Radius and CenterPoint

#include "Circle.hpp"
#include "Point.hpp"
#include <sstream>
#include <iostream>

// Constructors and destructor
Circle::Circle() : Shape()
{ // Default constructor
	p_center = Point(0.0, 0.0);
	m_radius = 1.0;
}

Circle::Circle(const Circle& source) : Shape(source)
{ // Copy constructor
	p_center = source.p_center;
	m_radius = source.m_radius;
}

Circle::Circle(const Point& center, double r) : Shape()
{
	p_center = center;
	m_radius = r;
}

Circle::~Circle()
{ 
	cout << "Circle Destructor" << endl;
}

Circle& Circle::operator = (const Circle& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Shape::operator = (source);

	// Copy state
	p_center = source.p_center;
	m_radius = source.m_radius;

	return *this;
}

Point Circle::CenterPoint() const
{
	return p_center;
}

void Circle::CenterPoint(const Point& center)
{
	p_center = center;
}

double Circle::Radius() const
{
	return m_radius;
}

void Circle::Radius(double radius)
{
	m_radius = radius;
}

ostream& operator << (ostream& os, const Circle& c)
{ // Send to ostream

	os << "Center: " << c.p_center << ", Radius: " << c.m_radius;

	return os;
}

string Circle::ToString() const
{
	stringstream stream;
	std::string s = Shape::ToString();

	stream << "Center: " << p_center.ToString() << ", Radius: " << m_radius << ", " << s;

	return stream.str();
}
