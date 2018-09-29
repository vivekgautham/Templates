#include "../src/fenwick_tree.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(FENWICK)

BOOST_AUTO_TEST_CASE( FENWICK_TEST )
{
    Fenwick<int> f(8);

    f.update(1, 1);
    f.update(2, 2);
    f.update(3, 3);
    f.update(4, 4);
    f.update(5, 5);
    f.update(6, 6);
    f.update(7, 7);
    f.update(8, 8);

    BOOST_CHECK_EQUAL( f.rangeSum(3), 6);
    BOOST_CHECK_EQUAL( f.rangeSum(4), 10);
    BOOST_CHECK_EQUAL( f.rangeSum(7), 28);
    BOOST_CHECK_EQUAL( f.rangeSum(8), 36);

    Fenwick<int> f1(5);

    f1.update(1, 2);
    f1.update(2, 3);
    f1.update(3, -1);
    f1.update(4, 0);
    f1.update(5, 6);

    BOOST_CHECK_EQUAL( f1.rangeSum(1), 2);
    BOOST_CHECK_EQUAL( f1.rangeSum(2), 5);
    BOOST_CHECK_EQUAL( f1.rangeSum(3), 4);
    BOOST_CHECK_EQUAL( f1.rangeSum(4), 4);
    BOOST_CHECK_EQUAL( f1.rangeSum(5), 10);
}

BOOST_AUTO_TEST_SUITE_END()
