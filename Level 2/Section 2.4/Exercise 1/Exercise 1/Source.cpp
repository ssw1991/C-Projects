#include "Point.hpp"
#include <iostream>
#include <boost/move/unique_ptr.hpp>
#include <memory>

using DoublePtr = std::unique_ptr<double>;
using PointPtr = std::unique_ptr<Point>;


int main()
{  // Block with raw pointer lifecycle
	try
	{
		DoublePtr d (new double (1.0));

		Point* pt = new Point(1.0, 2.0);// Two-d Point class
		PointPtr pt1(pt);
		PointPtr pt2(pt);
		pt1.release();    // When it wasnt released, it attempted to free already free memory and made the computer freeze
								   // Dereference and call member functions
		*d = 2.0;
		(*pt).X(3.0);// Modify x coordinate
		(*pt).Y(3.0);// Modify y coordinate

					 // Can use operators for pointer operations
		pt->X(3.0);// Modify x coordinate
		pt->Y(3.0);// Modify y coordinate
		throw (1);
		// Explicitly clean up memory (if you have not forgotten)
	
	}

	catch (int e)
	{
		std::cout << "Exception" << std::endl;  // Memory Leak introduced
	}
}