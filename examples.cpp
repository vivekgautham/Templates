#include "header.h"
#include "grid.h"
#include "fibonacci.h"
#include "combinatorial_utils.h"
#include "dputils.h"
int main()
{

	std::vector<int> p = {50, 3, 10, 7, 40, 80};
	unsigned a = DP::longestSubsequence(p.begin(), p.end());
	std::cout << a << '\n';


}
