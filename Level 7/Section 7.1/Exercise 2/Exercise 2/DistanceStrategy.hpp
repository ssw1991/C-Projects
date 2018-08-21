// Header file to Hold Distance Strategy

#ifndef DISTANCESTRATEGY_HPP
#define DISTANCESTRATEGY_HPP

#include "Point.hpp"

class DistanceStrategy
{
public:
	virtual double Distance(const Point& p1, const Point& p2) = 0;
};


#endif