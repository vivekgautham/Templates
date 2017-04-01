#include "header.h"
#include "grid.h"
#include "fibonacci.h"


int main()
{
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



}
