#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

struct X
{
	double val;

	X() : val(0.0) {}
	void operator ()() {
		std::cout << "An X " << val << std::endl;
	}
};

template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

void Modify(PointerType& p, double newVal)
{
	std::this_thread::sleep_for(std::chrono::duration<int>(1));
	p->val = p->val + newVal;  
	// This is so I can see the race,  if I just change 
	//to newVal, all the output would be the same
	std::stringstream ss;
	ss << "New Val: " << p->val << "\n";  // So the threads dont mix between << 
	std::cout << ss.str();	
}


int main()
{
	PointerType x1(new X);
	std::vector<std::thread> v;
	
	for (int i = 0; i < 100; i++)
		v.push_back(std::thread(std::bind(Modify, x1, 1.0)));   // Could not figure out how to do this with an array
	for (auto& i : v)  //C++ 11 Range based loop
		i.join();

}

/*
What is happening is that a single thread say thread 1 is reading pval, say 4, but before 
t1 can assign a new val of 5, another thread may have and assigned it 4, sp t1 reassigns it for
but had the operations occured sequentially, it should have been 5.  Additionally while it writes p->val
in one step, it needs to read it later to output it to the console.  As a consequece, while it may have written 5 
to the object, it may put 16 on the console.  (hence the lack of any number less than 4 to come out any time 
I run it)

*/