#include "Counter.hpp"
#include "LongFormat.hpp"
#include "DoubleFormat.hpp"
#include <memory>


int main()
{
	std::shared_ptr<Counter> ptr(new Counter);

	std::shared_ptr<LongFormat> l(new LongFormat(ptr)); // Calls Attach
	std::shared_ptr<DoubleFormat> d(new DoubleFormat(ptr)); // Calls Attach
	

	ptr->IncreaseCounter();
	ptr->DecreaseCounter();

}