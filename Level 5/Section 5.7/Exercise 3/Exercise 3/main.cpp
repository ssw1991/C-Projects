#include <boost/bimap.hpp>
#include <string>
#include <utility>
#include <iostream>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/set_of.hpp>

// For tagging purposes
struct Author {};
struct Title {};
struct Price {};

using namespace boost::bimaps;

// Each author can have many books, so we will have many authors
// but each book title is unique
// Real world applications limited - ISBM with title and price as info more realistic


using Library = boost::bimap<
	multiset_of< tagged<std::string, Author>>,
	set_of< tagged<std::string, Title>>,
	with_info < tagged< double, Price> > >;

using Book = Library::value_type;
int main()
{
	Library lib; 
	
	lib.insert(Book("Jk Rowling", "Harry Potter", 15.99));
	lib.insert(Book("Jk Rowling", "Harry Potter 2", 15.99));
	lib.insert(Book("Dan Draper", "Something I like", 22.98));

	auto i = lib.by<Author>().find("Jk Rowling");

	while (i != lib.by<Author>().end())
	{
		std::cout << i->get<Title>() <<": " << i->get<Price>() << std::endl;
		++i;  // The price is stored with the book
	}


}