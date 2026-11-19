#include <gtest/gtest.h>
#include "Account.h"

TEST(AccountTest, AccountCreation)
{
    Account account("1001", "Nathan", 500.0, AccountType::Savings);

    EXPECT_EQ(account.getAccountNumber(), "1001");
    EXPECT_EQ(account.getOwnerName(), "Nathan");
    EXPECT_EQ(account.getBalance(), 500.0);
    EXPECT_EQ(account.getType(), AccountType::Savings);
}

TEST(AccountTest, Deposit)
{
    Account account("1001", "Nathan", 500.0, AccountType::Savings);

    EXPECT_TRUE(account.deposit(200.0));
    EXPECT_EQ(account.getBalance(), 700.0);
}

TEST(AccountTest, InvalidDeposit)
{
    Account account("1001", "Nathan", 500.0, AccountType::Savings);

    EXPECT_FALSE(account.deposit(0));
    EXPECT_FALSE(account.deposit(-100.0));
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(AccountTest, Withdraw)
{
    Account account("1001", "Nathan", 500.0, AccountType::Current);

    EXPECT_TRUE(account.withdraw(200.0));
    EXPECT_EQ(account.getBalance(), 300.0);
}

TEST(AccountTest, InvalidWithdraw)
{
    Account account("1001", "Nathan", 500.0, AccountType::Current);

    EXPECT_FALSE(account.withdraw(0));
    EXPECT_FALSE(account.withdraw(-100.0));
    EXPECT_FALSE(account.withdraw(600.0));
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(AccountTest, NegativeInitialBalance)
{
    Account account("1001", "Nathan", -100.0, AccountType::Savings);

    EXPECT_EQ(account.getBalance(), 0.0);
}