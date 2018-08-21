// Full State


#include "Stack.hpp"
#include "Singleton.cpp"
#include "StackState.hpp"
#include "EmptyState.hpp"
#include "NotFullNotEmptyState.hpp"
#include "myException.hpp"
#include "FullState.hpp"



void FullState::push(Stack* s, int i) 
{
	throw(myException("Stack is full"));
};

int FullState::pop(Stack* s)
{
	int i = StackState::pop(s);
	ChangeState(s);
	return i;
};

void FullState::ChangeState(Stack* s)
{
	if(s->data.size() > 1)
		s->state = std::shared_ptr<NotFullNotEmptyState>(NotFullNotEmptyState::instance());
	else 
		s->state = std::shared_ptr<EmptyState>(EmptyState::instance());
};


