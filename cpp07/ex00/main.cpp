#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	int a = 2;
	int b = 3;
	std::cout << "test with 2 int, a = " << a << ", b = " << b << std::endl << std::endl;
	::swap( a, b );
	std::cout << "swap( a, b ) a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;


	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << std::endl << "test with 2 string, c = " << c << ", d = " << d << std::endl << std::endl;
	::swap(c, d);
	std::cout << "swap( c, d ) c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::string e = "autre chaine";
	void *f = &e;
	void *g = &e[6];
	std::cout << std::endl << "test with 2 void *, f = " << f << ", g = " << g << std::endl << std::endl;
	::swap(f, g);
	std::cout << "swap( f, g ) f = " << f << ", g = " << g << std::endl;
	std::cout << "min( f, g ) = " << ::min( f, g ) << std::endl;
	std::cout << "max( f, g ) = " << ::max( f, g ) << std::endl;

	float h = 42.42f;
	float i = 21.21f;

	std::cout << std::endl << "test with 2 float, h = " << h << ", i = " << i << std::endl << std::endl;
	::swap(h, i);
	std::cout << "swap( h, i ) h = " << h << ", i = " << i << std::endl;
	std::cout << "min( h, i ) = " << ::min( h, i ) << std::endl;
	std::cout << "max( h, i ) = " << ::max( h, i ) << std::endl;

	int j = 42;
	int k = 42;

	std::cout << std::endl << "test with 2 int, j = " << j << ", k = " << k << std::endl << std::endl;
	::swap(j, k);
	std::cout << "swap( j, k ) j = " << j << ", k = " << k << std::endl;
	std::cout << "min( j, k ) = " << ::min( j, k ) << std::endl;
	std::cout << "max( j, k ) = " << ::max( j, k ) << std::endl;
}