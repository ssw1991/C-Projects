#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>


using namespace boost::numeric::ublas;

int main()
{
	vector<double> v(5);

	for (unsigned i = 0; i < v.size(); ++i)
		v(i) = i;  // create and fill vector

	vector<double> v2(v);  // Copy vector

	// Inner and outer product

	auto out = outer_prod(v, v2);
	std::cout << "Outer Product: " << out << std::endl;

	auto in = inner_prod(v, v2);
	std::cout << "Inner Product: " << in << std::endl;

	vector<double> v3 = v + v2; // adding vector
	std::cout << "Adding Vectors: " << v3 << std::endl;

	v3 = v - v2; // subtracting
	std::cout << "Adding Vectors: " << v3 << std::endl;

	// Norms

	std::cout << "Euclidean Norm: " << norm_2(v) << std::endl;
	std::cout << "L1 Norm: " << norm_1(v) << std::endl;
	std::cout << "Max Norm: " << norm_inf(v) << std::endl;


	matrix<double> m(5,5);

	for (unsigned i = 0; i < m.size1(); ++i)
		for (unsigned j = 0; j < m.size2(); ++j)
			m(i, j) = 3 * i + j;  // Create and fill matrix

	// Matrix Norms

	std::cout << "L1 Norm: " << norm_1(m) << std::endl;
	std::cout << "Max Norm: " << norm_inf(m) << std::endl;

	// Product

	std::cout << "Matrix (5*5) * Vector(5): " << prod(m, v) << std::endl;

}