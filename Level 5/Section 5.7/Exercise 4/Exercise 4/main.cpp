#include <boost/bimap.hpp>
#include <boost/unordered_set.hpp>
#include <string>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/set_of.hpp>
#include <utility>
#include <iostream>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>

using namespace boost::bimaps;

using ONE_TO_MANY = boost::bimap< set_of<std::string>, list_of<int> >;

using MANY_TO_ONE = boost::bimap< multiset_of<std::string>, set_of<int> >;
using p1 = MANY_TO_ONE::value_type;

using ONE_TO_ONE = boost::bimap< unordered_set_of<std::string>, unordered_set_of<int> >;
using p2 = ONE_TO_ONE::value_type;


template<typename Map>
void Print(const Map& map)
{
	for (auto i = map.begin(); i != map.end(); i++)
	{
		std::cout << i->first << ", " << i->second << std::endl;
	}
}


int main()
{

	ONE_TO_MANY bm1;

	bm1.left["alpha"] = 1; bm1.left["bravo"] = 2; bm1.left["charlie"] = 3;
	bm1.left["alpha"] = 3; // overrides alpha = 1

	MANY_TO_ONE bm2;

	bm2.insert(p1("alpha", 1));
	bm2.insert(p1("bravo", 1));  // Not inserted because 1 is in
	bm2.insert(p1("charlie", 3));

	ONE_TO_ONE bm3;

	bm3.insert(p1("alpha", 1));
	bm3.insert(p1("bravo", 2));
	bm3.insert(p1("charlie", 3));

	std::cout << "One to many\n";
	Print(bm1.left);

	std::cout << "Many to One\n";
	Print(bm2.left);

	std::cout << "One to One\n";
	Print(bm3.left);




	return 0;
}