#include <iostream>
#include "Point.hpp"
#include "DistanceStrategy.hpp"
#include "ExactDistance.hpp"
#include "ApproximateDistance.hpp"
#include <memory>




int main()
{
	Point p1(1.0, 2.0);
	Point p2(4.0, 5.0);

	std::cout << "Exact Dist: " << p1.Distance(p2, std::shared_ptr<DistanceStrategy>(new ExactDistance())) << std::endl;
	std::cout << "From Origin: " << p1.Distance(std::shared_ptr<DistanceStrategy>(new ExactDistance())) << std::endl;


	std::cout << "Exact Dist: " << p1.Distance(p2, std::shared_ptr<DistanceStrategy>(new ApproximateDistance())) << std::endl;
	std::cout << "From Origin: " << p1.Distance(std::shared_ptr<DistanceStrategy>(new ApproximateDistance())) << std::endl;

	// I like this method better,   we may want to compute different distances with different points
	// For example, Line Lenght, we may want exact.  But in some cases may want taximan
}