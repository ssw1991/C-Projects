// Header file to Hold Distance Strategy

#ifndef EXACTDISTANCE_HPP
#define EXACTDISTANCE_HPP

#include "Point.hpp"
#include "DistanceStrategy.hpp"
#include <cmath> 

class ExactDistance : public DistanceStrategy
{
public:
	double Distance(const Point& p1, const Point& p2) override
	{
		return std::sqrt(std::pow((p1.X() - p2.X()), 2) + std::pow((p1.Y() - p2.Y()), 2));
	};
};


#endif