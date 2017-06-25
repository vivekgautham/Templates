
#include "../combinatorial_utils.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CombinatorialUtilsTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( pascaltriangle )
{
    PascalTriangle p;

    BOOST_CHECK_EQUAL( p.getBinomialCoeff(0, 0), 1);
    BOOST_CHECK_EQUAL( p.getBinomialCoeff(3, 0), 1);
    BOOST_CHECK_EQUAL( p.getBinomialCoeff(3, 1), 3);
}
