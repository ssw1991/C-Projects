#include "Proposition.hpp"
#include <bitset>
#include <sstream>



Proposition::Proposition(int val)
{
	data = std::bitset<1>(val);
}

Proposition::Proposition(std::bitset<1> bit): data(bit)
{
}

Proposition::Proposition(bool b)
{
	data = std::bitset<1>(b);
}

Proposition::Proposition(const Proposition& p): data(p.data)
{}

Proposition Proposition::operator = (const Proposition& p)
{
	if (this == &p) return *this;

	data = p.data;
	return *this;
}

bool Proposition::operator == (const Proposition& p)
{ // Return true if both are true or both are false
	return data == p.data;
}

bool Proposition::operator != (const Proposition& p)
{ // Return true if one is true and other is false
	return data != p.data;
}

Proposition Proposition::operator & (const Proposition& p)
{ // True Prop if both are true
	return Proposition((data & p.data)[0]);
}

Proposition Proposition::operator | (const Proposition& p)
{ // Return True Prop if at least one is true
	return Proposition((data | p.data)[0]);
}

Proposition Proposition::operator ^ (const Proposition& p)
{ // Return True Prop if only one is true
	return Proposition((data ^ p.data)[0]);
}

Proposition Proposition::operator ! () const
{ // Return negated prop 
	return Proposition(!data[0]);
}

std::ostream& operator << (std::ostream& os, const Proposition& p) 
{ // Allows to print 
	bool b = p.data[0];
	os << b;
	return os;
}

Proposition operator % (const Proposition& p1, const Proposition& p2)
{ // If A is true returns B, else returns True
	return (!p1 | p2);
}

Proposition operator %= (const Proposition& p1, const Proposition& p2)
{ // Returns true if A implies B and B implies A
	return  (p1%p2)&(p2%p1);
};