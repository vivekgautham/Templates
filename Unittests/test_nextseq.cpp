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

BOOST_AUTO_TEST_CASE( ALMOSTINCREASING )
{
    std::vector<int> v1 = {1, 3, 2};
    auto res1 = almostIncreasingSequence(v1.begin(), v1.end());
    BOOST_CHECK_EQUAL(res1, true);

    std::vector<int> v2 = {1, 2, 2, 3};
    auto res2 = almostIncreasingSequence(v2.begin(), v2.end());
    BOOST_CHECK_EQUAL(res2, true);

    std::vector<int> v3 = {0, -2, 5, 6};
    auto res3 = almostIncreasingSequence(v3.begin(), v3.end());
    BOOST_CHECK_EQUAL(res3, true);

    std::vector<int> v4 = {1, 2, 3, 4, 99, 5, 6};
    auto res4 = almostIncreasingSequence(v4.begin(), v4.end());
    BOOST_CHECK_EQUAL(res4, true);

    std::vector<int> v5 = {1, 3, 2, 1};
    auto res5 = almostIncreasingSequence(v5.begin(), v5.end());
    BOOST_CHECK_EQUAL(res5, false);

    std::vector<int> v6 = {3, 2, 1};
    auto res6 = almostIncreasingSequence(v6.begin(), v6.end());
    BOOST_CHECK_EQUAL(res6, false);

    std::vector<int> v7 = {1, 1, 1};
    auto res7 = almostIncreasingSequence(v7.begin(), v7.end());
    BOOST_CHECK_EQUAL(res7, false);

}

BOOST_AUTO_TEST_SUITE_END()
