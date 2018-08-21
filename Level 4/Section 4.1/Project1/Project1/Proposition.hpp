#ifndef PROPOSITION_H
#define PROPOSITION_H

#include <bitset>
#include <sstream>


class Proposition
{
private:
	std::bitset<1> data;

public:
	// Constructors 

	Proposition(int val);
	Proposition(std::bitset<1> bit);
	Proposition(bool b);
	Proposition(const Proposition& p);

	// Assignment Overload
	Proposition operator = (const Proposition& p);

	// Boolean Operators 
	bool operator == (const Proposition& p);
	bool operator != (const Proposition& p);

	// Logical Operators returning Prop
	Proposition operator & (const Proposition& p);
	Proposition operator | (const Proposition& p);
	Proposition operator ^ (const Proposition& p);
	Proposition operator ! () const;

	// So I can easily cout
	friend std::ostream& operator << (std::ostream& os, const Proposition& p);

	// Implication Overloads

	friend Proposition operator % (const Proposition& p1, const Proposition& p2);
	friend Proposition operator %= (const Proposition& p1, const Proposition& p2);
};



#endif