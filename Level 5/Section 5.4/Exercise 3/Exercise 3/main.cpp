#include <iostream>
#include <boost/container/set.hpp>
#include <boost/unordered_set.hpp>
#include "Point.hpp"
#include "stopwatch.hpp"
#include <unordered_set>


struct CustomHasher 
{ // Struct to pass a hasher 

	std::size_t operator () (double const& d) const 
	{// Function to hash double

		std::size_t seed;
		std::memcpy(&seed, &d, sizeof(double));  // copy bits to memory location of seed
		return seed & 0xffffff000;  // Mask last three bits

		// At high resolutions, two doubles that evaluate equal may have different bits, 
		// So I masked the least 3,  not certain if this is the right approach

	}

	std::size_t operator () (Point const& p) const
	{
		return (CustomHasher()(p.X()) ^ (CustomHasher()(p.Y()) << 1));
	}
};

int main()
{
	
	boost::unordered_multiset<Point> set;  // Defaults to using the hash_value currently defined for Point
	StopWatch timer;

	timer.StartStopWatch();
	for (int i = 0; i < 1000; i++)
	{
		set.insert(Point(i, i));
		set.emplace(.5*i, .5*i);
	}  // now contains P(0.0,0.0) - P(999, 999) and half all odd num (1,5 , 2.5, = 497.5)

	for (int i = 0; i < 1000; i++)
	{
		set.erase(Point(i, i));
		
	}  // now contains half all odd num (1,5 , 2.5, = 497.5)

	set.clear();

	timer.StopStopWatch();
	std::cout << "Time with custom hasher using std: " << timer.GetTime() << std::endl;
	timer.Reset();

	boost::unordered_multiset<Point, CustomHasher> set1;  // Defaults to using the hash_value currently defined for Point

	timer.StartStopWatch();
	for (int i = 0; i < 1000; i++)
	{
		set.insert(Point(i, i));
		set.emplace(.5*i, .5*i);
	}  // now contains P(0.0,0.0) - P(999, 999) and half all odd num (1,5 , 2.5, = 497.5)

	for (int i = 0; i < 1000; i++)
	{
		set.erase(Point(i, i));

	}  // now contains half all odd num (1,5 , 2.5, = 497.5)

	set.clear();

	timer.StopStopWatch();
	std::cout << "Time with custome hasher: " << timer.GetTime() << std::endl;
	timer.Reset();

	std::unordered_set<Point>;

	timer.StartStopWatch();
	for (int i = 0; i < 1000; i++)
	{
		set.insert(Point(i, i));
		set.emplace(.5*i, .5*i);
	}  // now contains P(0.0,0.0) - P(999, 999) and half all odd num (1,5 , 2.5, = 497.5)

	for (int i = 0; i < 1000; i++)
	{
		set.erase(Point(i, i));

	}  // now contains half all odd num (1,5 , 2.5, = 497.5)

	set.clear();
	timer.StopStopWatch();
	std::cout << "Time with stl multiset: " << timer.GetTime() << std::endl;


}