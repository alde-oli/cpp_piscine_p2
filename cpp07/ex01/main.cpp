#include <iostream>
#include "iter.hpp"

template <typename AnyType>
void	print(AnyType &a)
{
	std::cout << a << std::endl;
}

template <typename AnyType>
void	doubleValue(AnyType &a)
{
	a *= 2;
}

void	strCapitalize(std::string &s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);
}

int	main(void)
{
	int	a[5] = {0, 1, 2, 3, 4};
	float	b[5] = {0.1f, 42.42f, 21.21f, 101.101f, 4.2f};
	std::string	c[5] = {"hello", "hey", "hi", "good morning", "good evening"};

	std::cout << "test with fct print" << std::endl;
	std::cout << "int array:" << std::endl;
	iter(a, 5, print);
	std::cout << std::endl << "float array:" << std::endl;
	iter(b, 5, print);
	std::cout << std::endl << "string array:" << std::endl;
	iter(c, 5, print);

	std::cout << std::endl << "test with fct doubleValue" << std::endl;
	std::cout << "int array:" << std::endl;
	iter(a, 5, doubleValue);
	iter(a, 5, print);
	std::cout << std::endl << "float array:" << std::endl;
	iter(b, 5, doubleValue);
	iter(b, 5, print);

	std::cout << std::endl << "test with fct strCapitalize" << std::endl;
	std::cout << "string array:" << std::endl;
	iter(c, 5, strCapitalize);
	iter(c, 5, print);

}
