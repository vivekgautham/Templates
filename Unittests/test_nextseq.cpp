#include "../next_sequence.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(NEXT_SEQ)

BOOST_AUTO_TEST_CASE( SORTEDUNTIL )
{
    std::vector<int> v = {2, 3, 5, 4, 1};

    BOOST_CHECK_EQUAL( *(sortedUntil(v.begin(), v.end())), 4);
    BOOST_CHECK_EQUAL( *(sortedUntil(v.rbegin(), v.rend())), 3);
}

BOOST_AUTO_TEST_CASE( NEXTSEQUENCE )
{
    std::vector<int> v = {2, 3, 5, 4, 1};
    auto res = nextSequence(v.begin(), v.end());
    BOOST_CHECK_EQUAL(res, true);
    BOOST_CHECK_EQUAL(v.size(), 5);
    BOOST_CHECK_EQUAL(v[0], 2);
    BOOST_CHECK_EQUAL(v[1], 4);
    BOOST_CHECK_EQUAL(v[2], 1);
    BOOST_CHECK_EQUAL(v[3], 3);
    BOOST_CHECK_EQUAL(v[4], 5);
}

BOOST_AUTO_TEST_SUITE_END()
