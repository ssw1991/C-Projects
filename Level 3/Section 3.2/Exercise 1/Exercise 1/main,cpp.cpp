#include <iostream>
#include <memory>
#include <atomic>


struct X
{
	double val;

	X() : val(0.0) {}
	void operator ()() {
		std::cout << "An X " << val << std::endl;
	}
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

int main()
{
	PointerType x1(new X);
	x1->val = 1.0;
	
	std::cout << "x1 use_count: " << x1.use_count() << std::endl;

	PointerType x2(new X);
	std::atomic_store(&x2, x1);   // Atomically store x1 in x2
	std::cout << "x1 use_count: " << x1.use_count() << " x2 use_count: " << x2.use_count() << std::endl;

	PointerType x3(new X);
	x3->val = 15.0;
	std::cout << "x1 use_count: " << x1.use_count() << " x2 use_count: " << x2.use_count() << 
		" x3 use_count: " << x3.use_count() << std::endl;
	std::atomic_exchange(&x3, x1);   // x3 is now 1.0 
	std::atomic_exchange(&x3, x2);   // Both are still 1

	std::cout << "x1 use_count: " << x1.use_count() << "x2 use_count: " << x2.use_count() <<
		" x3 use_count: " << x3.use_count() << std::endl;
	
	std::cout << "x1, x2, x3 vals: " << x1->val << ", " << x2->val << ", " << x3->val << std::endl;
	std::cout << std::boolalpha << "Are shared pointers lock free: " << std::atomic_is_lock_free(&x1);
	
	/*
	Why is std::atomic<std::shared_ptr> not possible?

	It is not defined as a template specialization of the atomic class.  According to the 
	documentation on std::atomic, shared_ptr is the only type in the standard library which is 
	not a specialization of atomic, but still able to guarantee atomicity.

	I think the reason this is, is because even if the shared_ptr was atomic, there is no guarantee 
	that its underlying object is.   If multiple shared pointers pointed to the same object, even if operations on the 
	pointer were atomic, operations on the object wouldnt be.  
	
	
	*/
}