#ifndef SHAPES_H
#define SHAPES_H



class Shape
{
public:
	virtual void draw() = 0;
};

class Base
{
private:
	int y;
public:
	Base() {}
	void draw() {}
};

class Point: public Shape
{
public:
	Point() {}
	virtual void draw() override {}
};

#endif
