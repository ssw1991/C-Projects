// Header file to Hold Distance Strategy

#ifndef DISTANCESTRATEGY_HPP
#define DISTANCESTRATEGY_HPP

#include "Point.hpp"
#include <functional>

class DistanceStrategy
{
private:
	
	std::function<double(const Point&, const Point&)> strat;

public:
	DistanceStrategy(std::function<double(const Point&, const Point&)> _strat) : strat(_strat) {};
	// Pass in strategy, this could be as a function or function object (which may hold state)


	
	double Distance(const Point& p1, const Point& p2)
	{
		return(strat(p1, p2));
	}
};


#endif