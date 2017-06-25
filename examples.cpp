#include "header.h"
#include "grid.h"
#include "fibonacci.h"
#include "combinatorial_utils.h"

int main()
{
	/*
	Grid<int> g;

	FibonacciIterator<int> f;

	std::cout << *f << std::endl;

	f++;

	std::cout << *f << std::endl;

	f++;


	std::cout << *f << std::endl;


	f++;
	f++;
	f++;
	std::cout << *f << std::endl;

	f--;

	std::cout << *f << std::endl;
*/
	PascalTriangle p;
	unsigned a = p.getBinomialCoeff(0, 0);
	std::cout << a << '\n';


}
