

#include "Stack.hpp"
#include "Singleton.cpp"
#include "StackState.hpp"
#include "myException.hpp"
#include "NotFullNotEmptyState.hpp"
#include "FullState.hpp"
#include "EmptyState.hpp"

void EmptyState::push(Stack* s, int i)
{
	StackState::push(s, i);
	ChangeState(s);
};

int EmptyState::pop(Stack* s)
{
	throw(myException("Stack is Empty"));
};

void EmptyState::ChangeState(Stack* s)
{
	if (s->data.size() > 1)
		s->state = std::shared_ptr<NotFullNotEmptyState>(NotFullNotEmptyState::instance());
	else
		s->state = std::shared_ptr<FullState>(FullState::instance());
};

	

