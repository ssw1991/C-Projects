// Empty State


#ifndef EMPTYSTATE_HPP
#define EMPTYSTATE_HPP

#include "Stack.hpp"
#include "Singleton.cpp"
#include "StackState.hpp"

class EmptyState: public Singleton<EmptyState>, public StackState
{

private:
	EmptyState() : Singleton<EmptyState>() {};
	friend class Singleton<EmptyState>;
public:

	virtual void push(Stack* s, int i) override;
	virtual int pop(Stack* s) override;

	virtual void ChangeState(Stack* s) override;

	virtual ~EmptyState() {};
};

#endif