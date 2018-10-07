#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class test_K2d_tree : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(test_K2d_tree);

    CPPUNIT_TEST(test_param_constr_case1);

    CPPUNIT_TEST_SUITE_END();

public:

    void test_param_constr_case1();
    
};

CPPUNIT_TEST_SUITE_REGISTRATION( test_K2d_tree );