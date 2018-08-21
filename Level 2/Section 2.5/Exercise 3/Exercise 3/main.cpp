#include <boost/math/special_functions/next.hpp>
#include <iostream>
#include <cmath>


int main()
{
	// Number gaps/bits/ULP between
	// 2 floating-point values a and b
	// Returns a signed value indicating whether a < b
	double a = 0.1; double b = a + std::numeric_limits<double>::min();
	std::cout << boost::math::float_distance(a, b) << std::endl;
	a = 1.0; b = 0.0;
	std::cout << boost::math::float_distance(a, b) << std::endl;

	std::cout << boost::math::float_next(a) << std::endl;
	std::cout << boost::math::float_prior(a) << std::endl;

	std::cout << std::nextafter(a, 0.0) << std::endl;
	return 0;
}