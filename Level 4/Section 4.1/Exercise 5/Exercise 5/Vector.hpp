#ifndef Vector_HPP
#define Vector_HPP

#include <array>
#include <algorithm>
#include <functional>

template<typename T, int N>

class Vector
{
private:
	std::array<T,N>* m_data; // Size of the array

public:
	// Constructors
	Vector();
	Vector(std::array<T,N> a);
	Vector(const Vector& v);
	Vector(T val);
	virtual ~Vector();

	// Member operator overloading
	Vector& operator = (const Vector<T,N>& source);
	T& operator [] (int index);
	const T& operator [] (int index) const;

	// Operating Functions

	Vector operator + (const Vector<T, N>& v1);
	Vector operator - (const Vector<T, N>& v1);
	Vector operator - ();

	Vector operator * (const T mult) const;

	void modify(const std::function< T(T&)>& f);

	template <typename T, int N, typename F> 
	Vector<T, N> friend operator * (const F& mult, const Vector<T, N>& v);

	auto begin() const { return (*m_data).begin(); }  // Adding iterator support
	auto end() const { return (*m_data).end(); }

};

#endif