#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>



using InputFunction = std::function<double()>; 
using OutputFunction = std::function<void(const std::vector<double>&)>;


class TMPClass
{
private:
	std::vector<double> m_v;
	InputFunction _iFunction;
	OutputFunction _oFunction;
	


public:
	TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction)
	{
		
		for (int i = 0; i < n; ++i)
		{
			m_v.push_back(startValue); //From Duffy's comment 5/10/16
		}
		_iFunction = iFunction;
		_oFunction = oFunction;
	}


	void compute()
	{
		auto fact = _iFunction();
		std::vector<double> v;
		v.resize(m_v.size());
		std::transform(m_v.begin(), m_v.end(), v.begin(), [fact](double a) {return  a* fact; });
		_oFunction(v);
	}
};

double Ifunc()
{
	return 2.0;
}

void Ofunc(const std::vector<double>& v)
{
	for (auto elem : v)
		std::cout << elem << ", ";
	std::cout << "END";
}


int main() 
{
	auto i = Ifunc;
	auto o = Ofunc;

	TMPClass T(5, 1.0, Ifunc, Ofunc);
	T.compute();

}