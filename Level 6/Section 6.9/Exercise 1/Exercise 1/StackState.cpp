//StackState



#include "Stack.hpp"
#include "StackState.hpp"


void StackState::push(Stack* s, int i)
{
	s->data[s->current_index] = i;
	s->current_index += 1;
};

int StackState::pop(Stack* s)
{
	int val = s->data.back();
	s->data.pop_back();
	s->current_index -= 1;
	return(val);
};




