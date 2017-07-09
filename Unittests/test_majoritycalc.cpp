#include "../majority_calc.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(MAJORITY)
struct Comparator
{
  public:
    bool operator()(int a, int b)
    {
      return a==b;
    }
} compint;

BOOST_AUTO_TEST_CASE( MAJORITY_ELEM )
{
    std::vector<int> v1 = {2, 2, 1, 3, 6, 2, 2};
    std::vector<int> v2 = {1, 1, 1, 1, 3, 2};
    BOOST_CHECK_EQUAL( *(majorityElement(v1.begin(), v1.end())), 2);
    BOOST_CHECK_EQUAL( *(majorityElement(v2.begin(), v2.end(), compint, 0.6)), 1);
    BOOST_CHECK( majorityElement(v2.begin(), v2.end(), compint, 0.7) == v2.end());
}

BOOST_AUTO_TEST_SUITE_END()
