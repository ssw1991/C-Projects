// Long Observer

#ifndef DOUBLEOBSERVER_HPP
#define DOUBLEOBSERVER_HPP

#include "Observer.hpp"
#include "Subject.hpp"
#include <memory>
#include <iostream>
#include <iomanip>

class DoubleFormat : public Observer
{
private:
	std::shared_ptr<Subject> m_obj;
public:

	DoubleFormat(std::shared_ptr<Subject> s) : m_obj(s)
	{ // Initialize Member and attach
		s->Attach(std::shared_ptr<Observer>(this));
	}

	void Update(Subject* s) override
	{
		std::cout << std::fixed;
		std::cout <<std::setprecision(2) << "From Double: " << static_cast<double>(m_obj->GetCounter()) << std::endl;
	}
};
#endif