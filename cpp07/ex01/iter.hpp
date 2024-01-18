#ifndef ITER_HPP
# define ITER_HPP

template <typename AnyType>
void	iter(AnyType *a, unsigned int len, void (*fct)(AnyType &))
{
	for (unsigned int i = 0; i < len; i++)
		fct(a[i]);
}

#endif