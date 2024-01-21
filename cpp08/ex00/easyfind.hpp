#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class   NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Element not found");
		}
};

template <typename AnyType>
typename AnyType::iterator easyfind(AnyType &container, int value)
{
	typename AnyType::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif