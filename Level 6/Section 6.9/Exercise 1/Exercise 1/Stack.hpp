// Models a Stack

#ifndef STACK
#define STACK

#include "StackState.hpp"
#include <memory>
#include <vector>

class StackState;
class EmptyStackState;
class FullState;
class NotFullNotEmptyState;

class Stack
{
private:

	std::vector<int> data;
	int current_index;
	std::shared_ptr<StackState> state;

	void init(int size);

	friend class StackState;
	friend class EmptyState;
	friend class FullState;
	friend class NotFullNotEmptyState;

public:
	Stack();
	Stack(int size);

	void Push(int i);
	int Pop();
};


#endif