// Line.hpp
//
// Header file for Lines Segment


#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
using namespace std;

class Line : public Shape
{
private:
	Point m_p1; // Start point
	Point m_p2; // End point

public:
	// Constructors and destructor
	Line(); // Default constructor
	Line(const Line& line); // Copy constructor
	Line(const Point& p1, const Point& p2); // Constructor accepting two points
	virtual ~Line(); // Destructor

	// Member operator overloading
	Line& operator = (const Line& source); // Assignment operator

	// Accessing functions
	Point P1() const; // The start point
	void P1(const Point& p1);

	Point P2() const; // The end point
	void P2(const Point& p2);

	// Global operator overloading
	friend ostream& operator << (ostream& os, const Line& l); // Send to ostream

	string ToString() const;
	double Length() const;

	
};

#endif