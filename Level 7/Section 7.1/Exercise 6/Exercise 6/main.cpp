#include "Counter.hpp"
#include "LongFormat.hpp"
#include "DoubleFormat.hpp"
#include <memory>
#include <deque>
#include <functional>

using MyFunction = std::function<void(int)>;

int main()
{
	Counter<std::deque, MyFunction> C1;

	auto f1 = LongFormat;
	auto f2 = DoubleFormat;

	C1.Attach(f1);
	C1.Attach(f2);
	

	C1.IncreaseCounter();
	C1.DecreaseCounter();

}