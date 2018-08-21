//StackState

#ifndef STACKSTATE_HPP
#define STACKSTATE_HPP

#include "Stack.hpp"
class Stack;

class StackState
{

public:
	virtual void push(Stack* s, int i);
	virtual int pop(Stack* s);
	virtual void ChangeState(Stack* s) = 0;

};


#endif