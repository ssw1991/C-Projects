#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>

class[[deprecated("Use New")]] Old
{ 
private: 
	int x;
	int y;

public:
	Old() :x(0), y(0)
	{};

	Old(int& x, int& y) : x(x), y(y)
	{};

	void Draw()
	{
		std::cout << x << ", " << y << std::endl;
	}
};


class New
{
private:
	int x;
	int y;

public:
	New() :x(0), y(0)
	{};

	New(int& x, int& y) : x(x), y(y)
	{};

	[[deprecated("use draw")]]
	void Draw()
	{
		std::cout << x << ", " << y << std::endl;
	}

	void draw()
	{
		std::cout << "X: " << x << ", Y: " << y << std::endl;
	}
};


template<typename T>
class square
{
	T operator () (T val)
	{
		return (val * val);
	};
};


template<>
class [[deprecated]] square<int>
{
	int operator () (int val)
	{
		return (val * val);
	}
};



#endif