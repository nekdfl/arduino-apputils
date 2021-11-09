#include "test_apputils.hpp"

/**
 * @brief Set the Up object
 * 
 */
void setUp(void)
{
}

/**
 * @brief clear ram
 * 
 */
void tearDown(void)
{
}

void test_crc16_string_CCITT()
{
    const unsigned int expected = 10673;
    String mystr = "123456789";
    auto crc16 = crc16_CCITT(mystr);
    TEST_ASSERT_EQUAL(expected, crc16);

    //Verify result on https://crccalc.com/
}

void test_crc16_CCITT()
{
    const unsigned int expected = 10673;
    const char *mystr = "123456789";
    auto crc16 = crc16_CCITT((unsigned char *)mystr, strlen(mystr));
    TEST_ASSERT_EQUAL(expected, crc16);

    //Verify result on https://crccalc.com/
}

void test_splitstring()
{
    bool pass = true;
    String instr = "path/key";
    std::list<String> expectedlist = {"path", "key"};
    auto reslist = splitPath(instr, "/");
    if (expectedlist.size() != reslist.size())
    {

        TEST_ASSERT_EQUAL(true, false);
        return;
    }

    String exp;
    String res;

    while (!expectedlist.empty())
    {
        exp = expectedlist.front();
        res = reslist.front();
        expectedlist.pop_front();
        reslist.pop_front();
        if (exp != res)
        {
            pass = false;
            break;
        }
    }

    TEST_ASSERT_EQUAL(true, pass);
}

void dummy_test()
{
    TEST_ASSERT_EQUAL(0, 0);
}

void test_apputils()
{
    RUN_TEST(test_splitstring);
    RUN_TEST(test_crc16_string_CCITT);
    RUN_TEST(test_crc16_CCITT);

    //last test not display. Add dummy test.
    RUN_TEST(dummy_test);
    RUN_TEST(dummy_test);
    RUN_TEST(dummy_test);
}