// Point.cpp
// Models Point (x,y)

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>



// Constructors and destructor
Point::Point() : Shape()
{ // Default constructor
	m_x = 0.0;
	m_y = 0.0;
}

Point::Point(const Point& source) : Shape(source)
{ // Copy constructor
	m_x = source.m_x;
	m_y = source.m_y;
}

Point::Point(double x, double y) : Shape()
{ // Constructor accepting x- and y-coordinates
	m_x = x;
	m_y = y;
}

Point::~Point()
{ // Destructor
	cout << "Point destructor." << endl;
}

Point& Point::operator = (const Point& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Shape::operator = (source);

	// Copy state
	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}

double Point::X() const
{
	return m_x;
}

void Point::X(double x)
{
	m_x = x;
}


double Point::Y() const
{
	return m_y;
}

void Point::Y(double y)
{
	m_y = y;
}

ostream& operator << (ostream& os, const Point& p)
{ // Send to ostream

	os << "Point(" << p.m_x << "," << p.m_y << ")";

	return os;
}

string Point::ToString() const
{
	stringstream stream;
	std::string s = Shape::ToString();

	stream << "Point(" << m_x << "," << m_y << "), " << s;

	return stream.str();
}

double Point::Distance(const Point& p, shared_ptr<DistanceStrategy> strat) const
{// Distance from self to Point p
	return strat->Distance(*this, p);
}

double Point::Distance(shared_ptr<DistanceStrategy> strat) const
{//Distance from self to origin
	return strat->Distance(*this, *op.instance());
}

std::shared_ptr<Shape> Point::Clone() const
{
	return std::shared_ptr<Shape>(new Point(*this));
};