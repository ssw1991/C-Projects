#include <iostream>
#include "Point.hpp"
#include "DistanceStrategy.hpp"
#include "ExactDistance.hpp"
#include "ApproximateDistance.hpp"
#include <memory>




int main()
{
	Point::SetStrat(std::shared_ptr<DistanceStrategy>(new ExactDistance()));
	Point p1(1.0, 2.0);
	Point p2(4.0, 5.0);

	std::cout << "Exact Dist: " << p1.Distance(p2) << std::endl;
	std::cout << "From Origin: " << p1.Distance() << std::endl;

	Point::SetStrat(std::shared_ptr<DistanceStrategy>(new ApproximateDistance()));

	std::cout << "Exact Dist: " << p1.Distance(p2) << std::endl;
	std::cout << "From Origin: " << p1.Distance() << std::endl;

}