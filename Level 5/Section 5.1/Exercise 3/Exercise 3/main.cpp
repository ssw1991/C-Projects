#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <boost/algorithm/string/constants.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <map>

using split_vector_type = std::vector<std::string>;


boost::gregorian::date DateConversion(std::string& s)
{// Takes string as yyyy-mm-dd and returns date

	split_vector_type v;
	split(v, s, boost::is_any_of("-"), boost::algorithm::token_compress_on);

	int year = boost::lexical_cast<int>(v[0]);
	int mm = boost::lexical_cast<int>(v[1]);
	int dd = boost::lexical_cast<int>(v[2]);

	return boost::gregorian::date(year, mm, dd);
}

std::map<std::string, double> NameVal(std::string& s)
{
	/*
		Input: comma seperated string of  [name] = [value]
		Output: map<string,double> of name:value
	*/

	std::map<std::string, double> output;

	split_vector_type v1;
	split(v1, s, boost::is_any_of(","), boost::algorithm::token_compress_off);
	std::for_each(v1.begin(), v1.end(), [](auto i) {boost::trim(i); });  // trim strings after split

	for (auto i : v1)
	{ // Each i is now [name] = [value]
		split_vector_type v2;
		std::cout << i << std::endl;
		split(v2, i, boost::is_any_of("="), boost::algorithm::token_compress_on);  // Splits on space or =
		
		output[boost::trim_copy(v2[0])] = boost::lexical_cast<double>(boost::trim_copy(v2[1]));   // Adding name and output to map
	}
	return output;
}

int main()
{

	std::string sA = "1,2,3,4/5/9*56";

	split_vector_type SplitVec;

	split(SplitVec, sA, boost::is_any_of("/*,"), boost::algorithm::token_compress_on);

	std::string sB = boost::join(SplitVec, "/");

	std::cout << sB << std::endl;

	std::string d = "2015-12-31";

	auto date = DateConversion(d);

	std::cout << date << std::endl;

	std::string s = "port = 23, pin = 87, value = 34.4";
	auto map = NameVal(s);

	for (auto i : map)
	{
		std::cout << "{ " << i.first << ": " << i.second << "}\n";
	}

}