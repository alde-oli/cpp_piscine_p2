#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	int size = rand() % 30;
	std::cout << "creating Span of size: " << size << std::endl;
	Span sp = Span(size);
	int toAdd = rand() % 50;
	std::cout << "trying to add " << toAdd << " numbers" << std::endl << std::endl;
	int added = 0;
	int failed = 0;
	for (int i = 0; i < toAdd; i++)
	{
		try
		{
			sp.addNumber(rand() % 100);
			added++;
		}
		catch (std::exception &e)
		{
			std::cout << "exception: " << e.what() << std::endl;
			failed++;
		}
		
	}
	std::cout << std::endl << "added " << added << " numbers" << std::endl;
	std::cout << "failed to add " << failed << " numbers" << std::endl << std::endl;
	int shortest = 0;
	int longest = 0;
	try
	{
		shortest = sp.shortestSpan();
		longest = sp.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	std::cout << "shortest span is " << shortest << std::endl;
	std::cout << "longest span is " << longest << std::endl;
}