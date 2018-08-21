// Full State


#ifndef FULLSTATE_HPP
#define FULLSTATE_HPP

#include "Stack.hpp"
#include "Singleton.cpp"
#include "StackState.hpp"
//#include "EmptyState.hpp"
//#include "NotFullNotEmptyState.hpp"

class EmptyState;
class NotFullNotEmptyState;
class Stack;

class FullState : public Singleton<FullState>, public StackState
{
private:
	FullState() : Singleton<FullState>() {};
	friend class Singleton<FullState>;
public:

	virtual void push(Stack* s, int i) override;
	virtual int pop(Stack* s) override;

	virtual void ChangeState(Stack* s) override;

	virtual ~FullState() {};
};

#endif