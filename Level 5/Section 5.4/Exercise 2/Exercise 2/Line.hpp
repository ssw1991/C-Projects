// Line.hpp

// A line in 2 dimensions. This class represents an undirected
// line segment between two given points.


#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include <iostream>
#include <string>

using namespace std;

class Line

{

private:

	Point startPoint;	// Start point of the line
	Point endPoint;		// End point of the line

public:

	// Constructors
	Line();									// Line with both start and end Points at the origin
	Line(const Point& p1, const Point& p2);	// Line with start and end Points [p1, p2]
	Line(const Line& l); 					// Copy constructor
	~Line();								// Destructor


	Line& operator = (const Line& source);			//Assignment operator.

	friend std::ostream& operator << (ostream& os_L, const Line& L);	// Global function to send a line directlry to the cout object.
	
	friend std::size_t hash_value(const Line& l);   
};




#endif