// Empty State


#ifndef NOTFULLNOTEMPTYSTATE_HPP
#define NOTFULLNOTEMPTYSTATE_HPP

//#include "Stack.hpp"
#include "Singleton.cpp"
//#include "StackState.hpp"
//#include "EmptyState.hpp"
//#include "FullState.hpp"

class EmptyState;
class FullState;
class Stack;

class NotFullNotEmptyState : public Singleton<NotFullNotEmptyState>, public StackState
{
private:
	NotFullNotEmptyState(): Singleton<NotFullNotEmptyState>() {};
	friend class Singleton<NotFullNotEmptyState>;
public:

	virtual void push(Stack* s, int i) override;
	virtual int pop(Stack* s) override;

	virtual void ChangeState(Stack* s) override;

	virtual ~NotFullNotEmptyState() {};
};

#endif