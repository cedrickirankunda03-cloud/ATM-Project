[20:26, 29/10/2026] Ir.cedrick: #include "atm.h"
#include <iostream>
#include <limits>

int main()
{
    ATM atm("1234", 500.0);

    std::string enteredPIN;

    std::cout << "Welcome to the ATM!\n";
    std::cout << "Enter your PIN: ";
    std::cin >> enteredPIN;

    if (!atm.authenticate(enteredPIN))
    {
        std::cout << "Incorrect PIN. Access denied.\n";
        return 0;
    }

    std::cout << "Login successful!\n";

    int choice = 0;

    do
    {
        std::cout << "\n===== ATM MENU =====\n";
        std::cout << "1. Check balance\n";
        std::cout << "2. Deposit money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. Transaction history\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> …
[20:33, 29/10/2026] Ir.cedrick: #include <gtest/gtest.h>
#include "atm.h"

// Create a fresh ATM before each test
class ATMTest : public ::testing::Test
{
protected:
    ATM atm{"1234", 500.0};
};

// Test correct PIN
TEST_F(ATMTest, AcceptsCorrectPIN)
{
    EXPECT_TRUE(atm.authenticate("1234"));
}

// Test incorrect PIN
TEST_F(ATMTest, RejectsIncorrectPIN)
{
    EXPECT_FALSE(atm.authenticate("9999"));
}

// Test initial balance
TEST_F(ATMTest, HasCorrectInitialBalance)
{
    EXPECT_DOUBLE_EQ(atm.getBalance(), 500.0);
}

// Test successful deposit
TEST_F(ATMTest, DepositsMoney)
{
    EXPECT_TRUE(atm.deposit(100.0));
    EXPECT_DOUBLE_EQ(atm.getBalance(), 600.0);
}

// Test invalid deposit
TEST_F(ATMTest, RejectsInvalidDeposit)
{
    EXPECT_FALSE(atm.deposit(0.0));
    EXPECT_DOUBLE_EQ(atm.getBalance(), 500.0);
}

// Test successful withdrawal
TEST_F(ATMTest, WithdrawsMoney)
{
    EXPECT_TRUE(atm.withdraw(150.0));
    EXPECT_DOUBLE_EQ(atm.getBalance(), 350.0);
}

// Test withdrawal exceeding balance
TEST_F(ATMTest, RejectsWithdrawalAboveBalance)
{
    EXPECT_FALSE(atm.withdraw(600.0));
    EXPECT_DOUBLE_EQ(atm.getBalance(), 500.0);
}

// Test negative withdrawal
TEST_F(ATMTest, RejectsNegativeWithdrawal)
{
    EXPECT_FALSE(atm.withdraw(-50.0));
    EXPECT_DOUBLE_EQ(atm.getBalance(), 500.0);
}

// Test empty transaction history
TEST(ATMHistoryTest, EmptyHistoryDoesNotCrash)
{
    ATM atm{"1234", 500.0};
    EXPECT_NO_THROW(atm.showTransactions());
}
