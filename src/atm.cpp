
#include "atm.h"
#include <iostream>

// Create an ATM with a PIN and starting balance
ATM::ATM(const std::string& pin, double initialBalance)
    : correctPIN(pin),
      balance(initialBalance >= 0 ? initialBalance : 0.0)
{
}

// Check whether the entered PIN is correct
bool ATM::authenticate(const std::string& enteredPIN) const
{
    return enteredPIN == correctPIN;
}

// Return the current account balance
double ATM::getBalance() const
{
    return balance;
}

// Add money to the account
bool ATM::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;
    transactions.push_back("Deposit: +" + std::to_string(amount));

    return true;
}

// Withdraw money from the account
bool ATM::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        return false;
    }

    balance -= amount;
    transactions.push_back("Withdrawal: -" + std::to_string(amount));

    return true;
}

// Display transaction history
void ATM::showTransactions() const
{
    if (transactions.empty())
    {
        std::cout << "No transactions yet.\n";
        return;
    }

    std::cout << "\nTransaction History:\n";

    for (const std::string& transaction : transactions)
    {
        std::cout << transaction << '\n';
    }
}
