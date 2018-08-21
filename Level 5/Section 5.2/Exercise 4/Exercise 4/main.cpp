#include <regex>
#include <string>
#include <iostream>
#include <set>
#include <boost/lexical_cast.hpp>
#include <vector>

#include <boost/date_time/gregorian/gregorian.hpp>


using Date = boost::gregorian::date;
using regex = std::regex;


int main()
{
	regex myReg("/");
	std::string mydate = "2016/3/15";

	std::vector<int> v;
	auto num_begin = std::sregex_token_iterator(mydate.begin(), mydate.end(), myReg, -1);

	for (std::sregex_token_iterator i = num_begin; i != std::sregex_token_iterator(); i++)
	{
		v.push_back(boost::lexical_cast<int>(*i));
	}

	
	
	Date myDate(v[0], v[1], v[2]);

	std::cout << myDate;


}