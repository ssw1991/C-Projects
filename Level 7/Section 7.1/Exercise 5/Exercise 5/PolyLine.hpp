// PolyLine.hpp
//
// Header file for Lines Segment


#ifndef POLYLine_HPP
#define POLYLine_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <string>
using namespace std;

template< template<class, class> class Container, typename TPoint, typename Alloc = std::allocator<TPoint>>
class PolyLine : public Shape
{
private:
	Container<TPoint, Alloc> m_points;

public:
	// Constructors and destructor
	PolyLine() : m_points() {}; // Default constructor  - Default Container

	PolyLine(const PolyLine& line) : m_points(line.m_points) {}; // Copy constructor
	
	virtual ~PolyLine() {}; // Destructor

	// Member operator overloading
	PolyLine& operator = (const PolyLine& source) // Assignment operator
	{
		// Exit if same object
		if (this == &source)
		{
			return *this;
		}

		// Call base class assignment
		Shape::operator = (source);

		// Copy state
		m_points = source.m_points;
	}
							
	

	// Global operator overloading
	friend ostream& operator << (ostream& os, const PolyLine& l) // Send to ostream
	{
		for (auto i: l.m_points)
		{
			os << i << " ";
		}
		os << std::endl;
		return os;
	}

	double Length(std::shared_ptr<DistanceStrategy> strat) const
	{
		double dist = 0;
		for (int i = 1; i < m_points.size(); i++)
		{
			dist += m_points[i].Distance(m_points[i-1], strat);
		}

		return dist;
	}

	std::shared_ptr<Shape> Clone() const override // Returns shared_ptr to clone
	{
		return std::shared_ptr<Shape>(new PolyLine(*this));
	}

	void add(TPoint p)
	{
		m_points.push_back(p);
	}

};

#endif