// Long Observer

#ifndef LONGOBSERVER_HPP
#define LONGOBSERVER_HPP

#include "Observer.hpp"
#include "Subject.hpp"
#include <memory>
#include <iostream>

class LongFormat : public Observer
{
private:
	std::shared_ptr<Subject> m_obj;
public:

	LongFormat(std::shared_ptr<Subject> s) : m_obj(s)
	{ // Initialize Member and attach
		s->Attach(std::shared_ptr<Observer>(this));
	}

	void Update(Subject* s) override
	{
		std::cout << "From Long: " << m_obj->GetCounter() << std::endl;
	}
};
#endif