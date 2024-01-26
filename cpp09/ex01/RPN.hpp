#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stack>
#include <stdexcept>

void	RPN(std::string str);

class InvalidCharacterException
	: public std::exception
{
	public:
		virtual const char* what() const throw();
};

class MissingNumberException
	: public std::exception
{
	public:
		virtual const char* what() const throw();
};

class MissingOperatorException
	: public std::exception
{
	public:
		virtual const char* what() const throw();
};

class DivisionByZeroException
	: public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif