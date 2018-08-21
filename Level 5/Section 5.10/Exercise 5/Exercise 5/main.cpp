#include <boost/numeric/ublas/vector.hpp>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <functional>


using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;
using value_type = double;
using Vector = boost::numeric::ublas::vector<value_type>;



template <typename T, template <typename S, typename Alloc >
class Container, typename TAlloc>
Result find_sequential_greater(const Container<T, TAlloc>& container, T x)
{
	// Generic search that finds the index to the first element in container > x
	auto f = std::bind(std::greater<value_type>(), std::placeholders::_1, x);  // bind x to greater_than
	auto i = std::find_if(container.begin(), container.end(), f);  // Find if val in container > x
	auto index = std::distance(container.begin(), i);      // Find the distance
	if (i != container.end())
	{
		return std::make_tuple(std::make_tuple(index - 1, index), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
}

int main()
{

	Vector v(8);
	std::vector<double> v1{ 1.,2.,3.,4.,5.,6.,7.,8. };

	for (int i = 0; i < v.size(); i++)
		v[i] = i;

	Result r1 = find_sequential_greater(v, 3.0);
	Result r2 = find_sequential_greater(v1, 3.0);


	std::cout << "Result 1, Boost: " << std::get<1>(std::get<0>(r1)) << std::endl;
	std::cout << "Result 2, STL: " << std::get<1>(std::get<0>(r2)) << std::endl;


	return 0;
}