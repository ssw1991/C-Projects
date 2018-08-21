// Header file to Hold Distance Strategy

#ifndef APPROXIMATEDISTANCE_HPP
#define APPROXIMATEDISTANCE_HPP
class ApproximateDistance; // Forward Declaration
#include "Point.hpp"
#include "DistanceStrategy.hpp"
#include <cmath>

class ApproximateDistance: public DistanceStrategy
{
public:
	virtual double Distance(const Point& p1, const Point& p2) override
	{
		return std::abs(p1.X() - p2.X()) + std::abs(p1.Y() - p2.Y());
	};
};


#endif