#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename AnyType>
class Array
{
	public:
		Array() : _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new AnyType[n]), _size(n) {};
		Array(Array const &other) : _array(NULL), _size(0) { *this = other; };
		~Array() { delete [] _array; };

		Array			&operator=(Array const &other)
		{
			if (this != &other)
			{
				if (_array)
					delete[] _array;
				_array = new AnyType[other._size];
				_size = other._size;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return (*this);
		};
		AnyType			&operator[](unsigned int i)
		{
			if (i >= _size)
				throw OutOfRangeException();
			return (_array[i]);
		};

		class			OutOfRangeException
			: public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Out of range");
			};
		};

		unsigned int	size() const { return (_size); };

	private:
		AnyType			*_array;
		unsigned int	_size;
};

#endif