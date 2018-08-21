#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <complex>
#include <iostream>


using namespace boost::numeric::ublas;

int main() {
	
	mapped_matrix<std::complex<double>> m(3, 3, 1);     // 3*3 sparse matrix with 1 non-zero

	m(1, 1) = std::complex<double>(1, 2);   // add element

	std::cout << m << std::endl;

	m.erase_element(1, 1);
	std::cout << m << std::endl;  // erase element

	m.insert_element(0, 0, std::complex<double>(1, 2));
	std::cout << m << std::endl;

	m.clear();
	std::cout << m << std::endl;


	triangular_matrix<double, lower, column_major> low(3, 3);

	for (int i = 0; i < low.size1(); ++i)
	{
		for (int j = 0; j <= i; ++j)
			low(i, j) = 3 * i + j;  // Filling the matrix
	}

	std::cout << low << std::endl;


	triangular_matrix<double, upper> up(3, 3);  //default is row_major
	
	for (int i = 0; i < up.size1(); ++i)
	{
		for (int j = i; j < up.size2(); ++j)
			up(i, j) = 3 * i + j;  // Fillin the matrix
	}
	
	std::cout << up << std::endl;

	matrix<double> m1(3, 3);  // Matrix to adapt

	for (unsigned i = 0; i < m1.size1(); ++i)
	{
		for (unsigned j = 0; j < m1.size2(); ++j)
			m1(i, j) = 3 * i + j;  // Fill matrix
	}


	triangular_adaptor<matrix<double>, lower> tal(m1);   // Adapt to lower
	std::cout << tal << std::endl;

	triangular_adaptor<matrix<double>, upper> tau(m1); // adapt to higher
	std::cout << tau << std::endl;
	

}