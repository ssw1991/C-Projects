// Long Observer

#ifndef DOUBLEOBSERVER_HPP
#define DOUBLEOBSERVER_HPP

#include "Subject.hpp"
#include <memory>
#include <iostream>
#include <iomanip>

void DoubleFormat(int s)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2) << "From Double: " << static_cast<double>(s) << std::endl;
};
#endif