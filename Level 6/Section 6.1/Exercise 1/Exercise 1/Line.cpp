// Line.cpp
// Models a line segment (Point a - Point b)
#include "Line.hpp"
#include "Point.hpp"
#include <sstream>
#include <iostream>

// Constructors and destructor
Line::Line() : Shape()
{ // Default constructor
	m_p1 = Point(0.0, 0.0);
	m_p2 = Point(0.0, 0.0);
}

Line::Line(const Line& source) : Shape(source)
{ // Copy constructor
	m_p1 = source.m_p1;
	m_p2 = source.m_p2;
}

// Constructor accepting two points with colon syntax.
Line::Line(const Point& p1, const Point& p2) : Shape()
{ // Constructor accepting two points
	m_p1 = p1;
	m_p2 = p2;
}

Line::~Line()
{ // Destructor
	//cout << "Line destructor." << endl;
}

Line& Line::operator = (const Line& source)
{ // Assignment operator.

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Shape::operator = (source);

	// Copy state
	m_p1 = source.m_p1;
	m_p2 = source.m_p2;

	return *this;
}

Point Line::P1() const
{
	return m_p1;
}

void Line::P1(const Point& p1)
{
	m_p1 = p1;
}

Point Line::P2() const
{
	return m_p2;
}

void Line::P2(const Point& p2)
{
	m_p2 = p2;
}

ostream& operator << (ostream& os, const Line& l)
{ // Send to ostream

	os << "Line: " << l.m_p1 << "-" << l.m_p2 << endl;  // Delegate to Point <<

	return os;
}

string Line::ToString() const
{
	stringstream stream;
	std::string s = Shape::ToString();

	stream << "Line: " << m_p1.ToString() << "-" << m_p2.ToString() << ", " << s;

	return stream.str();
}
