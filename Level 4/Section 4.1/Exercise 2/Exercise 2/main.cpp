#include "Vector.cpp"
#include <array>
#include <iostream>
#include <functional>
#include <algorithm>


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
int main()
{
	Vector<int, 4> v(std::array<int, 4> {1, 2, 3, 4});  // test parameterized
	Vector<int, 4> v2(v);								// Test Copy
	Vector<int, 4> def;                                 // Test default
	Vector<int, 4> v3 = v + v2; // test addition amd = overload
	Vector<int, 4> v4 = v3 - v; // test sub
	Vector<int, 4> v5 = -v;     // test negation
	Vector<int, 4> v6 = 6*v;   // Test pre mult
	

	for (int i = 0; i < 4; i++)
	{
		def[i] = i; // Test []
	}
	PrintVec(def);
	PrintVec(v3);
	PrintVec(v4);
	PrintVec(v5);
	PrintVec(v6);

	v2 = v; 
	v.modify(Square);
	
	PrintVec(v);
	
	return 0;

}