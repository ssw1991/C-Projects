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
	virtual ~Vector();

	// Member operator overloading
	Vector& operator = (const Vector<T,N>& source);
	T& operator [] (int index);
	const T& operator [] (int index) const;

	// Operating Functions

	Vector operator + (const Vector<T, N>& v1);
	Vector operator - (const Vector<T, N>& v1);
	Vector operator - ();

	Vector operator * (const T mult);

	void modify(const std::function< T(T&)>& f);

	template <typename T, int N, typename F> 
	Vector<T,N> friend operator * (const F& mult, const Vector<T,N>& v)
	{ // Not sure why linker error occurs here
		auto m = std::bind(std::multiplies<F>(), std::placeholders::_1, mult);
		std::array<T, N> output;
		std::transform(v.m_data->begin(), v.m_data->end(), output.begin(), m);
		return(Vector(output));
	}

	

};

#endif