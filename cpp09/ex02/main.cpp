#include "PmergeMe.hpp"
#include "ctime"

void	solveDeque(int ac, char **av)
{
		std::deque<int> d;
	try
	{
		d = parseInputDeque(ac, av);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	clock_t		time = clock();
	d = PmergeMDeque(d);
	time = clock() - time;

	std::cout << "Before: ";
	for (int i = 1; i < ac; ++i)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	double time_ms = double(time) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << time_ms << "us" << std::endl;
}

void	solveVector(int ac, char **av)
{
	std::vector<int> v;
	try
	{
		v = parseInputVector(ac, av);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	clock_t		time = clock();
	v = PmergeMVector(v);
	time = clock() - time;

	double time_ms = double(time) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << time_ms << "us" << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: " << av[0] << " [number ...]" << std::endl;
		return EXIT_FAILURE;
	}
	solveDeque(ac, av);
	solveVector(ac, av);
	return EXIT_SUCCESS;
}