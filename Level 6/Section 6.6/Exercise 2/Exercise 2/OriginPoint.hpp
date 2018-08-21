#ifndef ORIGINPOINT_HPP
#define ORIGINPOINT_HPP

#include "Singleton.cpp"
#include "Point.hpp"
#include <iostream>
class OriginPoint :public Singleton< Point >
{
public:
	OriginPoint() {}
	virtual ~OriginPoint() {};
	OriginPoint(const OriginPoint & source) = delete;    // copy constructor
	OriginPoint & operator = (const OriginPoint& source) = delete; // Assignment operator

};
extern OriginPoint op;   // Declaring single global instance



#endif