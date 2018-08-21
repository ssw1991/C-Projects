#ifndef SHAPECOMPOSITE_HPP
#define SHAPECOMPOSITE_HPP

#include "Shape.hpp"
#include <list>
#include <memory>

class ShapeComposite: public Shape
{
private:
	std::list<std::shared_ptr<Shape>> m_data; // List of shape pointers

	ShapeComposite(ShapeComposite& source) {}; // Non-implemented Copy
	ShapeComposite operator =(ShapeComposite& source) {}; // Non-implemented =

public:

	using it = std::list<std::shared_ptr<Shape>>::iterator;
	using cit = std::list<std::shared_ptr<Shape>>::const_iterator;

	ShapeComposite(); // Default constructor
	virtual ~ShapeComposite() { std::cout << "GoodBye"; }


	// Modifiers
	
	void AddShape(std::shared_ptr<Shape> s);



	// Accessors
	it begin();
	it end();

	cit begin() const;
	cit end() const;

	int count() const;

	void Print() const override;
};

#endif