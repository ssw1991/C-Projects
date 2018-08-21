struct B 
{ 
	explicit B(int) {} 
	explicit B(int, int) {}  
	explicit operator int() const 
	{ 
		return 0; 
	} 
};



int main()
{

	// B b1 = 1;  wont compile because there is no default constructor, would need to define a default constructor
	B b1(1);       // a 
	B b2(3);       // b
	B b3{ 7,3 };   // c 
	B b4 = (B)42;  // d 

	return 0;
}