#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class	ScalarConverter
{
	public:
		static void	convert(const std::string& input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& src);

		static bool			isChar(const std::string& input);
		static bool			isInt(const std::string& input);
		static bool			isFloat(const std::string& input);
		static bool			isDouble(const std::string& input);
		static bool			isSpecial(const std::string& input);

		static void			fromChar(const std::string& input);
		static void			fromInt(const std::string& input);
		static void			fromFloat(const std::string& input);
		static void			fromDouble(const std::string& input);
		static void			fromSpecial(const std::string& input);
};

#endif