/*

Class to model a point

*/
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Point
{
private:
	double m_x; // x-coordinate
	double m_y; // y-coordinate

public:
	Point(); // Default constructor
	Point(const Point& point); // Copy constructor
	Point(double xValue, double yValue); // Constructor that accepts x- and y-coordinates

	~Point(); // Destructor

	// Accessing functions
	double X() const; // Getter function for x-coordinate
	double Y() const; // Getter function for y-coordinate

	// Equality check
	bool operator () (const Point& p) const;

	// Modifiers
	void X(double newX) { m_x = newX; } // Setter function for x-coordinate
	void Y(double newY) { m_y = newY; } // Setter function for y-coordinate

	string ToString() const; // String description of the point

	bool friend operator == (const Point& p1, const Point& p2)  // Identify equality of two points
	{
		return ((p1.m_x == p2.m_x) & (p1.m_y == p2.m_y));
	}

	double Distance() const; // Calculate the distance to the origin (0, 0).
	double Distance(const Point& p) const; // Calculate the distance between two points.

	friend std::size_t hash_value(const Point& p);
};


#endif