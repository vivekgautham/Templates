#include "../src/pairing.h"
#include "../src/functors.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(PAIRING)

BOOST_AUTO_TEST_CASE( ForEachAdjPair )
{
    std::vector<int> p = {1,2,3,4,5,6};
    CountConsecutive<int> c(0);
    CountConsecutive<int> res = for_each_adjpair(p.begin(), p.end(), c);
    BOOST_CHECK_EQUAL(res.getCount(), unsigned (5));

    std::vector<int> p1 = {1,2};
    CountConsecutive<int> res1 = for_each_adjpair(p1.cbegin(), p1.cend(), c);
    BOOST_CHECK_EQUAL(res1.getCount(), unsigned (1));

    std::vector<int> p2 = {1};
    CountConsecutive<int> res2 = for_each_adjpair(p2.cbegin(), p2.cend(), c);
    BOOST_CHECK_EQUAL(res2.getCount(), unsigned (0));
}


BOOST_AUTO_TEST_CASE( ForEachALLPairs )
{
    std::vector<int> p = {1,2,3,4,5,6};
    SumProduct<int> c(0);
    SumProduct<int> res = for_all_pairs(p.begin(), p.end(), c);
    BOOST_CHECK_EQUAL(res.getSumProd(), unsigned (175));

    std::vector<int> p1 = {1, 2, 3};
    SumProduct<int> res1 = for_all_pairs(p1.cbegin(), p1.cend(), c);
    BOOST_CHECK_EQUAL(res1.getSumProd(), unsigned (11));

    std::vector<int> p2 = {1};
    SumProduct<int> res2 = for_all_pairs(p2.cbegin(), p2.cend(), c);
    BOOST_CHECK_EQUAL(res2.getSumProd(), unsigned (0));
}

BOOST_AUTO_TEST_SUITE_END()