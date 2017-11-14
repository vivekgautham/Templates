#include "header.h"
#include "interesting_problems.h"
#include "matrix.h"
#include "matrix_utils1.h"


int main()
{

	Matrix <unsigned> m(3,3);

	m = createNumMatrix<unsigned> ("3 3 0 1 0 0 1 0 1 0 1");

	std::cout << m * m << std::endl;

	rainfallInTerrain(m);

}
