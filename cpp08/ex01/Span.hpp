#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class Span
{
	public:
		Span(unsigned int N);
		Span(unsigned int N, std::initializer_list<int> list);
		Span(Span const &other);
		~Span();

		Span					&operator=(Span const &other);
		int						&operator[](unsigned int i);

		void					addNumber(int i);
		void					addNumber(std::array a);
	
		int						shortestSpan();
		int						longestSpan();

		class 					OutOfRangeExcetion
			: public std::exception
		{
			virtual const char	*what() const throw();
		};

		class 					SpanFullExcetion
			: public std::exception
		{
			virtual const char	*what() const throw();
		};

	private:
		const unsigned int		_N;
		std::vector<int>		_v;
};

#endif