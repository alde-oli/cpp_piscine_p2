#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <stdexcept>
# include <iterator>

struct Date
{
	int			day;
	int			month;
	int			year;
	std::string	dateStr;
	bool		isValid;

	void		set(std::string const &date);

	bool		operator<(Date const &other) const;
	bool		operator>(Date const &other) const;
	bool		operator==(Date const &other) const;
	bool		operator!=(Date const &other) const;
};

class BitcoinExchange
{
	public:
		//uses the filename of the exchange rate over time file
		BitcoinExchange(std::string const &btcvalue);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		BitcoinExchange									&operator=(BitcoinExchange const &other);

		//uses the filename of your owned btc over time file
		void											showValue(std::string const &ownedbtc) const;
		std::map<Date, double>::const_iterator			btcpriceBegin() const;
		std::map<Date, double>::const_iterator			btcpriceEnd() const;

		class											FileError
			: public std::exception
		{
			public:
				virtual const char						*what() const throw();
		};

	private:
		std::map<Date, double>							_btcprice;
};

std::ostream &operator<<(std::ostream &out, BitcoinExchange const &other);

#endif