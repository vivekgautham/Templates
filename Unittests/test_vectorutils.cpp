#include "../src/utils/vector_utils.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(VECTOR_UTILS)

BOOST_AUTO_TEST_CASE( TRIMVECTOR )
{
    std::vector<size_t> v;
    for (size_t i=0; i<10; i++) {
        v.push_back(i);
    }        
    

    BOOST_CHECK_EQUAL( v.size(), 10 );
    BOOST_CHECK_EQUAL( v.capacity(), 16 );

    trimVector<size_t> (v);
    
    BOOST_CHECK_EQUAL( v.size(), 10 );
    BOOST_CHECK_EQUAL( v.capacity(), 10 );


}

BOOST_AUTO_TEST_SUITE_END()