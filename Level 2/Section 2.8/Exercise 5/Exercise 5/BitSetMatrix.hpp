#ifndef BITSETMATRIX_H
#define BITSETMATRIX_H
#include <iostream>
#include <array>
#include <bitset>

template<size_t N, size_t M>
class BitSetMatrix
{
private:
	std::array<std::bitset<M>, N> m_data; 

public:
	BitSetMatrix()
	{
		std::array<std::bitset<M>, N> a;
		for (int i = 0; i < N; i++)
			a[i] = std::bitset<M>();
		m_data = a;
	};

	BitSetMatrix(const std::array<std::bitset<M>, N>& data): m_data(data)
	{
	};

	BitSetMatrix(const BitSetMatrix& data): m_data(data.m_data)
	{
	};

	~BitSetMatrix()
	{};

	void set();
	void flip();
	bool none();
	bool all();
	bool any();
	std::bitset<M>& operator [] (int i);
	int count();

	BitSetMatrix<N, M> operator ^ (const BitSetMatrix<N,M>& data);
	BitSetMatrix<N, M> operator | (const BitSetMatrix<N, M>& data);
	BitSetMatrix<N, M> operator & (const BitSetMatrix<N, M>& data);
	BitSetMatrix<N, M> operator = (const BitSetMatrix<N, M>& source);
};

#endif
