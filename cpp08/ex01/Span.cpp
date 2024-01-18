#include "Span.hpp"

///////////////////////////////
//constructors and destructor//
///////////////////////////////

Span::Span(unsigned int N)
	: _N(N), _v(N)
{
}

Span::Span(unsigned int N, std::initializer_list<int> list)
	: _N(N), _v(list)
{
}

Span::Span(Span const &other)
	: _N(other._N), _v(other._v)
{
}

Span::~Span()
{
}

//////////////////////
//operators overload//
//////////////////////

Span	&Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_v = other._v;
	}
	return (*this);
}

int	&Span::operator[](unsigned int i)
{
	if (i >= this->_N)
		throw Span::OutOfRangeExcetion();
	return this->_v[i];
}

////////////////////
//member functions//
////////////////////

void	Span::addNumber(int i)
{
	if (this->_v.size() < this->_N)
		
}
