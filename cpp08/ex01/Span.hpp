#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <stdexcept>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();

		Span						&operator=(const Span &copy);

		void						addNumber(int n);
		template<typename Iterator>
		void						addNumber(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) > _N)
				throw SpanFullException();
			_set.insert(begin, end);
		}

		int							shortestSpan();
		int							longestSpan();

		class						SpanFullException
			: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class						SpanEmptyException
			: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		unsigned int				_N;
		std::multiset<int>			_set;
};

#endif