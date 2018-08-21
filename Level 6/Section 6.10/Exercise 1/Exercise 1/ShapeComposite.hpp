#ifndef SHAPECOMPOSITE_HPP
#define SHAPECOMPOSITE_HPP
// Models a collection of shapes or shape composites
// Derives from shapes

class ShapeComposite; // Forward Declaration

#include "Shape.hpp"
#include <list>
#include <memory>
#include "ShapeVisitor.hpp"

class ShapeComposite: public Shape
{
private:
	std::list<std::shared_ptr<Shape>> m_data; // List of shape pointers

	

public:

	using it = std::list<std::shared_ptr<Shape>>::iterator;
	using cit = std::list<std::shared_ptr<Shape>>::const_iterator;

	ShapeComposite(); // Default constructor
	ShapeComposite(const ShapeComposite& source);
	ShapeComposite& operator =(const ShapeComposite& source);
	
	virtual ~ShapeComposite() { std::cout << "GoodBye"; }


	// Modifiers
	
	void AddShape(std::shared_ptr<Shape> s);



	// Accessors
	it begin();
	it end();

	cit cbegin() const;
	cit cend() const;

	int count() const;

	void Print() const override;
	std::shared_ptr<Shape> Clone() const override;
	void Accept(std::shared_ptr<ShapeVisitor> v) override;
	void Translate(double x, double y) override;
	
};

#endif