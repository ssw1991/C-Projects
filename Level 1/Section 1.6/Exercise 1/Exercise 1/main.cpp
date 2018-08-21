#include <iostream>
#include <memory>

struct Base
{
	virtual void draw() = 0;  // Declarint Function as pure virtual 

	void print() {}

	~Base()
	{
		std::cout << "bye base\n";
	}
};

struct Derived final : public Base
{
	Derived() {}

	void draw() override
	{
		std::cout << "print a derived\n";
	}

	void draw() const {}   // Removed override as base does not have virtual function with same signature

	void print() {}        // Removed override because print not declared virtual

	~Derived()
	{
		std::cout << "bye derived\n";
	}
};

class Derived2 : public Base
{ // Cannot inherit from Derived as Derived is declared final

};



int main()
{
	std::shared_ptr<Derived> ptr(new Derived());

	ptr->draw();

	return 0;

}