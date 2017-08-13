#include "../wavy_array.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(WAVY_SEQ)


BOOST_AUTO_TEST_CASE( WAVIFY )
{
    std::vector<int> v = {2, 3, 10, 4, 1, 7};
    wavify(v.begin(), v.end());
    BOOST_CHECK_EQUAL(v.size(), 6);
    BOOST_CHECK_EQUAL(v[0], 1);
    BOOST_CHECK_EQUAL(v[1], 3);
    BOOST_CHECK_EQUAL(v[2], 2);
    BOOST_CHECK_EQUAL(v[3], 7);
    BOOST_CHECK_EQUAL(v[4], 4);
    BOOST_CHECK_EQUAL(v[5], 10);

    std::vector<int> v1 = {20, 30, 10, 5, 15, 5, 10, 40, 30};
    wavify(v1.begin(), v1.end());
    BOOST_CHECK_EQUAL(v1.size(), 9);
    BOOST_CHECK_EQUAL(v1[0], 5);
    BOOST_CHECK_EQUAL(v1[1], 10);
    BOOST_CHECK_EQUAL(v1[2], 5);
    BOOST_CHECK_EQUAL(v1[3], 15);
    BOOST_CHECK_EQUAL(v1[4], 10);
    BOOST_CHECK_EQUAL(v1[5], 30);
}

BOOST_AUTO_TEST_SUITE_END()
