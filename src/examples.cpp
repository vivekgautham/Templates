#include "header.h"
#include "fraction.h"

int main()
{
	std::vector<int> a = {1, 2, 9, 3};
	std::vector<int> b = {2, 3, 10, 7};
	bool r = betterThanExpected(a, b);
	std::cout << r;
}
