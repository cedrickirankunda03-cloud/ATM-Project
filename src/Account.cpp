#include "Account.h"

/**
 * @brief Creates a new bank account.
 * @param accountNumber The account number.
 * @param ownerName The account owner's name.
 * @param initialBalance The initial account balance.
 * @param type The type of account.
 */
Account::Account(const std::string& accountNumber,
    const std::string& ownerName,
    double initialBalance,
    AccountType type)
    : accountNumber(accountNumber),
    ownerName(ownerName),
    balance(initialBalance >= 0 ? initialBalance : 0.0),
    type(type)
{
}

/**
 * @brief Returns the account number.
 */
std::string Account::getAccountNumber() const
{
    return accountNumber;
}

/**
 * @brief Returns the account owner's name.
 */
std::string Account::getOwnerName() const
{
    return ownerName;
}

/**
 * @brief Returns the current account balance.
 */
double Account::getBalance() const
{
    return balance;
}

/**
 * @brief Returns the account type.
 */
AccountType Account::getType() const
{
    return type;
}

/**
 * @brief Deposits money into the account.
 * @param amount The amount to deposit.
 * @return True if the deposit succeeds, false otherwise.
 */
bool Account::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;
    return true;
}

/**
 * @brief Withdraws money from the account.
 * @param amount The amount to withdraw.
 * @return True if the withdrawal succeeds, false otherwise.
 */
bool Account::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        return false;
    }

    balance -= amount;
    return true;
}