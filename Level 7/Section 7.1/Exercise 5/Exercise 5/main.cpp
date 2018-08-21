#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "ConsoleFactor.hpp"
#include <memory>
#include <string>
#include "PolyLine.hpp"
#include <vector>
#include <functional>
#include <cmath>


struct ExactDistance
{
	double total; // holds the total lenght of distance called

	ExactDistance() : total(0.0) {};

	double operator() (const Point& p1, const Point& p2)
	{
		double temp = std::sqrt(std::pow((p1.X() - p2.X()), 2) + std::pow((p1.Y() - p2.Y()), 2));
		total += temp;  // Keeps tab of total calls
		return temp;
	}

	double Total() { return total };

};

using MyFunction = std::function<double(const Point&, const Point&) > ;

int main()
{
	MyFunction Taximan = [](const Point& p1, const Point& p2) {return std::abs(p1.X() - p2.X()) + std::abs(p1.Y() - p2.Y()); };
	
	std::shared_ptr<DistanceStrategy> strat (new DistanceStrategy(Taximan));

	Point p1(5.6, 2.1);
	Point p2;  // Default point

	std::cout << p1.Distance(p2, strat) << std::endl;

	

	MyFunction Exact = ExactDistance();

	std::shared_ptr<DistanceStrategy> strat_exact(new DistanceStrategy(Exact));

	std::cout << p1.Distance(p2, strat_exact) << std::endl;

	// std::cout << Exact.Total();   How to access state from here?

}