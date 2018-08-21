#ifndef ORIGINPOINT_HPP
#define ORIGINPOINT_HPP

#include "Singleton.cpp"
#include "Point.hpp"

class OriginPoint :public Singleton< Point >
{
private: 
	OriginPoint() : Singleton<Point>(){};
	OriginPoint(const OriginPoint & source) = delete;    // copy constructor
	OriginPoint & operator = (const OriginPoint& source) = delete; // Assignment operator
	friend class Singleton< Point >;
public:
	
};
extern OriginPoint op;


#endif