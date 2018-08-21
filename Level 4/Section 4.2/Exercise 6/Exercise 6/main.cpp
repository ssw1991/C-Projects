#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include "Point.hpp"
#include <string>

Point ORIGIN = Point(0., 0.);

bool PEqual(const Point& p1, const Point& p2)
{
	return (p1 == p2);
}

bool Origindist(const Point& p1, double& dist)
{
	if (ORIGIN.Distance(p1) > dist) return true;
	else return false;
}

bool equal(char c1, char c2)
{
	return c1 == c2;
}
bool CheckRange(char c1, std::vector<char>& c)
{//Function to check if character is in range
	return std::any_of(c.begin(), c.end(), std::bind(equal, std::placeholders::_1, c1));
}




bool IsChar(char c, std::vector<char>& s)
{
	//std::string whitepace = " \t\n\r\f\v"

	return (std::find(s.begin(), s.end(), c) == s.end());  // return true on anything not in list
}

std::string& ltrim(std::string& s, std::function<bool(char)> Unary)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), Unary));   // Erase everything until the first true
	return s;
}


std::string rtrim(std::string s, std::function<bool(char)> Unary)
{
	int num_trail = std::distance(s.rbegin(), std::find_if(s.rbegin(), s.rend(), Unary));  // Find pos of last item not in list
	s.erase(s.size() - num_trail, num_trail);  // Erase 
	return s;
}


std::string trim_if(std::string s, std::function<bool(char)> Unary) 
{
	 s =rtrim(s, Unary);
	 return (ltrim(s, Unary));
}

void split(const string& s, char delim, vector<string>& v)
{
	auto i = 0;
	auto pos = s.find(delim);  // Find Delim
	while (pos != string::npos) 
	{  //  while pos isnt the end
		v.push_back(s.substr(i, pos - i));  // pushback substring
		i = ++pos; //Move pos forward
		pos = s.find(delim, pos); // rest pos

		if (pos == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

std::string join(std::string& s1, std::string& s2)
{
	return s1 + s2;
}


int main()
{

	std::vector<char> S1 = { 'a','b','c','d','e','k' };
	std::vector<char> S2 = { 'a','e' };

	std::vector<char> S3(S1.size());
	
	
	std::remove_copy_if(S1.begin(), S1.end(), S3.begin(), std::bind(CheckRange, std::placeholders::_1, S2));
	
	for (auto i : S3)
		std::cout << i << " ";
	std::cout << std::endl;


	std::vector<Point> points =
	{
	Point(1.2,3.4),
	Point(3.6, 7.8),
	Point(1.2,3.4),
	Point(9.4, 7.8),
	Point(6.1, 9.4),
	Point(0.5, 0.5)
	};

	std::vector<Point> set_points;

	for (auto i : points)
	{ // No operators defined to sort
		if (std::none_of(set_points.begin(), set_points.end(), std::bind(PEqual, std::placeholders::_1, i)))
			set_points.push_back(i);
	}

	auto last = std::remove_if(set_points.begin(), set_points.end(), std::bind(Origindist, std::placeholders::_1, 4.0));
	set_points.erase(last, set_points.end());

	for (auto i : set_points) 
		std::cout << i.ToString() << std::endl;

	std::string s = "    my string\n\n\n\n    \n";

	std::vector<char> whitespace = { ' ','\t', '\n', '\r', '\f', '\v' };

	
	auto f = std::bind(IsChar, std::placeholders::_1, whitespace);

	std::string s1 = ltrim(s, f);
	std::cout << s1;
	
	s1 = rtrim(s, f);
	std::cout << s1 << std::endl;

	s = "st,st,st";
	std::vector<std::string> v;
	split(s, ',', v);

	for (auto i : v)
		std::cout << i << " ";
	std::string test = "test";
	std::string test2 = " join";
	std::cout << join(test, test2) << std::endl;
}