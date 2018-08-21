#include <tuple>
#include <memory>
#include <iostream>
#include "Shapes.hpp"
#include "IODevice.hpp"






using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;

class Builder
{ // A Builder hierarchy that builds shapes and io devices 
public:
	std::tuple<ShapePointer, IODevicePointer> getProduct()
	{ 
		auto data = std::make_tuple<ShapePointer, IODevicePointer>(getShape(), getIODevice());
		return(data);
	}

	// Hook functions that derived classes must implement  
	virtual ShapePointer getShape() = 0;
	virtual IODevicePointer getIODevice() = 0;
};

class Graphic_CircleBuilder : public Builder
{
public:
	ShapePointer getShape()
	{
		ShapePointer p = ShapePointer(new Circle);
		return p;
	}

	IODevicePointer getIODevice()
	{
		IODevicePointer p =  IODevicePointer(new Graphics);
		return(p);

	}
};


int main()
{
	Graphic_CircleBuilder GB;

	std::tuple<ShapePointer, IODevicePointer> myProd = GB.getProduct();

	std::get<0>(myProd)->display();
}


	