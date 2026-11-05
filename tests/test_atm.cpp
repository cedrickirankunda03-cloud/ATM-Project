#include "atm.h"

#include <iostream>
#include <cassert>
#include <limits>

// Test 1: Account creation
void testAccountCreation()
{
    ATM atm("1234", 5000.0);

    assert(atm.getBalance() == 5000.0);
    assert(atm.getAccountNumber() == "10000001");
    assert(atm.getAccountType() == "Savings");
}

// Test 2: PIN authentication
void testAuthentication()
{
    ATM atm("1234", 1000.0);

    assert(atm.authenticate("1234") == true);
    assert(atm.authenticate("9999") == false);
}

// Test 3: Deposit money
void testDeposit()
{
    ATM atm("1234", 1000.0);

    assert(atm.deposit(500.0) == true);
    assert(atm.getBalance() == 1500.0);
}

// Test 4: Invalid deposits
void testInvalidDeposit()
{
    ATM atm("1234", 1000.0);

    assert(atm.deposit(0) == false);
    assert(atm.deposit(-100) == false);
    assert(atm.deposit(std::numeric_limits<double>::infinity()) == false);

    assert(atm.getBalance() == 1000.0);
}

// Test 5: Withdraw money
void testWithdraw()
{
    ATM atm("1234", 1000.0);

    assert(atm.withdraw(300.0) == true);
    assert(atm.getBalance() == 700.0);
}

// Test 6: Invalid withdrawals
void testInvalidWithdraw()
{
    ATM atm("1234", 1000.0);

    assert(atm.withdraw(0) == false);
    assert(atm.withdraw(-100) == false);
    assert(atm.withdraw(1500) == false);

    assert(atm.getBalance() == 1000.0);
}

// Test 7: Daily withdrawal limit
void testDailyWithdrawalLimit()
{
    ATM atm("1234", 5000.0);

    assert(atm.withdraw(1000.0) == true);
    assert(atm.withdraw(100.0) == false);

    assert(atm.getRemainingDailyLimit() == 0.0);

    atm.resetDailyWithdrawal();

    assert(atm.withdraw(100.0) == true);
}

// Test 8: ATM cash availability
void testATMCash()
{
    ATM atm("1234", 5000.0);

    atm.setATMCash(50.0);

    assert(atm.withdraw(100.0) == false);
    assert(atm.withdraw(50.0) == true);

    assert(atm.getATMCash() == 0.0);
}

// Test 9: Money transfer
void testTransfer()
{
    ATM sender("1234", 1000.0, "10000001");
    ATM recipient("5678", 500.0, "10000002");

    assert(sender.transfer(recipient, 200.0) == true);

    assert(sender.getBalance() == 800.0);
    assert(recipient.getBalance() == 700.0);
}

// Test 10: Invalid transfers
void testInvalidTransfer()
{
    ATM sender("1234", 1000.0);
    ATM recipient("5678", 500.0);

    assert(sender.transfer(recipient, 0) == false);
    assert(sender.transfer(recipient, -100) == false);
    assert(sender.transfer(recipient, 2000) == false);
    assert(sender.transfer(sender, 100) == false);

    assert(sender.getBalance() == 1000.0);
    assert(recipient.getBalance() == 500.0);
}

// Test 11: Change PIN
void testChangePIN()
{
    ATM atm("1234", 1000.0);

    assert(atm.changePIN("1234", "5678") == true);
    assert(atm.authenticate("5678") == true);
    assert(atm.authenticate("1234") == false);
}

// Test 12: Invalid PIN changes
void testInvalidPINChange()
{
    ATM atm("1234", 1000.0);

    assert(atm.changePIN("9999", "5678") == false);
    assert(atm.changePIN("1234", "12AB") == false);
    assert(atm.changePIN("1234", "123") == false);

    assert(atm.authenticate("1234") == true);
}

// Test 13: Account blocking
void testAccountBlocking()
{
    ATM atm("1234", 1000.0);

    assert(atm.authenticate("0000") == false);
    assert(atm.authenticate("0000") == false);
    assert(atm.authenticate("0000") == false);

    assert(atm.isAccountBlocked() == true);
    assert(atm.authenticate("1234") == false);
}

// Test 14: Account type selection
void testAccountType()
{
    ATM atm("1234", 1000.0);

    assert(atm.setAccountType("Current") == true);
    assert(atm.getAccountType() == "Current");

    assert(atm.setAccountType("Invalid") == false);
}

// Test 15: Language selection
void testLanguageSelection()
{
    ATM atm("1234", 1000.0);

    assert(atm.selectLanguage("French") == true);
    assert(atm.getLanguage() == "French");

    assert(atm.selectLanguage("English") == true);
    assert(atm.getLanguage() == "English");

    assert(atm.selectLanguage("Spanish") == false);
}
// Test 16: Amount validation
void testAmountValidation()
{
    ATM atm("1234", 1000.0);

    assert(atm.validateAmount(100.0) == true);
    assert(atm.validateAmount(0.0) == false);
    assert(atm.validateAmount(-50.0) == false);
    assert(atm.validateAmount(
        std::numeric_limits<double>::quiet_NaN()) == false);
}

// Main test function
int main()
{
    std::cout << "\n========== ATM UNIT TESTS ==========\n";

    testAccountCreation();
    testAuthentication();
    testDeposit();
    testInvalidDeposit();
    testWithdraw();
    testInvalidWithdraw();
    testDailyWithdrawalLimit();
    testATMCash();
    testTransfer();
    testInvalidTransfer();
    testChangePIN();
    testInvalidPINChange();
    testAccountBlocking();
    testAccountType();
    testLanguageSelection();
    testAmountValidation();

    std::cout << "\nAll 16 test groups passed successfully!\n";
    std::cout << "====================================\n";

    return 0;
}
