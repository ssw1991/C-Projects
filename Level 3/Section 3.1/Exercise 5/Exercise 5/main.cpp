#include <iostream>
#include <atomic>



int main()
{
	std::atomic_llong ll = 19999999;  // Initiliazing Atomic Values
	std::atomic_bool b = 0;
	std::atomic_int i = 1;
	std::atomic_int i2 = 2;

	std::cout << std::boolalpha;  
	std::cout << "Is atomic long long lock free: " << ll.is_lock_free() << std::endl;  // Determining Which are lock_free
	std::cout << "Is atomic bool lock free: " << b.is_lock_free() << std::endl;        // These three all are
	std::cout << "Is atomic int lock free: " << i.is_lock_free() << std::endl;

	i.exchange(i2); // exchange atomic values      

	std::cout << i << std::endl;   // Demonstrate exchange actually occured

	int x;         
	x = i.load();  // Load atomic value into variable
	std::cout << x << std::endl; // Verify

}