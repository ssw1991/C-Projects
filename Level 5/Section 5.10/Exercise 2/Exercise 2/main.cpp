#include <algorithm>
#include <functional>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <iostream>


namespace ublas = boost::numeric::ublas;

template<typename VecType>
void Print(VecType& v)
{
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

template<typename MatrixType>
void PrintMatrix(MatrixType& m)
{
	for (int i = 0; i < m.size1(); i++)
	{ // Iterate through first index and second 
		//to print each element
		for (int j = 0; j < m.size2(); j++)
			std::cout << m(i, j) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{

	ublas::matrix<double> m1(5, 5); 
	ublas::matrix<double, ublas::column_major> m2(5, 5);

	
	for (int i = 0; i < m1.size1(); i++)
	{ // Iterate through first index and second 
	  //assign each element
		for (int j = 0; j < m1.size2(); j++)
		{
			m1(i, j) = j - i;
			m2(i, j) = j + i;
		}
	}
	PrintMatrix(m1); PrintMatrix(m2);

	ublas::matrix<double> m3 = m1 + m2;
	PrintMatrix(m3);
	
	ublas::matrix<double> m4 = ublas::identity_matrix<double>(5);

	ublas::matrix<double> m5 = m3 - m4;
	ublas::matrix<double> m6 = ublas::zero_matrix<double>(5, 5);

	PrintMatrix(m4); PrintMatrix(m5); PrintMatrix(m6);

	m3.resize(3, 3);

	PrintMatrix(m3);







}