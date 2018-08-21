#ifndef STACK_HPP
#define STACK_HPP

/*
Header file for a first in last out container with specific functionality

*/

#include <vector>


template <typename T>
class Stack
{
private:
	std::vector<T> stack;

public:

	Stack() : stack(std::vector<T>())   // Default by creating a stack with 0 elements 
	{};

	Stack(std::vector<T> v) : stack(v)  // create stack out of vector
	{};

	// Modifying Functions

	void push(T t)
	{ // 
		stack.push_back(t);
	};


	T top()
	{
		return *(stack.end() - 1);  //stack.end()-1 is iterator to last element, by construction the top
	};

	void max()
	{  // compares the top 2 elements and deletes the min

		if (*(stack.end() - 2) > *(stack.end() - 1))
		{
			stack.erase(stack.end() - 1);
		}

		else
		{
			stack.erase(stack.end() - 2);
		}
	};

	void min()
	{ // Compares top  elements and removes the max

		if (*(stack.end() - 2) < *(stack.end() - 1))
		{
			stack.erase(stack.end() - 1);
		}

		else
		{
			stack.erase(stack.end() - 2);
		}
	}

	void over()
	{ // Duplicates the second value on top (assuming this is second value inserted
		stack.push_back(stack[1]);
	};

	void rot()
	{ // Rotates the stacks third data val to top
		std::rotate(stack.rbegin(), stack.rbegin() + 2, stack.rbegin()+3);
	};

	void swap()
	{ // interchange the top 2 elements
		std::rotate(stack.rbegin(), stack.rbegin() + 1, stack.rbegin()+2);
	};

	void drop()
	{ // discard the top
		stack.erase(stack.end() - 1);
	};

	void Print()
	{
		for (auto i : stack)
			std::cout << i << " ";
		std::cout << std::endl;
	}
};

#endif