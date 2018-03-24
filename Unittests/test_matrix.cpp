#include "../src/matrix.h"
#include "../src/matrix_utils.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(MATRIX)

BOOST_AUTO_TEST_CASE( Determinant )
{
    Matrix<int> m(3,3);
    for (size_t i=1; i<=3; i++)
    {
      for (size_t j=1; j<=3; j++)
      {
        m.setValue(i, j, 3);
      }
    }
    BOOST_CHECK_EQUAL( ~m , 0);
    int mat[3][3] = {
                     {3, 0, 0},
                     {2, 1, 4},
                     {1, 0, 5}
                    };
    Matrix<int> m2(3,3);
    for (size_t i=1; i<=3; i++)
    {
      for (size_t j=1; j<=3; j++)
      {
        m2.setValue(i, j, mat[i-1][j-1]);
      }
    }
    BOOST_CHECK_EQUAL( ~m2 , 15);
    int mat1[4][4] = {{1, 0, 2, -1},
                     {3, 0, 0, 5},
                     {2, 1, 4, -3},
                     {1, 0, 5, 0}
                    };
    Matrix<int> m1(4,4);
    for (size_t i=1; i<=4; i++)
    {
      for (size_t j=1; j<=4; j++)
      {
        m1.setValue(i, j, mat1[i-1][j-1]);
      }
    }
    BOOST_CHECK_EQUAL( ~m1 , 30);
}

BOOST_AUTO_TEST_CASE( Multiplication )
{
    Matrix<int> m(3,3);
    for (size_t i=1; i<=3; i++)
    {
      for (size_t j=1; j<=3; j++)
      {
        m.setValue(i, j, 3);
      }
    }
    int mat[3][3] = {
                     {3, 0, 0},
                     {2, 1, 4},
                     {1, 0, 5}
                    };
    Matrix<int> m2(3,3);
    for (size_t i=1; i<=3; i++)
    {
      for (size_t j=1; j<=3; j++)
      {
        m2.setValue(i, j, mat[i-1][j-1]);
      }
    }
    Matrix<int> res(3, 3);
    res = m * m2;
    /*BOOST_CHECK_EQUAL( res.nRows() , 3);
    BOOST_CHECK_EQUAL( res.nCols() , 3);*/
}



BOOST_AUTO_TEST_CASE( CreateMatrix )
{
    Matrix<int> m(3,3);
    m = createNumMatrix<int> ("3 3 3 0 0 2 1 4 1 0 5");
    int mat[3][3] = {
                     {3, 0, 0},
                     {2, 1, 4},
                     {1, 0, 5}
                    };
    Matrix<int> m2(3,3);
    for (size_t i=1; i<=3; i++)
    {
      for (size_t j=1; j<=3; j++)
      {
        m2.setValue(i, j, mat[i-1][j-1]);
      }
    }
    BOOST_CHECK( m2 == m);
}

BOOST_AUTO_TEST_SUITE_END()
