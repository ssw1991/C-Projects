#include <boost/random/generate_canonical.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <boost/random/triangle_distribution.hpp>
#include <random>
#include <iostream>



int main()
{
	boost::lagged_fibonacci1279 eng1;

	boost::triangle_distribution<double> dist(0.0, 1.0, 2.0);

	std::cout << "From Triangle dist: " << dist(eng1) << std::endl;

	std::cout << "Canoncial with 2 bits: " << boost::random::generate_canonical<double, 2>(eng1) << std::endl;
	std::cout << "Canoncial with 8 bits: " << boost::random::generate_canonical<double, 8>(eng1) << std::endl;
	std::cout << "Canoncial with 16 bits: " << boost::random::generate_canonical<double, 16>(eng1) << std::endl;
	std::cout << "Canoncial with 32 bits: " << boost::random::generate_canonical<double, 32>(eng1) << std::endl;
	
}