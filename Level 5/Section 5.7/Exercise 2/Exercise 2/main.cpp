#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/bimap.hpp>
#include <boost/unordered_set.hpp>
#include <string>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <utility>
#include <iostream>

struct IpAddress {};
struct DomainName {};

#include <boost/bimap/unordered_set_of.hpp>
using DNSType = boost::bimap<
	boost::bimaps::unordered_set_of<boost::bimaps::tagged<std::string, DomainName>>,
	boost::bimaps::unordered_set_of<boost::bimaps::tagged<boost::uuids::uuid, IpAddress>>,
	boost::bimaps::list_of_relation>;  // user friendly
					

using Position = std::pair<std::string, boost::uuids::uuid>;

void Print(DNSType& d)
{// Iterate through in relation view and print
	for (auto i = d.begin(); i != d.end(); i++)
		std::cout << i.dereference().left << ": " << i.dereference().right << std::endl;
}



int main()
{
	DNSType Dns;

	boost::uuids::string_generator stGen;
	
	// Create 4 ips
	boost::uuids::uuid ip1 = stGen("0123456789abcdef0123456789ABCDEF");
	boost::uuids::uuid ip2 = stGen("0123444789abcdef0123456789ABCDEF");
	boost::uuids::uuid ip3 = stGen("0123456788abcdef0123456789ABCDEF");
	boost::uuids::uuid ip4 = stGen("0123455589abcdef0123456789ABCDEF");
	
	// Push back
	Dns.push_back(DNSType::value_type("www.google.com", ip1));
	Dns.push_back(DNSType::value_type("www.wissen.io", ip2));
	Dns.push_back(DNSType::value_type("www.cppplus.com", ip3));
	Dns.push_back(DNSType::value_type("www.cpp.com",ip4));

	//Find by name
	auto ip = Dns.by<DomainName>().find("www.cpp.com");
	
	if (ip != Dns.by<DomainName>().end())
		std::cout << "www.cpp.com ip is: " << ip->get<IpAddress>() << std::endl;
	// Find by ip
	auto domain = Dns.by<IpAddress>().find(ip1);

	if (domain != Dns.by<IpAddress>().end())
		std::cout << ip1 << " has Domain name: " << domain->get<DomainName>() << std::endl;
	Print(Dns);
}