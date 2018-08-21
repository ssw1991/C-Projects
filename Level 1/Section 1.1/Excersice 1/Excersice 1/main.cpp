
/*
* File:   main.cpp
* Author: wilsons
*
* Created on April 30, 2018, 1:12 PM
*
a) Create a lambda function that multiplies each element of an array by a
number. This number is a captured variable; test the function for the cases
when it is copy-by-value and a reference. The original
array is modified after having called the function.

b) Print the values of the modified array using auto to initialise the iterator
variable instead of declaring it explicitly.

c) Write a lambda function to compute both the minimum and maximum of the
elements in an array. The return type is an std::pair (or if you prefer,
std::tuple with two elements) containing the computed minimum and maximum
values in the array.

d) Compare the approach taken in part c) by calling std::minmax_element. For
example, do you get the same output? How easy is to understand and reuse the
code?
*/

#include <iostream>  // std::cout
#include <array>     // std::array 
#include <algorithm> // std::for_each, std::min_element, std::max_element, 
//  std::minmax_elemnt
#include <utility>   // std::pair


using namespace std;

int main()
{
	array<double, 15> a1;            // Hold first array
	array<double, 15> a2;            // Hold second array
	double multiplier = 6;           // Hard Coded multiplier
	pair<double, double> min_max;     // Pair from Lambda (part c)


									  // Fill Array's 
	for (int i = 0; i < 15; i++)
	{
		a1[i] = i;
		a2[i] = i;
	}

	// Capture value by copy (array by reference to ensure it is changed)
	for_each(a1.begin(), a1.end(), [=](double& i) {i *= multiplier; });

	// Capture value by reference
	for_each(a2.begin(), a2.end(), [&](double& i) {i *= multiplier; });

	// Inspect output (same for both)
	for_each(a1.begin(), a1.end(), [](double i) {cout << i << endl; });
	for_each(a2.begin(), a2.end(), [](double i) {cout << i << endl; });

	// Part C
	min_max = [](array<double, 15> &a1)
	{  // Part C
		return make_pair(*min_element(a1.begin(), a1.end()),
			*max_element(a1.begin(), a1.end()));
	}(a1);

	// Inspect output
	cout << "Max: " << min_max.second << " Min: " << min_max.first << endl;

	// Part D
	auto min_max2 = minmax_element(a1.begin(), a1.end());

	// Inspect Output
	cout << "Max: " << *min_max2.second << " Min: " << *min_max2.first << endl;

	return 0;
}

