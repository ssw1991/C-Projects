// Empty State


#include "Stack.hpp"
#include "Singleton.cpp"
#include "StackState.hpp"
#include "EmptyState.hpp"
#include "FullState.hpp"
#include "NotFullNotEmptyState.hpp"

void NotFullNotEmptyState::push(Stack* s, int i)
{
	StackState::push(s, i);
	ChangeState(s);
};

int NotFullNotEmptyState::pop(Stack* s)
{
	int i = StackState::pop(s);
	ChangeState(s);
	return (i);
};

void NotFullNotEmptyState::ChangeState(Stack* s)
{
	if (s->data.size() == s->current_index)
		s->state = std::shared_ptr<FullState>(FullState::instance());
	else if (s->current_index = 0)
		s->state = std::shared_ptr<EmptyState>(EmptyState::instance());
}



