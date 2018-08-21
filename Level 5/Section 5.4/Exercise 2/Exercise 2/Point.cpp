#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <boost/functional/hash.hpp>
using namespace std;

Point::Point(): m_x(0.0), m_y(0.0) // Default constructor
{
}

Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y) // Copy constructor
{	
}

Point::Point(double xValue, double yValue) : m_x(xValue), m_y(yValue) // Constructor that accepts x- and y-coordinates
{
}

Point::~Point() // Destructor
{
}

string Point::ToString() const
{
	stringstream stream;

	stream << "Point(" << m_x << "," << m_y << ")";

	return stream.str();
}

double Point::Distance() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(const Point& p) const
{
	// p.SetX(); // Result in compiler error.
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}

std::size_t hash_value(const Point& p)
{ // Create a hash value for a point by combining the hash for x and y
	std::size_t seed = 0;
	boost::hash_combine(seed, p.m_x);
	boost::hash_combine(seed, p.m_y);
	return seed;
}