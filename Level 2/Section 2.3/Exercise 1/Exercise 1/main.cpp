#include "Classes.hpp"
#include <iostream>


[[deprecated]]
New _origin;  // Depracated Global Variable


[[deprecated]]
void Print(New& point)
{
	point.draw();
}



int main()
{
	// Old origin2; 
	New origin;

	// origin.Draw();
	origin.draw();
	// _origin.Draw();
	 // Print(origin);

	square<double> sq1;
	// square<int> sq2;

	enum [[deprecated]] COLORS { red, yellow, green, blue };
	enum class [[deprecated]] direction { LEFT, RIGHT };
	
	// int c = red;
	// direction d = direction::LEFT;

	
	// [[deprecated]] auto glambda =  [](auto a, auto b) { std::cout << a + b << std::endl; };

	// glambda(1, 2);

	return 0;
}

/*
Would not compile with depracated code.  Commented all code using depracated feautures
*/