#include "../dputils.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(DP_UTILS)

BOOST_AUTO_TEST_CASE(LONGEST_SUBSEQ)
{
    size_t res;
    std::vector<int> v = {3, 10, 2, 1, 20};
    res = DP::longestSubsequence(v.begin(), v.end());
    BOOST_CHECK_EQUAL(res, 3);

    std::vector<int> v2 = {3, 2};
    res = DP::longestSubsequence(v2.begin(), v2.end());
    BOOST_CHECK_EQUAL(res, 1);

    std::vector<int> v1 = {50, 3, 10, 7, 40, 80};
    res = DP::longestSubsequence(v1.begin(), v1.end());
    BOOST_CHECK_EQUAL(res, 4);

}

BOOST_AUTO_TEST_SUITE_END()
