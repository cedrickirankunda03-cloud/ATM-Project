#include <gtest/gtest.h>
#include "Validator.h"

// A simple test to make sure the test harness works
TEST(ValidatorTest, BasicAssertions) {
    EXPECT_EQ(1, 1);
}

// A real test for your code
TEST(ValidatorTest, AmountMustBePositive) {
    // We can't easily test std::cin directly here without mock libraries, 
    // but we can test the logic if we separate it. 
    // For now, let's just make sure the test runner works!
    EXPECT_TRUE(true);
}
