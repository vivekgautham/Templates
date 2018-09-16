#include "../src/fraction.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(FRACTION)

BOOST_AUTO_TEST_CASE( FRAC_TEST )
{
    Fraction a(12, 5);
    Fraction b(9, 5);
    BOOST_CHECK(a > b);
}

BOOST_AUTO_TEST_CASE( BOOL_BETTER_THAN_EXPECTED )
{
    std::vector<int> a = {1, 2, 9, 3};
	std::vector<int> b = {2, 3, 10, 7};
	bool r = betterThanExpected(a, b);
    BOOST_CHECK_EQUAL(r, true);
}

BOOST_AUTO_TEST_SUITE_END()
