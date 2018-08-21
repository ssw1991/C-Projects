#include "Vector.cpp"
#include <array>
#include <iostream>
#include <functional>
#include <algorithm>
#include "Matrix.cpp"


int Square(int& val)
{
	return val * val;
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
	Vector<int, 2> v(std::array<int, 2> {1, 2});  // test parameterized
	Vector<int, 2> v2(v);								// Test Copy
	
	Matrix<int, 2, 2> M;
	
	M[0] = v;
	M[1] = v2;
	Matrix<int, 2, 2> M2(2);
	PrintMatrix(M);
	PrintMatrix(M2);

	PrintMatrix(M + M2);
	PrintMatrix(M - M2);
	PrintMatrix(2 * M);
	PrintMatrix(-M);

	PrintVec(M[0]);
	M.modify(Square);

	PrintMatrix(M);
	M2 = M;
	PrintMatrix(M2);
	std::cout << M2[1][1];
	
	
	return 0;

}