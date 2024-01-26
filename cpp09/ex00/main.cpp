#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	std::string     database = "data2.csv";
	BitcoinExchange *exchange;
	try
	{
		exchange = new BitcoinExchange(database);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << database << ": " << e.what() << std::endl;
		return (1);
	}

	try
	{
		exchange->showValue(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	delete exchange;
}