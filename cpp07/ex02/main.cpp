#include <ctime>
#include <cstdlib>
#include "Array.hpp"

template <typename AnyType>
void	initNumericArray(Array<AnyType> &a)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		a[i] = rand() % 1000;
		a[i] /= 10;
	}
}

void	initStringArray(Array<std::string> &a)
{
	std::string		words[] = {"pouet", "hello", "tut tut", "42", "E", "I like trains", "Templates are great"};

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = words[rand() % 7];
}

template <typename AnyType>
void	printArray(Array<AnyType> &a)
{
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	Array<std::string> a(10);
	Array<int> b(8);
	Array<float> c(6);

	srand(time(NULL));
	initStringArray(a);
	initNumericArray(b);
	initNumericArray(c);

	std::cout << "a:" << std::endl;
	printArray(a);
	std::cout << std::endl << "b:" << std::endl;
	printArray(b);
	std::cout << std::endl << "c:" << std::endl;
	printArray(c);
}