#ifndef MATRIX_CPP
#define MATRIX_CPP

/*
Matrix Class that uses compile time vector as underlying data structure,
this will allow me to delegate much of the functionality to the vectors


*/

#include "Vector.cpp"
#include "Matrix.hpp"
#include <array>
#include <algorithm>
#include <functional>

template <typename T, int NR, int NC>
Matrix<T, NR, NC>::Matrix()
{// New default vector
	m_data = new Vector<Vector<T, NC>, NR>;
}

template <typename T, int NR, int NC>
Matrix<T, NR, NC>::Matrix(Vector<Vector<T, NC>, NR> a)
{ // Create a new vector then place te data

	m_data = new Vector<Vector<T, NC>, NR>;

	for (int i = 0; i < NR; i++)
	{
		(*m_data)[i] = a[i];
	}
}

template <typename T, int NR, int NC>
Matrix<T, NR, NC>::Matrix(const Matrix<T, NR, NC>& v)
{ // Copy Constructor
	m_data = new Vector<Vector<T, NC>, NR>;

	for (int i = 0; i < NR; i++)
	{
		(*m_data)[i] = v[i];
	}
}

template <typename T, int NR, int NC>
Matrix<T, NR, NC>::~Matrix()
{ // Destructor
	delete m_data;
}

template<typename T, int NR, int NC>
Matrix<T, NR, NC>::Matrix(T val)
{ // Constructor off of val
	m_data = new Vector<Vector<T, NC>, NR>;
	
	for (int i = 0; i < NR; i++)
	{
		(*m_data)[i] = Vector<T, NC>(val);
	}
}

template <typename T, int NR, int NC>
Matrix<T, NR, NC>& Matrix<T, NR, NC>::operator = (const Matrix& source)
{ // Assignment
	if (this == &source)
	{
		return *this;
	}

	delete m_data;

	m_data = new Vector<Vector<T, NC>, NR>;

	for (int i = 0; i < NR; i++)
	{
		(*m_data)[i] = source[i];
	}

	return *this;
}

template <typename T, int NR, int NC>
Vector<T, NC>& Matrix<T, NR, NC>::operator [] (int index)
{ // Indexing operator
	// returns vector
	return (*m_data)[index];
}

template <typename T, int NR, int NC>
const Vector<T, NC>& Matrix<T, NR, NC>::operator [] (int index) const
{ // Const index operator
	return (*m_data)[index];
}

// Operating Functions

template <typename T, int NR, int NC>
Matrix<T,NR,NC> Matrix<T, NR, NC>::operator + (const Matrix<T, NR, NC>& v1)
{ // Add each vector
	Matrix<T, NR, NC> output;
	for (int i = 0; i < NR; i++) output[i] = (*m_data)[i] + v1[i];
	return(output);
}


template <typename T, int NR, int NC>
Matrix<T, NR, NC> Matrix<T, NR, NC>::operator - (const Matrix<T, NR, NC>& v1)
{ // subtract each vector
	Matrix<T, NR, NC> output;
	for (int i = 0; i < NR; i++) output[i] = (*m_data)[i]  - v1[i];
	return(output);
};

template <typename T, int NR, int NC>
Matrix<T, NR, NC> Matrix<T, NR, NC>::operator - ()
{ // Negate each vector
	Matrix<T, NR, NC> output;
	for (int i = 0; i < NR; i++) output[i] = -(*m_data)[i];
	return(output);
};


template <typename T, int NR, int NC>
Matrix<T, NR, NC> Matrix<T, NR, NC>::operator * (const T mult) const
{  // RHS Multiply
	
	Matrix<T, NR, NC> output;
	
	for (int i = 0; i < NR; i++) output[i] = (*m_data)[i] * mult;

	return(output);
}

template <typename T, int NR, int NC, typename F>
Matrix<T, NR, NC> operator * (const F& mult, const Matrix<T, NR, NC>& v)
{ // Delegate LHS mult to RHS mult
	return (v * mult);
}

template <typename T, int NR, int NC>
void Matrix<T, NR, NC>::modify(const std::function<T(T&)>& f)
{ // Apply modification too each vector
	for (int i = 0; i < NR; i++)
		(*m_data)[i].modify(f);
}

#endif