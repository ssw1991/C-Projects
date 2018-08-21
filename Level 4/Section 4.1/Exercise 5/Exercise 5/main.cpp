#include <algorithm>
#include "Vector.cpp"
#include <iostream>
#include <array>
#include <functional>
#include <numeric>
#include "Matrix.cpp"
#include <complex>

template <typename T, int N>
T inner_product(const Vector<T, N>& v1,
	const Vector<T, N>& v2,
	T initValue)
{
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue);
}


template <typename T>
using BinaryFunction =
std::function < T(const T& t1, const T& t2)>;

template <typename T, int N>
T inner_product(const Vector<T, N>& v1,
	const Vector<T, N>& v2,
	T initValue,
	const BinaryFunction<T>& op1,
	const BinaryFunction<T>& op2)
{
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue, op1, op2);
}
template <typename T, int NR, int NC>
Matrix<T, NR, NC> outer_product(const Vector<T, NR>& v1, const Vector<T, NC>& v2)
{
	Matrix<T, NR, NC> output;

	for (int i = 0; i < NR; i++)
	{
		output[i] = v2*v1[i];
	}
	return output;
}

template <typename T, int NR, int NC>
Matrix<std::complex<T>, NR, NC> outer_product(const Vector<std::complex<T>, NR>& v1, const Vector<std::complex<T>, NC>& v2)
{
	Matrix<std::complex<T>, NR, NC> output;
	
	Vector<std::complex<T>, NC> conj(v2);
	
	for (std::complex<T>& n : conj) n = std::conj(n);
	
	 // conj.modify(std::conj); // compute conjugate some errors in the template
	PrintVec(conj);
	for (int i = 0; i < NR; i++)
	{
		output[i] = conj * v1[i];
	}
	return output;
}

template<typename T, int N>
void PrintVec(const Vector<T, N>& v)
{
	for (int i = 0; i < N - 1; i++) std::cout << v[i] << ", ";  //Not printing last element with comma
	std::cout << v[N - 1] << std::endl;  // Last Element and Endl;
}

template<typename T, int NR, int NC>
void PrintMatrix(const Matrix<T, NR, NC>& m)
{
	for (int i = 0; i < NR; i++) PrintVec(m[i]);
}

int main()
{
	std::array<int, 4> a = { 1,2,3,4 };

	Vector<int, 4> v1(a);
	Vector<int, 4> v2(a);

	BinaryFunction<int> ADD = [](int a, int b)->int {return a + b; };
	BinaryFunction<int> MULT = [](int a, int b)->int {return a * b; };
	std::cout << "Inner Product: " << inner_product(v1, v2, 0) << std::endl;
	std::cout << "Inner Product  2: " << inner_product(v1, v2, 0, MULT, ADD) << std::endl;
	
	PrintMatrix<int, 4, 4>(outer_product(v1, v2));

	Vector<std::complex<int>, 2> v3(std::complex<int>(1, 1));
	Vector<std::complex<int>, 2> v4(std::complex<int>(1, 1));

	PrintMatrix<std::complex<int>, 2, 2>(outer_product(v3, v4));
}

