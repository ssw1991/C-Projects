#include <iostream>
#include <list>
#include "Line.hpp"
#include "Point.hpp"
#include <boost/functional/hash.hpp>



int main()
{
	Point p1(1.0, 2.0);
	Point p2(1.5, 32.4);
	Point p3(1.8, 9.2);

	std::list<Point> ls{ p1,p2,p3 };

	Line l(p1, p2);

	std::size_t range = boost::hash_range(ls.begin(), ls.end());

	std::cout << "Hash Range: " << range << std::endl;

	std::cout << "p1 Hash: " << hash_value(p1) << std::endl;
	std::cout << "p2 Hash: " << hash_value(p2) << std::endl;
	std::cout << "p3 Hash: " << hash_value(p3) << std::endl;
	std::cout << "Line Hash: " << hash_value(l) << std::endl;

}


