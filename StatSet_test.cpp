/**
 * An unit testing example using the boost unit test framework
 *
 * @see https://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/utf/testing-tools/reference.html
 */
#include "StatSet.h"

#define BOOST_TEST_MODULE PacketHashTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

//  floating-point numbers differing by less than this percent will be
//  considered equal
static const double epsilon = 0.001;

BOOST_AUTO_TEST_CASE( StatSet_basic )
{
    StatSet<int> ss;

    //  Size should be zero
    BOOST_CHECK_EQUAL(0, ss.size());
}

BOOST_AUTO_TEST_CASE( StatSet_AM_throw )
{
    StatSet<int> ss;

    //  getArithmeticMean should throw a runtime_error exception if called
    //  when the set is empty
    BOOST_CHECK_THROW(ss.getArithmeticMean(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE( StatSet_AM_int )
{
    StatSet<int> ss;

    //  Simple arithmetic mean test with int
    ss.addSample(1);
    ss.addSample(100);

    BOOST_CHECK_EQUAL(50, ss.getArithmeticMean());
}

BOOST_AUTO_TEST_CASE( StatSet_AM_float )
{
    StatSet<float> ss;

    //  Simple arithmetic mean test with float
    ss.addSample(1);
    ss.addSample(2);

    BOOST_CHECK_CLOSE(1.5, ss.getArithmeticMean(), epsilon);
}

BOOST_AUTO_TEST_CASE( StatSet_AM_unsigned_long_long )
{
    StatSet<unsigned long long> ss;

    //  Simple arithmetic mean test with unsigned long long
    ss.addSample(1ULL);
    ss.addSample(ULLONG_MAX);

    BOOST_CHECK_EQUAL(ULLONG_MAX / 2, ss.getArithmeticMean());
}

BOOST_AUTO_TEST_CASE( StatSet_Median_float_even )
{
    StatSet<float> ss;

    //  Median test with even number of floats
    ss.addSample(1.0);
    ss.addSample(2.0);
    ss.addSample(3.0);
    ss.addSample(4.0);

    BOOST_CHECK_CLOSE(2.5, ss.getMedian(), epsilon);
}

BOOST_AUTO_TEST_CASE( StatSet_Median_float_odd )
{
    StatSet<float> ss;

    //  Median test with odd number of floats
    ss.addSample(1.0);
    ss.addSample(2.0);
    ss.addSample(3.0);
    ss.addSample(4.0);
    ss.addSample(5.0);

    BOOST_CHECK_CLOSE(3.0, ss.getMedian(), epsilon);
}

BOOST_AUTO_TEST_CASE( StatSet_Median_int_even )
{
    StatSet<int> ss;

    //  Median test with even number of ints
    ss.addSample(1);
    ss.addSample(2);
    ss.addSample(3);
    ss.addSample(4);

    BOOST_CHECK_CLOSE(2.5, ss.getMedian(), epsilon);
}

BOOST_AUTO_TEST_CASE( StatSet_Median_int_odd )
{
    StatSet<int> ss;

    //  Median test with odd number of ints
    ss.addSample(1);
    ss.addSample(2);
    ss.addSample(3);
    ss.addSample(4);
    ss.addSample(5);

    BOOST_CHECK_CLOSE(3.0, ss.getMedian(), epsilon);
}

BOOST_AUTO_TEST_CASE( StatSet_Mode_uniform )
{
    StatSet<int> ss;

    //  Mode test with a set having a uniform distribution
    ss.addSample(1);
    ss.addSample(2);
    ss.addSample(3);
    ss.addSample(4);
    ss.addSample(5);

    BOOST_CHECK_EQUAL(1, ss.getMode());
}

BOOST_AUTO_TEST_CASE( StatSet_Mode_nonuniform )
{
    StatSet<int> ss;

    //  Mode test with a set having a non-uniform distribution
    ss.addSample(1);
    ss.addSample(2);
    ss.addSample(3);
    ss.addSample(3);
    ss.addSample(4);
    ss.addSample(5);

    BOOST_CHECK_EQUAL(3, ss.getMode());
}

