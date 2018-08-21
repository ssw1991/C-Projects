#include <boost\date_time\gregorian\greg_date.hpp>
#include <iostream>
#include <tuple>
#include <string>
#include <sstream>
#include <vector>

using DATE = boost::gregorian::date;
using PERSON = std::tuple<std::string, std::string, DATE>;


template<typename T>
std::string toString(T& obj)
{
	std::stringstream ss;
	ss << obj;
	return ss.str();
}


template<>
std::string toString(DATE& date)
{
	std::stringstream ss;
	ss << date.year() << "\\" << date.month() << "\\" << date.day();
	return ss.str();

}

template<typename Tuple, std::size_t N> 
	struct TuplePrinter 
	{ 
		static void print(Tuple& pack) 
		{ 
			TuplePrinter<Tuple, N - 1>::print(pack); 
			std::cout << ", " << toString(std::get<N - 1>(pack)); 
		} 
	};


template<typename Tuple> 
	struct TuplePrinter<Tuple, 1> 
	{ 
		static void print(Tuple& pack)
		{ 
			std::cout << toString(std::get<0>(pack)); 
		} 
	};


template <int index> struct TupleLess // Compare elements of a tuple for some index 
{ 
	template <typename Tuple> 
		bool operator () (const Tuple& left, const Tuple& right) const 
		{ // Lexicographical comparison for 'index' 
			return std::get<index>(left) <  std::get<index>(right);
		} 
};

int main()
{

	PERSON p1{ "Sarah", "123 Park Place", DATE{ 1986, 04, 07 } };
	PERSON p2{"Sam", "124 Park Place", DATE{ 1985, 04, 07 }};
	PERSON p3{ "Steve", "125 Park Place", DATE{ 1984, 04, 07 } };
	std::tuple<int, int, int> t{ 1,1,1 };
	

	std::vector<PERSON> v{ p1,p2,p3 };
	
	std::sort(v.begin(), v.end(), TupleLess<1>());

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		TuplePrinter<PERSON, 3>::print(*i);
		std::cout << '\n';
	}

	return 0;
}