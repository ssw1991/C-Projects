
#include "Stack.hpp"
#include "StackState.hpp"
#include <memory>
#include <vector>
#include "EmptyState.hpp"


void Stack::init(int size)
{
	if (size < 1)
	{
		data = std::vector<int>(1);
	}
	else
	{
		data = std::vector<int>(size);
	}

	current_index = 0;
	state = std::shared_ptr<StackState>(EmptyState::instance());
};

Stack::Stack()
{
	init(1);
};

Stack::Stack(int size)
{
	init(size);
};

void Stack::Push(int i)
{
	state->push(this, i);
};

int Stack::Pop()
{
	int val = state->pop(this);
	return val;
};



