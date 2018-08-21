#include "Vector.cpp"
#include <array>
#include <iostream>
#include <functional>
#include <algorithm>
#include "Matrix.cpp"
#include "Proposition.hpp"


using value_type = Proposition;
template <int NR, int NC>
using BitMap = Matrix<value_type, NR, NC>;
template <int NR, int NC>
using BitMap2 = std::array<std::bitset<NC>, NR>;
using BitFunction =
std::function < Proposition(const Proposition&,
	const Proposition&) >;

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

template <int NR, int NC>
BitMap<NR, NC> mask(const BitMap<NR, NC>& bm1,
	const BitMap<NR, NC>& bm2,
	const BitFunction& masker)
{
	BitMap<NR, NC> output;

	for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < NC; j++)
			output[i][j] = masker(bm1[i][j], bm2[i][j]);
	} // I feel like there must be a better way.   However 
	// The modificiation function takes a function that only takes one argument
	// And I couldnt figure out how to iterativly bind each value
	return output;
};

int main()
{
	Proposition t(1);
	Proposition f(0);
	std::array<Proposition, 8> a1;
	Vector<Proposition, 8> a(1);
	BitMap<8,8> bm1(t);
	BitMap<8, 8> bm2(t);
	
	bm1[4][3] = f;

	BitMap2<8,8> bitblt2;

	bitblt2[0] = std::bitset<8>("01111100");

	auto IMPL = []
	(const Proposition& p1, const Proposition& p2)
	{ return p1 % p2; };

	auto XOR = []
	(const Proposition& p1, const Proposition& p2)
	{ return p1 ^ p2; };
	
	auto OR = []
	(const Proposition& p1, const Proposition& p2)
	{ return p1 | p2; };

	auto AND = []
	(const Proposition& p1, const Proposition& p2)
	{ return p1 & p2; };

	auto EQUAL = []
	(const Proposition& p1, const Proposition& p2)
	{ return p1 == p2; };

	auto NEQUAL = []
	(const Proposition& p1, const Proposition& p2)
	{ return p1 != p2; };

	PrintMatrix(mask(bm1, bm2, IMPL));
	PrintMatrix(mask(bm1, bm2, XOR));
	PrintMatrix(mask(bm1, bm2, OR));
	PrintMatrix(mask(bm1, bm2, AND));
	PrintMatrix(mask(bm1, bm2, EQUAL));
	PrintMatrix(mask(bm1, bm2, NEQUAL)); 


	/*
	In this case, both seem about the same to use.   It is easier to 
	initialise BitSet1 if all the bits are the same, as it provides a 
	constructor.  Printing is the same, and the free masking function would
	probably be easier with transform.  This can be overcome by building in 
	functions to return iterators.   Also an additional friend modify function
	to implement the masks.
	
	
	*/
}