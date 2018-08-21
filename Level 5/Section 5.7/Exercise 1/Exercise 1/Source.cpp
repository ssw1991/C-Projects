#include <boost/bimap.hpp>
#include <string>
#include <iostream>

typedef boost::bimap<std::string, int> PersonMap; // For some reasone using would'nt compile here "cant use qualified name"
typedef PersonMap::value_type Position;
typedef PersonMap::left_map::const_iterator ILeft;  // define right and left iterators
typedef PersonMap::right_map::const_iterator IRight;

int main()
{
	boost::bimap<std::string, int> people;

	people.insert(Position("Mark", 26));
	people.insert(Position("Thom", 26));
	people.insert(Position("James", 24));
	people.insert(Position("Kamber", 13));


	std::cout << "LEFT VIEW" << std::endl;
	for (ILeft i = people.left.begin(); i != people.left.end(); i++)
		std::cout << i.dereference().first << ": " << i.dereference().second<< std::endl;  // Why doesnt -> work?

	std::cout << "RIGHT VIEW" << std::endl;
	for (IRight i = people.right.begin(); i != people.right.end(); i++)
		std::cout << i.dereference().first << ": " << i.dereference().second << std::endl;  // Why doesnt -> work?

	std::cout << "THIRD VIEW" << std::endl;
	for(auto i = people.begin(); i != people.end(); i++)
		std::cout << i.dereference().left << ": " << i.dereference().right << std::endl;


	try
	{
		std::cout << "The thirteen year old is: " << people.right.at(13) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "No on is 13" << std::endl;
	}

	try
	{
		std::cout << "The James is: " << people.left.at("James") << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "James does not exist" << std::endl;
	}



}