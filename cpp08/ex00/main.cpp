#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include "easyfind.hpp"

template <typename AnyType>
void	printContainer(AnyType &container)
{
	typename AnyType::iterator it;

	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}

template <typename AnyType>
void	createContainer(AnyType &container)
{
	int	size = rand() % 12 + 4;
	std::vector<int>	values(size);
	for (int i = 0; i < size; i++)
		values[i] = rand() % 15;
	container = AnyType(values.begin(), values.end());
}

template <typename AnyType>
void	testEasyFind(AnyType &container, int nb_test)
{
	int	value;
	typename AnyType::iterator it;

	std::cout << "Running " << nb_test << " tests:" << std::endl;
	for (int i = 0; i < nb_test; i++)
	{
		value = rand() % 15;
		std::cout << "Value to find: " << value << std::endl;
		try
		{
			it = easyfind(container, value);
			std::cout << "Value found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "exception: " << e.what() << std::endl;
		}
	}
}

int	main()
{
	std::vector<int>	v;
	std::list<int>		l;
	std::deque<int>		d;

	srand(time(NULL));

	createContainer(v);
	createContainer(l);
	createContainer(d);

	std::cout << "Vector container|" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"<< std::endl;
	printContainer(v);
	testEasyFind(v, 5);

	std::cout << std::endl << "List container|" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	printContainer(l);
	testEasyFind(l, 5);

	std::cout << std::endl << "Deque container|" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	printContainer(d);
	testEasyFind(d, 5);

	return (0);
}