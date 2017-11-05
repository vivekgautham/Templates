#include "header.h"
#include "next_sequence.h"
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


	std::vector<int> v = {1, 2, 6, 4, 5};

	std::cout << almostIncreasingSequence(v.begin(), v.end()) << "\n\n" << std::endl;

	std::vector<int> v1 = {10, 1, 2, 3, 4, 5};

	std::cout << almostIncreasingSequence(v1.begin(), v1.end()) << std::endl;


}
