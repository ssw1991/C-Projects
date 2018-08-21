#ifndef Matrix_HPP
#define MATRIX_HPP

#include <array>
#include <algorithm>
#include <functional>
#include "Vector.cpp"

template<typename T, int NR, int NC>

class Matrix
{
private:
	Vector<Vector<T,NC>, NR>* m_data; // Matrix

public:
	// Constructors
	Matrix();
	Matrix(Vector<Vector<T, NC>, NR> a);
	Matrix(const Matrix& v);
	Matrix(T val);
	virtual ~Matrix();

	// Member operator overloading
	Matrix& operator = (const Matrix<T, NR, NC>& source);
	Vector<T, NC>& operator [] (int index);
	const Vector<T, NC>& operator [] (int index) const;

	// Operating Functions

	Matrix operator + (const Matrix<T, NR, NC>& v1);
	Matrix operator - (const Matrix<T, NR, NC>& v1);
	Matrix operator - ();

	Matrix operator * (const T mult) const;

	void modify(const std::function< T(T&)>& f);

	template <typename T, int NR, int NC, typename F>
	Matrix<T, NR, NC> friend operator * (const F& mult, const Matrix<T, NR, NC>& v);
};

#endif
