#include "stack.hpp"
#include <iostream>


int main()
{
	Stack<int> stack;

	for (int i = 0; i < 20; i++) stack.push(i);   // fill stack

	stack.Print();

	stack.max();
	stack.Print();   // end of stack should be ...17, 19

	stack.min();
	stack.Print(); // end of stack should be ...16, 17

	stack.over(); // stack should go ...16, 17, 1
	stack.Print();

	stack.rot();
	stack.Print();  // 14, 15, 17, 1, 16

	stack.swap();
	stack.Print(); // 14,15,17, 16, 1

	stack.drop();
	stack.Print(); // 14,15,16,17

	/*
	These were all modifying algorithms
	
	*/
}