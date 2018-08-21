#ifndef BITSETMATRIX_CPP
#define BITSETMATRIX_CPP
#include <iostream>
#include <array>
#include <bitset>
#include "BitSetMatrix.hpp"

template<size_t N, size_t M>
void BitSetMatrix<N,M>::set()
{
	for (int i = 0; i < N; i++)
		m_data[i].set();
};

template<size_t N, size_t M>
void BitSetMatrix<N, M>::flip()
{//flip all bits
	for (int i = 0; i < N; i++)
		m_data[i].flip();
};

template<size_t N, size_t M>
bool BitSetMatrix<N, M>::none()
{ // Test if all bits set to 0
	bool ret = 0;
	for (int i = 0; i < N; i++)
		ret =| m_data[i].none();
};

template<size_t N, size_t M>
bool BitSetMatrix<N, M>::all()
{ // test if all bits set to 1
	for (int i = 0; i < N; i++)
	{	
		if (!m_data[i].all())
			return 0;
	}
	return 1;
};

template<size_t N, size_t M>
bool BitSetMatrix<N, M>::any()
{ // check if any bits
	for (int i = 0; i < N; i++)
	{
		if (m_data[i].any())
			return 1;
	}
	return 0;
};

template<size_t N, size_t M>
std::bitset<M>& BitSetMatrix<N, M>::operator [] (int i)
{ // return [i] bitset, allows to use [][] to access element
	//returned by reference to change elements
	return m_data[i];
};

template<size_t N, size_t M>
int BitSetMatrix<N, M>::count()
{ // get total count
	int val = 0;
	for (int i = 0; i < N; i++)
	{
		val += m_data[i].count();
	}
	return val;
};

template<size_t N, size_t M>
BitSetMatrix<N, M> BitSetMatrix<N, M>::operator ^ (const BitSetMatrix<N, M>& data)
{ //Apply XOR to each bitset
	BitSetMatrix<N, M> ret;
	for (int i = 0; i < N; i++)
	{
		ret[i] = ( m_data[i] ^ data.m_data[i]);
	}
	return ret;
};

template<size_t N, size_t M>
BitSetMatrix<N, M> BitSetMatrix<N, M>::operator | (const BitSetMatrix<N, M>& data)
{ // Apply OR to each bitset
	BitSetMatrix<N, M> ret;
	for (int i = 0; i < N; i++)
	{
		ret[i] = (m_data[i] | data.m_data[i]);
	}
	return ret;
};

template<size_t N, size_t M>
BitSetMatrix<N, M> BitSetMatrix<N, M>::operator & (const BitSetMatrix<N, M>& data)
{ // Apply & to each bitset
	BitSetMatrix<N, M> ret;
	for (int i = 0; i < N; i++)
	{
		ret[i] = (m_data[i] & data.m_data[i]);
	}
	return ret;
}

template<size_t N, size_t M>
BitSetMatrix<N, M> BitSetMatrix<N, M>::operator = (const BitSetMatrix<N, M>& source)
{ // Assignment Operator
	if (this == &source)
	{
		return *this;
	}

	m_data = source.m_data;
	return *this;

};

#endif