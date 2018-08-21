#include <iostream>
#include <forward_list>
#include <vector>


int length(std::forward_list<int>& l)
{//Use distance to compute lenght of list
	auto begin = l.begin();
	auto end = l.end();
	return std::distance(begin, end);
}

void print(std::forward_list<int> l)
{
	for (const auto i : l) std::cout << i << ", ";
	std::cout<<std::endl;
}

void erase(std::forward_list<int>& l, std::forward_list<int>::iterator begin)
{
	l.erase_after(begin); //erases the element after given iterator
}

void erase(std::forward_list<int>& l, std::forward_list<int>::iterator begin, std::forward_list<int>::iterator end)
{
	l.erase_after(begin, end); //erases the elements between given iterators
}
int main()
{
	std::forward_list<int> l1(20, 5);  // list with 20 5's
	std::forward_list<int> l2{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }; // Initalizer List
	std::cout << "Length: " << length(l2) << std::endl;
	
	std::cout << "l1: "; print(l1); 
	std::cout << "l2: "; print(l2);
	

	auto beginIt = l2.begin();
	auto endIt = std::next(beginIt, 14);
	

	l2.insert_after(endIt, 16);  // insert after endIt
	std::cout << "l2: "; print(l2);
	

	l2.insert_after(endIt, 3, 1);  // insert 3 0's after 15 (before 16 because endIt didnt move
	std::cout << "l2: "; print(l2);

	
	l2.insert_after(endIt,{16, 17, 18, 19}); // insert with initializer list No overload for initliazer list and two iterators
	std::cout << "l2: "; print(l2);

	std::vector<int> v{ 1,2,3 };
	
	l2.insert_after(endIt, v.begin(), v.end());  // insert with input iterators
	std::cout << "l2: "; print(l2);

	auto bb = l2.before_begin();

	erase(l2, bb); //Erase first element
	std::cout << "l2: "; print(l2);


	erase(l2, std::next(bb, 5),std::next(bb,10));
	std::cout << "l2: "; print(l2);

	l2.splice_after(endIt, l1, std::next(l1.begin(), 3), l1.end());   // after endIt will add 16 5's 
	std::cout << "l2: "; print(l2);
	std::cout << "l1: "; print(l1);   // L1 is now smaller

	l1.sort();
	l2.sort(); //has to be sorted to merge
	l2.merge(l1);
	std::cout << "l2: "; print(l2);
	
}