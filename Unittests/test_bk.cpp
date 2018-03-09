#include "../src/bk.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(BKTREE)

BOOST_AUTO_TEST_CASE(BKADD)
{
    std::vector<std::string> words = {"book", "books", "cake", "boo", "cape", "Boon", "Cook", "Cart"};
    BK tree;
    for (unsigned int i=0; i<words.size(); i++)
        tree.add(words[i]);

    tree.displayTree();

    std::vector<std::string> result = tree.search("coop", 1);

    BOOST_CHECK_EQUAL(result.size(), (unsigned int)1);
    BOOST_CHECK_EQUAL(result[0], std::string("cook"));

    std::vector<std::string> result1 = tree.search("boop", 1);

    BOOST_CHECK_EQUAL(result1.size(), (unsigned int)3);
    BOOST_CHECK_EQUAL(result1[0], std::string("book"));
    BOOST_CHECK_EQUAL(result1[1], std::string("boo"));
    BOOST_CHECK_EQUAL(result1[2], std::string("boon"));

    std::vector<std::string> result2 = tree.search("caqe", 1);

    BOOST_CHECK_EQUAL(result2.size(), (unsigned int)2);
    BOOST_CHECK_EQUAL(result2[0], std::string("cake"));
    BOOST_CHECK_EQUAL(result2[1], std::string("cape"));
}

BOOST_AUTO_TEST_SUITE_END()