#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "MutantStack:" << std::endl << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top of MutantStack: " << mstack.top() << std::endl;

	mstack.pop();
	mstack.push(3);

	std::cout << "MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Reverse MutantStack:" << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << "Size of MutantStack: " << mstack.size() << std::endl << std::endl;



	std::cout << std::endl << "std::list:" << std::endl << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top of std::list: " << lst.back() << std::endl;

	lst.pop_back();
	lst.push_back(3);

	std::cout << "std::list:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "std::list:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Reverse std::list:" << std::endl;
	for (std::list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << "Size of std::list: " << lst.size() << std::endl << std::endl;

	return 0;
}
