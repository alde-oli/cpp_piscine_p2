#include "ScalarConverter.hpp"
#include <climits>
#include <string>
#include <cfloat>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

///////////////////////////////
//constructors and destructor//
///////////////////////////////

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {(void)src;}

ScalarConverter::~ScalarConverter() {}

//////////////////////
//operators overload//
//////////////////////

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {(void)src; return (*this);}

/////////////////
//main function//
/////////////////

void	ScalarConverter::convert(const std::string& input)
{
	if (isChar(input))
		fromChar(input);
	else if (isInt(input))
		fromInt(input);
	else if (isFloat(input))
		fromFloat(input);
	else if (isDouble(input))
		fromDouble(input);
	else if (isSpecial(input))
		fromSpecial(input);
	else
		std::cout << "Invalid input\nPlease enter a char, int, float or double\n" << std::endl;
}

///////////////////////
//detection functions//
///////////////////////
bool	ScalarConverter::isChar(const std::string& input)
{
	if (input.length() == 1)
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string& input)
{
	std::string	numStr = input;
	long		num;
	if (input.empty() || input.length() > 11)
		return (false);
	if (numStr[0] == '+' || numStr[0] == '-')
		numStr = numStr.substr(1);
	if (numStr.empty() || numStr.find_first_not_of("0123456789") != std::string::npos)
		return (false);
	num = std::atol(numStr.c_str());
	if (num <= INT_MAX && num >= INT_MIN)
		return (true);
	std::cout << "int overflow" << std::endl;
	return (false);
}

bool ScalarConverter::isFloat(const std::string& input)
{
	if (input.empty())
		return (false);
	std::string numStr = input;
	if (numStr[0] == '+' || numStr[0] == '-')
		numStr = numStr.substr(1);
	if (numStr[numStr.length() - 1] != 'f')
		return (false);
	numStr = numStr.substr(0, numStr.length() - 1);
	if (numStr.empty() || numStr.find_first_of(".") != numStr.find_last_of("."))
		return (false);
	if (numStr.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	double num = std::strtod(numStr.c_str(), NULL);
	if (!(errno == ERANGE) && (num <= static_cast<double>(FLT_MAX) && num >= -static_cast<double>(FLT_MAX)))
		return (true);
	std::cout << "float overflow" << std::endl;
	return (false);
}

bool ScalarConverter::isDouble(const std::string& input)
{
	if (input.empty())
		return (false);
	std::string numStr = input;
	if (numStr[0] == '+' || numStr[0] == '-')
		numStr = numStr.substr(1);
	if (numStr.empty() || numStr.find_first_of(".") != numStr.find_last_of("."))
		return (false);
	if (numStr.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	double num = std::strtod(numStr.c_str(), NULL);
	if (!(errno == ERANGE) && (num <= static_cast<double>(DBL_MAX) && num >= -static_cast<double>(DBL_MAX)))
		return (true);
	std::cout << "double overflow" << std::endl;
	return (false);
}

bool ScalarConverter::isSpecial(const std::string& input)
{
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		return (true);
	return (false);
}

////////////////////////
//conversion functions//
////////////////////////

void	ScalarConverter::fromChar(const std::string& input)
{
	char c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)  << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::fromInt(const std::string& input)
{
	int i = std::atoi(input.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char: ";
	if (CHAR_MIN <= i && i <= CHAR_MAX && isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (CHAR_MIN <= i && i <= CHAR_MAX)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::fromFloat(const std::string& input)
{
	float f = std::atof(input.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char: ";
	if (CHAR_MIN <= f && f <= CHAR_MAX && isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (f >= CHAR_MIN && f <= CHAR_MAX)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (f >= INT_MIN && f <= INT_MAX)
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::fromDouble(const std::string& input)
{
	double d = std::strtod(input.c_str(), NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char: ";
	if (CHAR_MIN <= d && d <= CHAR_MAX && isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (d >= CHAR_MIN && d <= CHAR_MAX)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (d >= -FLT_MAX && d <= FLT_MAX)
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::fromSpecial(const std::string& input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nan" || input == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (input == "+inf" || input == "+inff")
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: -inff" << std::endl;
	if (input == "nan" || input == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (input == "+inf" || input == "+inff")
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: -inf" << std::endl;
}
