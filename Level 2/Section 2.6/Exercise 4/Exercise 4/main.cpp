#include <system_error>
#include <tuple>
#include <iostream>
#include <string>

template<typename T>
std::tuple<std::string, int, std::string> GetInfo(T e)
{
	std::string message = e.message();
	std::string cat = e.category().name();
	int val = e.value();
	auto t = std::make_tuple(message, val, cat);
	return t;
}


int main()
{

	std::error_code e1;
	std::error_condition e2(1, std::system_category());
	std::error_code e3(1, std::system_category());
	

	std::tuple<std::string, int, std::string> a = GetInfo(e1);
	std::tuple<std::string, int, std::string> b = GetInfo(e2);
	std::tuple<std::string, int, std::string> c = GetInfo(e3);


	std::string e1message = std::get<0>(a);
	std::string e1cat = std::get<2>(a);
	int e1val = std::get<1>(a);

	std::string e2message = std::get<0>(b);
	std::string e2cat = std::get<2>(b);
	int e2val = std::get<1>(b);

	std::string e3message = std::get<0>(c);
	std::string e3cat = std::get<2>(c);
	int e3val = std::get<1>(c);

	std::cout << "E1 message: " << e1message << " E1 value: " << e1val << " E1 Cat: " << e1cat << std::endl;
	std::cout << "E2 message: " << e2message << " E2 value: " << e2val << " E2 Cat: " << e2cat << std::endl;
	std::cout << "E3 message: " << e3message << " E3 value: " << e3val << " E1 Cat: " << e3cat << std::endl;

	std::cout << std::boolalpha;

	std::cout << "Is error condition (1, system_category) == to error_code: " << (e2 == e3);


}
