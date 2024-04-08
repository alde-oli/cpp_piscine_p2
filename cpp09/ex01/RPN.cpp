#include "RPN.hpp"


static void	parseString(std::string str)
{
	if (str.find_first_not_of("1234567890+-*/ \t") != std::string::npos)
		throw InvalidCharacterException();

	int		numbers = 0;
	int		operators = 0;

	for (long unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			numbers++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			operators++;
	}

	if (numbers - operators > 1)
		throw MissingOperatorException();
	else if (numbers - operators < 1)
		throw MissingNumberException();
}

void	RPN(std::string str)
{
	parseString(str);

	std::stack<int>	stack;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			stack.push(std::atoi(str.substr(i).c_str()));
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
		{
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (str[i] == '+')
				stack.push(a + b);
			else if (str[i] == '-')
				stack.push(a - b);
			else if (str[i] == '*')
				stack.push(a * b);
			else if (str[i] == '/')
			{
				if (b == 0)
					throw DivisionByZeroException();
				stack.push(a / b);
			}
		}
	}
	std::cout << stack.top() << std::endl;
}



//////////////
//exceptions//
//////////////

const char* InvalidCharacterException::what() const throw()
{
	return ("Invalid character");
}

const char* MissingNumberException::what() const throw()
{
	return ("Missing number");
}

const char* MissingOperatorException::what() const throw()
{
	return ("Missing operator");
}

const char* DivisionByZeroException::what() const throw()
{
	return ("Division by zero");
}
