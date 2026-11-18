#include <gtest/gtest.h>
#include "Validator.h"

// Your simple test to make sure the test harness works
TEST(ValidatorTest, BasicAssertions) {
    EXPECT_EQ(1, 1);
}

// Your real test
TEST(ValidatorTest, AmountMustBePositive) {
    EXPECT_TRUE(true);
}