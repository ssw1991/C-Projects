// Point.hpp
//
// Header file for Point(x,y)

#ifndef Point_HPP
#define Point_HPP

#include "Shape.hpp"
#include <iostream>

// Forward reference for point
class Point;
#include "OriginPoint.hpp"

using namespace std;

class Point : public Shape
{
private:
	double m_x; // x-coordinate
	double m_y; // y-coordinate

public:
	// Constructors and destructor
	Point(); // Default constructor
	Point(const Point& source); // Copy constructor
	Point(double x, double y); // Constructor accepting x- and y-coordinates
	~Point(); // Destructor

	// Member operator overloading
	Point& operator = (const Point& source); // Assignment operator

	// Accessing functions
	double X() const; // The x-coordinate
	void X(double newX);

	double Y() const; // The y-coordinate
	void Y(double newY);

	// Global operator overloading
	friend ostream& operator << (ostream& os, const Point& p); // Send to ostream

	string ToString() const;

	double Distance(const Point& p) const;
	double Distance() const;

};

#endif