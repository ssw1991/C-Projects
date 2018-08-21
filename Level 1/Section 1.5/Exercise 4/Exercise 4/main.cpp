#include <iostream>
#include <iterator>
#include <vector>
#include <functional>
#include <algorithm>


template<typename T>
bool predicate(T val, T& i)
{	
	std::cout << val << " " << i << std::endl;
	return (i > val);
		
}


template<typename T>
int VectorBetween(std::vector<T>& v, T val)
{// Function to find the index in which vector[i] < val and vector[i+1] > val
// Because the vector is sorted, we only need the first element greater than some val, and find the index to the previous
	auto pred = std::bind(predicate<T>, val, std::placeholders::_1);
	auto it = std::find_if(v.begin(), v.end(), pred);
	int index = std::distance(v.begin(), it);
	return index - 1;
}


template<typename T>
T difference(T a, T b)
{
	return std::abs(a - b);
}
template<typename T, typename F>
int MaxDist(std::vector<T>& v1, std::vector<T>& v2, F f)
{//Assumes both vectors are of the same size
	// Any distance function can be used
	std::vector<T> diff;
	for (int i = 0; i < v1.size(); ++i)
	{
		diff.push_back(f(v1[i], v2[i]));
	}
	
	auto max = std::max_element(diff.begin(), diff.end());
	return std::distance(diff.begin(), max);
}

int main()
{
	std::vector<double> v{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
	std::vector<double> v2{2.0,4.5,4.5,4.7,5.0,6.0,7.0,8.0,9.0 };
	int a = VectorBetween<double>(v, 5.0);
	
	auto f = difference<double>;

	int b = MaxDist(v, v2, f);

	std::cout << "Part A: " << a << std::endl << "Part B: " << b;
	return 0;
}