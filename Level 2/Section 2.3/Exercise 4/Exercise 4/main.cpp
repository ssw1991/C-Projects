#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

template <typename T>
std::function<T(const T&)> bind1st
(const std::function<T(const T& x, const T& y)>& f, const T& x_)
{
	return [=](const T& _y)
	{
		return f(x_, _y);
	};
};

template <typename T>
std::function<T(const T&)> bind2nd
(const std::function<T(const T& x, const T& y)>& f, const T& y_)
{
	return [=](const T& _x)
	{
		return f(_x, y_);
	};
}

double fxy(const double& x, const double& y)
{
	return (x + y);
}

int main()
{
	double yval = 10.0;

	ScalarFunction fx = bind2nd<double>(fxy, yval);
	std::cout << fx(3.0) << std::endl;

	// Test new bind code on STL algorithms
	std::vector<double> vec(10, 2.0);
	std::transform(vec.begin(), vec.end(), vec.begin(), fx);
	for (auto i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ",";
	}


	return 0;
}