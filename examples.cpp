#include "header.h"
#include "grid.h"
#include "fibonacci.h"
#include "combinatorial_utils.h"
#include "dputils.h"
#include "matrix.h"

int main()
{

	Matrix<int> m(3,3);

	for (size_t i=1; i <= 3; i++)
	{
		for (size_t j=1; j <= 3; j++)
		{
			m.setValue(i, j, 3);
		}
	}

	std::cout << m << std::endl;

	//std::cout << m.nRows() << std::endl;
	//std::cout << m.nCols() << std::endl;
	//std::cout << m.getMinor(2,2,3)  << std::endl;

	std::cout << ~m << std::endl;
}
