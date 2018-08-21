
#include "Vector.hpp"
#include <array>
#include <algorithm>
#include <functional>

template<typename T, int N>
Vector<T, N>::Vector()
{
	std::cout << "Constuct " << std::endl;
	m_data = new std::array<T, N>;
}

template<typename T, int N>
Vector<T,N>::Vector(std::array<T,N> a)
{
	std::cout << "Constuct " << std::endl;
	m_data = new std::array<T, N>;

	for (int i = 0; i < N; i++)
	{
		(*m_data)[i] = a[i];
	}
}

template<typename T, int N>
Vector<T,N>::Vector(const Vector& v)
{
	std::cout << "Constuct " << std::endl;
	m_data = new std::array<T,N>;
	
	for (int i = 0; i < N; i++)
	{
		(*m_data)[i] = v[i];
	}
}

template<typename T, int N>
Vector<T,N>::~Vector()
{
	std::cout << "destruct " << std::endl;
	delete m_data;
}

template<typename T, int N>
Vector<T,N>& Vector<T, N>::operator = (const Vector& source)
{
	if (this == &source)
	{
		return *this;
	}

	delete m_data;

	m_data = new std::array<T,N>;
	

	for (int i = 0; i < N; i++)
	{
		(*m_data)[i] = source[i];
	}

	return *this;
}

template<typename T, int N>
T& Vector<T,N>::operator [] (int index)
{
	return (*m_data)[index];
}

template<typename T, int N>
const T& Vector<T,N>::operator [] (int index) const
{
	return (*m_data)[index];
}

// Operating Functions

template<typename T, int N>
Vector<T,N> Vector<T, N>::operator + (const Vector<T, N>& v1)
{
	std::array<T, N> output;
	std::transform(m_data->begin(), m_data->end(), v1.m_data->begin(), output.begin(), std::plus<T>());
	return(output);
}


template<typename T, int N>
Vector<T,N> Vector<T, N>::operator - (const Vector<T, N>& v1)
{
	std::array<T, N> output;
	std::transform(m_data->begin(), m_data->end(), v1.m_data->begin(), output.begin(), std::minus<T>());
	return(output);
};

template<typename T, int N>
Vector<T,N> Vector<T, N>::operator - ()
{
	std::array<T, N> output;
	std::transform(m_data->begin(), m_data->end(), output.begin(), std::negate<T>());
	return(output);
};


template<typename T, int N>
Vector<T,N> Vector<T,N>::operator * (const T mult)
{
	auto m = std::bind(std::multiplies<T>(),std::placeholders::_1,mult);
	std::array<T, N> output;
	std::transform(m_data->begin(), m_data->end(), output.begin(), m);

	return(Vector(output));
}

template <typename T, int N>
void Vector<T,N>::modify(const std::function<T(T&)>& f)
{
	for (auto& i : (*m_data))
		i = f(i);
}
