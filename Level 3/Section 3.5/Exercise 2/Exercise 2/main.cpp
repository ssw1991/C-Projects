#include "Command.hpp"
#include <queue>



double Algo(double x)
{ // Algo to test
	return x * x;
}

int main()
{

	Command c1(Algo, 1);
	Command c2(Algo, 3);
	Command c3(Algo, 5);
	Command c4(Algo, 2);

	std::priority_queue<Command> q;
	q.push(c1); q.push(c2); q.push(c3); q.push(c4);

	while (!q.empty())
	{
		Command a = q.top();
		a.Execute(9);
		q.pop();
	}

}
