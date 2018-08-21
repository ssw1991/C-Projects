//  Implementation of functions in   Line.hpp

#include "Line.hpp"
#include <cmath>
#include <sstream>
#include <boost/functional/hash.hpp>


Line::Line() : startPoint(Point()), endPoint(Point())		// Line with both start and end Points at the origin
{
}


Line::~Line()		// Destructor
{

}


Line::Line(const Point& p1, const Point& p2) //Overloaded constructor
{

	startPoint = p1;
	endPoint = p2;
}


Line::Line(const Line& l) // Copy constructor
{
	startPoint = l.startPoint;
	endPoint = l.endPoint;
}

//Assignment operator
Line& Line::operator = (const Line& source_line)
{
	// Avoid doing assign to myself
	if (this == &source_line)
		return *this;

	startPoint = source_line.startPoint;
	endPoint = source_line.endPoint;

	return *this;
}

bool Line::operator () (const Line& l) const
{
	return ((startPoint == l.startPoint) & (endPoint == l.endPoint));
}

// Global function to send a line directlry to the cout object.
std::ostream& operator <<(ostream& os_L, const Line& L)
{

	os_L << "Line between" << L.startPoint.ToString() << " and " << L.endPoint.ToString();
	return os_L;
}

std::size_t hash_value(const Line& l)
{ // Create a hash value for a point by combining the hash for start and end
	std::size_t seed = 0;
	boost::hash_combine(seed, l.startPoint);   // Delegate to hashing each point
	boost::hash_combine(seed, l.endPoint);
	return seed;
}
