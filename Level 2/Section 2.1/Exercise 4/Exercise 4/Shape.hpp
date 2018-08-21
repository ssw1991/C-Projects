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
private:
	int x;
	int y;
	// Data members to move 

public:
	Point() {}
	Point(const Point& point) = delete;		// Disable copy
	Point operator = (Point& p) = delete;   // Disable Assignment

	Point(Point&& source)
	{
		x = std::move(source.x);
		y = std::move(source.y);
	}

	Point& operator = (Point&& source)
	{
		x = std::move(source.x);
		y = std::move(source.y);
		return *this;
	}

	virtual void draw() override {}
};

#endif
