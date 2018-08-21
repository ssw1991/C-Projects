#include <limits>
#include <iostream>

template <typename T>
const char* Classify(T t)
{
	switch (std::fpclassify(t))
	{
	case FP_INFINITE:  return "Inf";
	case FP_NAN: return "NaN";
	case FP_NORMAL:    return "normal";
	case FP_SUBNORMAL: return "subnormal";
	case FP_ZERO: return "zero";
	default:  return "unknown";
	}
}



int main()
{


	double val = std::numeric_limits<double>::max();

	std::cout << Classify(val) << std::endl;               // Normal
	 
	std::cout << Classify(2.0 * val) << std::endl;       // INf

	std::cout << Classify(3.1415 + val) << std::endl;     // Normal

	double val2 = std::numeric_limits<double>::min() - 3.1415;

	std::cout << Classify(val2) << std::endl;              // Normal

	std::cout << Classify(val2 / 2.0) << std::endl;       // Normal
	std::cout << Classify(DBL_MIN / 2.) << std::endl;     // Subnormal


	double factor = 2.0;
	std::cout << std::isfinite(factor) << std::endl;

	val = factor * std::numeric_limits<double>::max();

	std::cout << std::isinf(val) << std::endl;
	std::cout << std::isnan(val-val) << std::endl;
	std::cout << std::isnormal(std::sqrt(-1.0)) << std::endl;
	std::cout << std::isnormal(std::log(0.0)) << std::endl;
	std::cout << std::isnormal(std::exp(val)) << std::endl;
}