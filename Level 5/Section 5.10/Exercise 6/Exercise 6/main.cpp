#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
using namespace boost::numeric::ublas;

int main()
{


	matrix<double> m(3, 3);

	for (int i = 0; i < m.size1(); i++)
		for (int j = 0; j < m.size2(); j++)
			m(i, j) = 3 * i + j;

	auto row = matrix_row<matrix<double>>(m, 0);
	std::cout << row << std::endl;

	auto column = matrix_column< matrix<double> >(m,2);
	std::cout << column << std::endl;

	auto mr = matrix_range< matrix<double> >(m, range(0, 2), range(0, 2));
	std::cout << mr << std::endl;

	matrix_slice< matrix<double> > ms(m, slice(0, 1, 2), slice(0, 1, 2));
	matrix_slice< matrix<double> > ms2(m, slice(0, 1, 3), slice(0, 1, 3));  // same as m
	
	std::cout << ms << std::endl;
	std::cout << ms2 << std::endl;

}