#ifndef FUNCTIONOBJECTS_H
#define FUNCTIONOBJECTS_H
#include <string>

class FunctionObject
{
public:
	static void Iprint(const std::string& s, int count)
	{ // Static Function to print s, count # of times to terminal

		for (int i = 0; i <= count; i++)
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
	}
	void operator () (const std::string& s, int count)
	{ // Callable Object to print s, count # of times to terminal

		for (int i = 0; i <= count; i++)
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
	}
};

class FunctionObject2
{
public:
	void Iprint(const std::string& s, int count)
	{ // Function to print s, count # of times to terminal

		for (int i = 0; i <= count; i++)
			std::cout << std::this_thread::get_id() << ": " << s << std::endl;
	}
};



#endif

