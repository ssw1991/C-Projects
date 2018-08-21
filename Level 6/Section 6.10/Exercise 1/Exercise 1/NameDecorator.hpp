// File to decorate Shape with name

#ifndef NAMEDECORATOR_HPP
#define NAMEDECORATOR_hpp

#include "Shape.hpp"
#include <memory>
#include "ShapeDecorator.hpp"
#include <string>
#include <sstream>

class NameDecorator : public ShapeDecorator
{
private:
	std::string name;
public:
	NameDecorator() :ShapeDecorator(std::shared_ptr<Shape>()), name("")
	{};

	NameDecorator(std::shared_ptr<Shape> ptr, std::string nme): ShapeDecorator(ptr), name(nme)
	{};

	NameDecorator(const NameDecorator& source):ShapeDecorator(source.GetShape())
	{
		name = source.name;
	}

	virtual ~NameDecorator() {};

	std::string GetName() const
	{
		return name;
	}

	void SetName(std::string nme)
	{
		name = nme;
	}

	std::shared_ptr<Shape> Clone() const override
	{
		return std::shared_ptr<Shape>(new NameDecorator(*this));
	}

	std::string ToString() const
	{
		stringstream stream;
		stream << "Name: "<< name << " " << this->GetShape()->ToString();
		return stream.str();
	}

	friend ostream& operator << (std::ostream& os, const NameDecorator& n)
	{ // Send to ostream

		os << "Name: " << n.name << " " << n.GetShape()->ToString() << std::endl;

		return os;
	}
};
#endif