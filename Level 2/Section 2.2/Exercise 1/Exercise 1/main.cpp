#include <type_traits>
#include <iostream>
#include <vector>
#include <array>
#include <complex>


template <typename T>
T Addition(const T& t1, const T& t2)
{
	return Addition_impl(t1, t2, std::is_compound<T>());
}

template <typename T>
T Addition_impl(const T& t1, const T& t2, std::true_type)
{ // With any user defined storage, this requires the ability to index T

	T result;
	for (int i = 0; i < t1.size(); i++)
	{
		result[i] = t1[i] + t2[i];
		// Will not work for Vector
	}
	return result;
}

template <typename T>
T Addition_impl(const std::vector<T>& t1, const std::vector<T>& t2, std::true_type)
{ // Specialization for Vector because its interface is different from arrays

	std::vector<T> result;
	for (int i = 0; i < t1.size(); i++)
	{
		result.push_back(t1[i] + t2[i]);
	}
	return result;
}
/*
template <typename T>
std::complex<T> Addition_impl(const std::complex<T>& t1, const std::complex<T>& t2, std::true_type)
{ // Specialization for Vector because its interface is different from arrays
	return t1 + t2;
}
*/

template <typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type)
{
	return t1 + t2;
}


template <typename T>
T Additive_inv(const T& t1)
{
	return Additive_inv_impl(t1, std::is_compound<T>());
}

template <typename T>
T Additive_inv_impl(const T& t1, std::true_type)
{ // With any user defined storage, this requires the ability to index T

	T result;
	for (int i = 0; i < t1.size(); i++)
	{
		result[i] = -t1[i];
		// Will not work for Vector
	}
	return result;
}

template <typename T>
T Additive_inv_impl(const std::vector<T>& t1, std::true_type)
{ // Specialization for Vector because its interface is different from arrays

	std::vector<T> result;
	for (int i = 0; i < t1.size(); i++)
	{
		result.push_back -t[i];
	}
	return result;
}

template <typename T>
T Additive_inv_impl(const T& t1, std::false_type)
{
	return -t1;
}

template <typename T, typename S>
T ScalarMult(const T& t1, const S& val)
{
	return ScalarMult_impl(t1, val, std::is_compound<T>());
}

template <typename T, typename S>
T ScalarMult_impl(const T& t1, const S& val, std::true_type)
{ // With any user defined storage, this requires the ability to index T

	T result;
	for (int i = 0; i < t1.size(); i++)
	{
		result[i] = val * t1[i];
		// Will not work for Vector
	}
	return result;
}

template <typename T, typename S>
T ScalarMult_impl(const std::vector<T>& t1, const S& val, std::true_type)
{ // Specialization for Vector because its interface is different from arrays

	std::vector<T> result;
	for (int i = 0; i < t1.size(); i++)
	{
		result.push_back(t[i] * val);
	}
	return result;
}

template <typename T, typename S>
T ScalarMult_impl(const T& t1, const S& val,  std::false_type)
{
	return (t1 * val);
}



int main()
{
	using Comp = std::complex<double>;

	std::array<double,4> a1 { 1.0,2.0,3.0,4.0 };
	std::array<double,4> a2 { 1.0,2.0,3.0,4.0 };
	std::array<double, 4> a3 = Addition(a1, a2);
	auto a4 = Additive_inv(a1);
	auto a5 = ScalarMult(a1, 2);

	std::array<double, 4> v1{ 1.0,2.0,3.0,4.0 };
	std::array<double, 4> v2{ 1.0,2.0,3.0,4.0 };
	std::array<double, 4> v3 = Addition(v1, v2);
	auto v4 = Additive_inv(v1);
	auto v5 = ScalarMult(v1, 2);

	
	std::array<Comp, 4> c1{ Comp(1.0,1.0),Comp(1.0,1.0),Comp(1.0,1.0),Comp(1.0,1.0) };
	std::array<Comp, 4> c2{ Comp(2.0,1.0),Comp(2.0,1.0),Comp(2.0,1.0),Comp(2.0,1.0) };
	std::array<Comp, 4> c3 = Addition(c1, c2);
	std::array<Comp, 4> c4 = Additive_inv(c1);
	std::array<Comp, 4> c5 = ScalarMult(c1, 4.0);
	
	
	
	std::cout << "a3\ta4\ta5\tv3\tv4\tv5\tc3\tc4\tc5\n";
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << a3[i] << "\t" << a4[i] << "\t" << a5[i] << "\t"
			<< v3[i] << "\t" << v4[i] << "\t" << v5[i] << "\t"
			<< c3[i] << "\t" << c4[i] << "\t" << c5[i] << "\t" << std::endl;
	}
	



	return 0;
}