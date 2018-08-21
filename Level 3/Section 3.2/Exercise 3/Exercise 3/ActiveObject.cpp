#ifndef ACTIVEOBJECT_HPP
#define ACTIVEOBJECT_HPP


/*
This class will be a class that manages an associated thread
*/

#include <iostream>
#include <thread>
#include <system_error>
class ActiveObject
{
private:
	std::thread& t;
public:

	explicit ActiveObject(std::thread& t_): t(t_)
	{ // t is a reference now assigned to t_
		std::cout << "constructed" << std::endl;
		if (!t.joinable()) // throw error if no associated function
			throw std::system_error(std::make_error_code(std::errc::invalid_argument), "Thread must have associated function");
	};

	~ActiveObject()
	{
		if (t.joinable())
			t.join();
		std::cout << "Destroyed" << std::endl;
	}

};

#endif