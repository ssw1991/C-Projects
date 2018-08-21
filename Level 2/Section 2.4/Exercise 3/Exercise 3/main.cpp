#include <memory>
#include <iostream>


int main()
{
	using std::unique_ptr;
	// Define auto_ptr pointers instead of raw pointers
	std::unique_ptr <double> d(new double(1.0));

	// Dereference
	*d = 2.0;

	// Change ownership of auto_ptr
	// (after assignment, d is undefined)
	unique_ptr <double> d2;
	// d2 = d;    The = operator is a a deleted function (using VS 2017)  this isnt in documentation though
	d2.swap(d);
	*d2 = 3.0;


	std::cout << "Unique values: " << d.get() << ", " << *d2.get();  

	// The original runtime error is because d a null pointer.
}