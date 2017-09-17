#include "../wavy_array.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(WAVY_SEQ)


BOOST_AUTO_TEST_CASE( WAVIFY )
{

    std::vector<int> v0 = {10, 90, 49, 2, 1, 5, 23};
    wavify(v0.begin(), v0.end());
    BOOST_CHECK_EQUAL(v0.size(), 7);
    BOOST_CHECK_EQUAL(v0[0], 90);
    BOOST_CHECK_EQUAL(v0[1], 10);
    BOOST_CHECK_EQUAL(v0[2], 49);
    BOOST_CHECK_EQUAL(v0[3], 1);
    BOOST_CHECK_EQUAL(v0[4], 5);
    BOOST_CHECK_EQUAL(v0[5], 2);
    BOOST_CHECK_EQUAL(v0[6], 23);

    std::vector<int> v = {2, 3, 10, 4, 1, 7};
    wavify(v.begin(), v.end());
    BOOST_CHECK_EQUAL(v.size(), 6);
    BOOST_CHECK_EQUAL(v[0], 3);
    BOOST_CHECK_EQUAL(v[1], 2);
    BOOST_CHECK_EQUAL(v[2], 10);
    BOOST_CHECK_EQUAL(v[3], 1);
    BOOST_CHECK_EQUAL(v[4], 7);
    BOOST_CHECK_EQUAL(v[5], 4);

    std::vector<int> v1 = {20, 30, 10, 5, 15, 5, 10, 40, 30};
    wavify(v1.begin(), v1.end());
    BOOST_CHECK_EQUAL(v1.size(), 9);
    BOOST_CHECK_EQUAL(v1[0], 30);
    BOOST_CHECK_EQUAL(v1[1], 10);
    BOOST_CHECK_EQUAL(v1[2], 20);
    BOOST_CHECK_EQUAL(v1[3], 5);
    BOOST_CHECK_EQUAL(v1[4], 15);
    BOOST_CHECK_EQUAL(v1[5], 5);
    BOOST_CHECK_EQUAL(v1[6], 40);
    BOOST_CHECK_EQUAL(v1[7], 10);
    BOOST_CHECK_EQUAL(v1[8], 30);
}

BOOST_AUTO_TEST_SUITE_END()
