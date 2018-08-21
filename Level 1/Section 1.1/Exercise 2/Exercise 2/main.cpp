/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: wilsons
*
* Created on May 1, 2018, 1:47 PM
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <numeric>
using namespace std;


// N.B. Generic lambda
auto MyMultiply = [](auto x, auto y) { return x * y; };

struct FOMultiply
{
	template <typename T>
	T operator () (const T& x, const T& y)
	{
		return x * y;
	}
};

template <typename T>
T MyMultiply2(const T& x, const T& y) { return x * y; };

int main()
{
	int initVal = 1;
	int initVal2 = 1;  // For implementing accumulate using for_each
	std::vector<int> vec = { 1,2,3,4,5 };

	int acc2 = std::accumulate(vec.begin(), vec.end(), initVal,
		std::multiplies<int>());

	int accA = std::accumulate(vec.begin(), vec.end(),
		initVal, FOMultiply());

	int acc3 = std::accumulate(vec.begin(), vec.end(), initVal, MyMultiply);
	std::cout << "Sum 3, Lambda: " << acc3 << std::endl;


	// Using complex numbers
	using Complex = std::complex<double>;
	std::vector<Complex> complexArray = { Complex(1.0, 1.0), Complex(2.0, 2.0) };
	Complex initCVal(1.0, 1.0);
	Complex initCVal2(1.0, 1.0); // For implementing accumulate using for_each

	auto acc4C = accumulate(complexArray.begin(),
		complexArray.end(), initCVal, FOMultiply());
	std::cout << "Sum 4, Complex: " << acc4C << std::endl;

	auto acc5C = accumulate(complexArray.begin(),
		complexArray.end(), initCVal, MyMultiply);             // This is an example using a stored lambda
	std::cout << "Sum 5, Complex: " << acc5C << std::endl;

	Complex acc6C = std::accumulate(complexArray.begin(),
		complexArray.end(), initCVal, MyMultiply2<Complex>);
	std::cout << "Sum 6, complex numbers: " << acc6C << std::endl;

	std::for_each(vec.begin(), vec.end(), [&](auto i) {initVal2 *= i; });
	std::for_each(complexArray.begin(), complexArray.end(), [&](auto i) {initCVal2 *= i; });
	std::cout << "Sum 7, using for_each: " << initVal2 << std::endl;
	std::cout << "Sum 8, complex numbers, using for_each: " << initCVal2 << std::endl;

	return 0;
}

