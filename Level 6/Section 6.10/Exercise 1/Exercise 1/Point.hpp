// Point.hpp
//
// Header file for Point(x,y)

#ifndef Point_HPP
#define Point_HPP
// Forward reference for point - Because of including origin point
class Point;

#include "Shape.hpp"
#include <iostream>
#include "OriginPoint.hpp"
#include "DistanceStrategy.hpp"
//#include "ShapeVisitor.hpp"
class ShapeVisitor;

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
	virtual ~Point(); // Destructor

	// Member operator overloading
	Point& operator = (const Point& source); // Assignment operator

	// Accessing functions
	double X() const; // The x-coordinate
	void X(double newX);

	double Y() const; // The y-coordinate
	void Y(double newY);

	
	// Global operator overloading
	friend std::ostream& operator << (std::ostream& os, const Point& p); // Send to ostream

	std::string ToString() const;

	double Distance(const Point& p, std::shared_ptr<DistanceStrategy> strat) const;
	double Distance(std::shared_ptr<DistanceStrategy> strat) const;
	std::shared_ptr<Shape> Clone() const override;

	void Accept(std::shared_ptr<ShapeVisitor> v) override;
	void Translate(double x, double y) override;
};

#endif