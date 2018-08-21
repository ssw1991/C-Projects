#include <memory>
#include "Class.hpp"
#include "Point.hpp"


using DoublePtr = std::shared_ptr<double>;
using PointPtr = std::shared_ptr<Point>;


int main()
{
	double* d = new double(1.0);
	DoublePtr ptr(d);
	
	C1 c1(ptr);
	C2 c2(ptr);
	
	std::cout << ptr.use_count() << std::endl;  // currently 3, ptr, c1, and c2
	ptr.reset();
	
	std::cout << c1.use_count() << std::endl;

	std::cout << c2.use_count() << std::endl;

	Point* p = new Point(0.0, 0.0);
	Point* p1 = new Point(1.0, 0.0);
	
	PointPtr sp1(p);
	PointPtr sp2(p1);

	std::cout << "sp1 is currently: ";
	sp1->Print();

	std::cout << "sp2 is currently: ";
	sp2->Print();


	sp1.swap(sp2);

	std::cout << "sp1 is currently: ";
	sp1->Print();

	std::cout << "sp2 is currently: ";
	sp2->Print();

	sp2.reset();  //Destructor Called
	sp2.swap(sp1); // Tranferiing ownership
	sp2->Print();  //verify transfer
	std::cout << sp1.use_count() << std::endl;  //Verify sp1 is empty
	std::cout << "Is sp2 the only pointer to point?: " << sp2.unique() << std::endl; //Check unique.

	return 0;
}