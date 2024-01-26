#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

///////////////////////////////
//constructors and destructor//
///////////////////////////////

BitcoinExchange::BitcoinExchange(const std::string &btcvalue)
{
	std::ifstream file(btcvalue.c_str());

	if (!file.is_open())
		throw FileError();
		
	std::string	line;
	std::string	dateStr;
	std::string	valueStr;
	Date		d;
	double		v;
	double		temp;

	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream linestream(line);
		std::getline(linestream, dateStr, ',');
		std::getline(linestream, valueStr);

		d.set(dateStr);

		v = -3;
		std::istringstream valueStream(valueStr);
		if (valueStream >> temp)
		{
			if (temp < 0)
				v = -1;
			else
				v = temp;
		}

		if (v == -3 || d.isValid == false)
			std::cerr << "Warning: bad input => " << line << std::endl;
		else
			_btcprice[d] = v;
	}
	file.close();
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}


BitcoinExchange::~BitcoinExchange()
{
}



//////////////////////
//operators overload//
//////////////////////

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		if (!_btcprice.empty())
			_btcprice.clear();
		_btcprice = other._btcprice;
	}
	return (*this);
}


std::ostream &operator<<(std::ostream &out, BitcoinExchange const &other)
{
	std::map<Date, double>::const_iterator curr = other.btcpriceBegin();
	std::map<Date, double>::const_iterator end = other.btcpriceEnd();

	out << "Bitcoin exchange rate over time:" << std::endl;
	out << "Date | Value" << std::endl;

	while (curr != end)
	{
		if (curr->first.year < 0)
			out << curr->first.dateStr << std::endl;
		else
		{
			out << std::setw(4) << std::setfill('0') << curr->first.year;
			out << "-" << std::setw(2) << std::setfill('0') << curr->first.month;
			out << "-" << std::setw(2) << std::setfill('0') << curr->first.day;
			out << " | " << curr->second << std::endl;
		}

		++curr;
	}
	return out;
}




//////////////
//exceptions//
//////////////

const char	*BitcoinExchange::FileError::what() const throw()
{
	return ("could not open file");
}



///////////
//getters//
///////////

std::map<Date, double>::const_iterator	BitcoinExchange::btcpriceBegin() const
{
	return (_btcprice.begin());
}


std::map<Date, double>::const_iterator	BitcoinExchange::btcpriceEnd() const
{
	return (_btcprice.end());
}



////////////////////
//member functions//
////////////////////

void	display(Date const &d, double const &v, std::map<Date, double> const &btcprice)
{

	if (d.isValid == false || v == -3)
		std::cout << "Error: bad input => " << d.dateStr << std::endl;
	else if (v == -2)
		std::cout << "Error: too large a number." << std::endl;
	else if (v == -1)
		std::cout << "Error: not a positive number." << std::endl;
	else if (d < btcprice.begin()->first)
		std::cout << "Error: date too low." << std::endl;
	else
	{
		std::map<Date, double>::const_iterator btcPriceIt = btcprice.lower_bound(d);
		if (btcPriceIt == btcprice.end() || btcPriceIt->first != d)
			if (btcPriceIt != btcprice.begin())
				--btcPriceIt;
		std::cout << std::setw(4) << std::setfill('0') << d.year << "-"
				<< std::setw(2) << std::setfill('0') << d.month << "-"
				<< std::setw(2) << std::setfill('0') << d.day
				<< " => " << v << " = " << ((btcPriceIt != btcprice.end()) ? (v * btcPriceIt->second) : 0) << std::endl;
	}
}


void BitcoinExchange::showValue(std::string const &ownedbtc) const
{
	std::string				line;
	std::string				dateStr;
	std::string				valueStr;
	Date					d;
	double					v;
	double					temp;
	std::ifstream			file(ownedbtc.c_str());

	if (!file.is_open())
		throw FileError();

	std::getline(file, line);
	while (std::getline(file, line))
	{
		d.dateStr = line;

		std::istringstream linestream(line);
		std::string dateStr;
		std::getline(linestream, dateStr, ' ');
		std::getline(linestream, line, '|');
		std::getline(linestream, line, ' ');
		std::getline(linestream, valueStr);

		d.set(dateStr);

		// std::cout << std::endl << "new line: " << d.dateStr << std::endl;
		// std::cout << d.isValid << std::endl;
		// std::cout << d.year << "-" << d.month << "-" << d.day << std::endl;

		v = -3;

		std::istringstream valueStream(valueStr);
		if (valueStream >> temp)
		{
			if (temp < 0)
				v = -1;
			else if (temp > 1000)
				v = -2;
			else
				v = temp;
		}

		//std::cout << v << std::endl;

		display(d, v, this->_btcprice);
	}
	file.close();
}



////////////////
//Date methods//
////////////////

void Date::set(std::string const &date)
{
	static int invalidYear = 0;
		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		isValid = false;
		year = invalidYear;
		month = 0;
		day = 0;
		invalidYear--;
		return;
	}

	try
	{
		year = std::atoi(date.substr(0, 4).c_str());
		month = std::atoi(date.substr(5, 2).c_str());
		day = std::atoi(date.substr(8, 2).c_str());
	}
	catch (const std::invalid_argument& e)
	{
		isValid = false;
		year = invalidYear;
		month = 0;
		day = 0;
		invalidYear--;
		return;
	}

	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		isValid = false;
		
		return;
	}
	if (month == 2 && day > (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28))
	{
		isValid = false;
		return;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		isValid = false;
		return;
	}
	isValid = true;
}


bool Date::operator<(Date const &other) const
{
	if (year != other.year)
		return (year < other.year);
	else if (month != other.month)
		return (month < other.month);
	else
		return (day < other.day);
}


bool Date::operator>(Date const &other) const
{
	if (year != other.year)
		return (year > other.year);
	else if (month != other.month)
		return (month > other.month);
	else
		return (day > other.day);
}


bool Date::operator==(Date const &other) const
{
	return (year == other.year && month == other.month && day == other.day);
}


bool Date::operator!=(Date const &other) const
{
	return (year != other.year || month != other.month || day != other.day);
}
