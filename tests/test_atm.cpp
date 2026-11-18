#include <gtest/gtest.h>
#include "atm.h"

// Test 1: Account creation
TEST(ATMTest, AccountCreation) {
    ATM atm("1234", 5000.0);
    EXPECT_EQ(atm.getBalance(), 5000.0);
}

// Test 2: PIN authentication
TEST(ATMTest, Authentication) {
    ATM atm("1234", 1000.0);
    EXPECT_TRUE(atm.authenticate("1234"));
    EXPECT_FALSE(atm.authenticate("9999"));
}

// Test 3: Deposit money
TEST(ATMTest, Deposit) {
    ATM atm("1234", 1000.0);
    EXPECT_TRUE(atm.deposit(500.0));
    EXPECT_EQ(atm.getBalance(), 1500.0);
}

// Test 4: Invalid deposits
TEST(ATMTest, InvalidDeposit) {
    ATM atm("1234", 1000.0);
    EXPECT_FALSE(atm.deposit(0));
    EXPECT_FALSE(atm.deposit(-100));
    EXPECT_EQ(atm.getBalance(), 1000.0);
}

// Test 5: Withdraw money
TEST(ATMTest, Withdraw) {
    ATM atm("1234", 1000.0);
    EXPECT_TRUE(atm.withdraw(300.0));
    EXPECT_EQ(atm.getBalance(), 700.0);
}

// Test 6: Invalid withdrawals
TEST(ATMTest, InvalidWithdraw) {
    ATM atm("1234", 1000.0);
    EXPECT_FALSE(atm.withdraw(0));
    EXPECT_FALSE(atm.withdraw(-100));
    EXPECT_FALSE(atm.withdraw(1500));
    EXPECT_EQ(atm.getBalance(), 1000.0);
}