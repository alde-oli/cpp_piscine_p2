#include "Span.hpp"

///////////////////////////////
//constructors and destructor//
///////////////////////////////

Span::Span(unsigned int n)
	: _N(n)
{
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span()
{
}

//////////////////////
//operators overload//
//////////////////////

Span	&Span::operator=(const Span& copy)
{
	_N = copy._N;
	_set = copy._set;
	return *this;
}

////////////////////
//member functions//
////////////////////

void	Span::addNumber(int n)
{
	if (_set.size() >= _N)
		throw SpanFullException();
	_set.insert(n);
}

int		Span::shortestSpan()
{
	if (_set.size() <= 1)
		throw SpanEmptyException();
	std::multiset<int>::iterator	it = _set.begin();
	std::multiset<int>::iterator	it2 = _set.begin();
	it2++;
	int	span = *it2 - *it;
	while (it2 != _set.end())
	{
		if (*it2 - *it < span)
			span = *it2 - *it;
		it++;
		it2++;
	}
	return span;
}

int		Span::longestSpan()
{
	if (_set.size() <= 1)
		throw SpanEmptyException();
	std::multiset<int>::iterator	it = _set.begin();
	std::multiset<int>::iterator	it2 = _set.end();
	it2--;
	return *it2 - *it;
}

////////////////////////
//exception definition//
////////////////////////

const char*	Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char*	Span::SpanEmptyException::what() const throw()
{
	return "Span contains less than 2 elements";
}
