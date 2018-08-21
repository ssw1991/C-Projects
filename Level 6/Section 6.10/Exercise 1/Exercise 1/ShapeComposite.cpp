#include "ShapeComposite.hpp"
#include "Shape.hpp"
#include <iostream>
#include <memory>
#include "ShapeVisitor.hpp"

using namespace std;

using it = std::list<shared_ptr<Shape>>::iterator;
using cit = std::list<shared_ptr<Shape>>::const_iterator;

ShapeComposite::ShapeComposite(): m_data(list<shared_ptr<Shape>>()) // Default constructor
{
};
// Modifiers

ShapeComposite::ShapeComposite(const ShapeComposite& source)
{ // Copy the source composite to this shape composite

  // Create STL list iterator
	list<shared_ptr<Shape>>::const_iterator it;

	for (it = source.cbegin(); it != source.cend(); it++)
	{ // Copy the whole list

	  // Add a copy of the shape to our list
		m_data.push_back((*it)->Clone());
	}
}

ShapeComposite& ShapeComposite::operator = (const ShapeComposite& source)
{ // Assignment operator

  // Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Shape::operator = (source);

	// Copy state
	list<shared_ptr<Shape>>::const_iterator it;

	for (it = source.cbegin(); it != source.cend(); it++)
	{ // Copy the whole list

	  // Add a copy of the shape to our list
		m_data.push_back((*it)->Clone());
	}

	return *this;
}


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

cit ShapeComposite::cbegin() const
{
	return m_data.cbegin();
};

cit ShapeComposite::cend() const
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

shared_ptr<Shape> ShapeComposite::Clone() const
{// Create a copy of the shape
	return shared_ptr<Shape>(new ShapeComposite(*this));
}


void ShapeComposite::Accept(std::shared_ptr<ShapeVisitor> v)
{
	for (auto i : m_data)
		i->Accept(v);
};

void ShapeComposite::Translate(double x, double y)
{
	for (auto i : m_data)
		i->Translate(x,y);
}