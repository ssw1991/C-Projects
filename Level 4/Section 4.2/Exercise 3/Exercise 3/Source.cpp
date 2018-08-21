#include <vector>
#include <iostream>
#include <algorithm>

/*
a) Scale all values by a given factor.
	Transform - Mutating
b) Count the number of elements whose values are in a given range.
	Count_if - Non Modifying
c) Find the average, minimum and maximum values in a container.
	min, mas, minmax   for average - accumulate/size
d) Find the first element that is (that is not) in a range.
	find_if, find_if_not Non modifying
e) Search for all occurrences of ‘3456’ in the container.
	loop with search until last iterator is returns, if sorted, equal_range
	non-modifying
f) Determine if the elements in two ranges are equal.
	all_of - non-modifying
g) Determine if a set is some permutation of ‘12345’.
is permutation - non-modifying
h) Is a container already sorted?
is_sorted - Non modifying
i) Copy a container into another container.
copy - mutating
j) Move the last 10 elements of a container to the front.
rotate - move if 
k) Swap two ranges at a given position.
swap-ranges - modifying
l) Generate values in a container based on some formula.
generate - mutating
m) Replace all uneven numbers by zero.
replace_if - modifying
n) Remove all elements whose value is less than 100.
remove_if - modifying
o) Shuffle a container randomly (pre- and post-C++11 versions).
shuffle - modifying
p) Compute one-sided divided differences of the values in a container.
	adjacent difference - mutating
*/

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

using value_type = double;
using Vector = std::vector<value_type>;

void PrintVec(Vector& v)
{
	for (auto i : v) std::cout << i << " ";
	std::cout << std::endl;
}

bool InRange(double test, double v1, double v2)
{
	return (v1 <= test) & (v2 >= test);
}


double RandomNumber()
{
	return std::rand();
}

bool IsOdd(int i) 
{
	return ((i % 2) == 1); 
}

int myrandom(int i) 
{ 
	return std::rand() % i; 
}

int main()
{
	

	// scale all values

	Vector v = { 1.,2.,3.,4. };
	double val = 2.0;
	
	std::transform(v.begin(), v.end(),v.begin(), std::bind(std::multiplies<double>(), std::placeholders::_1, val));
	PrintVec(v);

	// Count the number of elements whose values are in a given range.
	
	std::count_if(v.begin(), v.end(), std::bind(InRange, std::placeholders::_1, 3.0, 6.0));
	PrintVec(v);
	//  Find the average, minimum and maximum values in a container.

	std::cout << "Min:  " << *std::min_element(v.begin(), v.end()) << std::endl;
	std::cout << *std::max_element(v.begin(), v.end()) << std::endl;
	std::cout << ( std::accumulate(v.begin(), v.end(), 0) / v.size() ) << std::endl;


	// Find the First Element is / not in range

	auto in = std::find_if(v.begin(), v.end(), std::bind(InRange, std::placeholders::_1, 3.0, 6.0));
	auto out = std::find_if_not(v.begin(), v.end(), std::bind(InRange, std::placeholders::_1, 3.0, 6.0));

	std::cout << "First Value in range: " << std::distance(v.begin(), in) << std::endl;
	std::cout << "First not in range: " << std::distance(v.begin(), out) << std::endl;

	// Search for all occurences of 3,4,5,6 in range
	Vector target = { 3.,4.,5.,6. };
	v = { 1,2,3,4,5,6,3,4,5,6 };

	auto it = v.begin();

	while (it != v.end())
	{
		it = std::search(it, v.end(), target.begin(), target.end());

		if (it != v.end())
		{
			std::cout << "Occurence at index: " << std::distance(v.begin(), it) << std::endl;
			it++;
		}
	}


	
	//  Determine if the elements in two ranges are equal.
	std::cout << std::boolalpha;
	std::cout << std::equal(v.begin(), v.end(), target.begin(), target.end()) << std::endl;
	
	// g) Determine if a set is some permutation of ‘12345’.

	target = { 1.,2.,3.,4.,5. };
	std::cout << std::is_permutation(v.begin(), v.end(), target.begin(), target.end()) << std::endl;

	// h) Is a container already sorted?

	std::cout << std::is_sorted(target.begin(), target.end())<< std::endl;
	
	// i) Copy a container into another container.

	Vector v1(v.size());

	std::copy(v.begin(), v.end(), v1.begin());
	PrintVec(v1);
	// j) Move the last 10 elements of a container to the front.

	v = { 1.,2.,3.,4.,5.,6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,17.,18.,19.,20 };

	auto n = v.size() - 10;  // will move the first n to end of range, n being size - 10
							 
	std::rotate(v.begin(), v.begin() + n, v.end());
	PrintVec(v);
	// k) Swap two ranges at a given position.

	
	std::swap_ranges(v.begin(), v.begin() + 1, target.begin());
	PrintVec(v); PrintVec(target);

	// l) Generate values in a container based on some formula.
	
	Vector myvector(8);
	std::generate(myvector.begin(), myvector.end(), RandomNumber);
	PrintVec(myvector);
	// m) Replace all uneven numbers by zero.
	
	std::replace_if(v.begin(), v.end(), IsOdd, 0);

	PrintVec(v);
	// n) Remove all elements whose value is less than 100.

	auto end = std::remove_if(v.begin(), v.end(), std::bind(std::less<double>(), std::placeholders::_1, 100.));
	v.erase(end, v.end());
	PrintVec(v);
	// o) Shuffle a container randomly (pre- and post-C++11 versions).

	
	std::random_shuffle(myvector.begin(), myvector.end(), myrandom);
	PrintVec(myvector);
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(myvector.begin(), myvector.end(), std::default_random_engine(seed));
	PrintVec(myvector);
	//p) Compute one-sided divided differences of the values in a container.
	
	Vector newvec(myvector.size());

	std::adjacent_difference(myvector.begin(), myvector.end(), newvec.begin());
	PrintVec(newvec);
}