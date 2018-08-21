#include "ShapeComposite.hpp"
#include "Shape.hpp"
#include <iostream>
#include <memory>

using namespace std;

using it = std::list<shared_ptr<Shape>>::iterator;
using cit = std::list<shared_ptr<Shape>>::const_iterator;

ShapeComposite::ShapeComposite(): m_data(list<shared_ptr<Shape>>()) // Default constructor
{
};
// Modifiers

void ShapeComposite::AddShape(shared_ptr<Shape> s)
{
	m_data.push_back(s);
};

// Accessors


it ShapeComposite::begin()
{
	return m_data.begin();
};

it ShapeComposite::end()
{
	return m_data.end();
};

cit ShapeComposite::begin() const
{
	return m_data.cbegin();
};

cit ShapeComposite::end() const
{
	return m_data.cend();
};

int ShapeComposite::count() const
{
	return m_data.size();
}

void ShapeComposite::Print() const  
{
	for (auto i : m_data)
		i->Print();
};