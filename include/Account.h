#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

/**
 * @brief Defines the available bank account types.
 */
enum class AccountType {
    Savings,
    Current
};

/**
 * @brief Represents a bank account.
 */
class Account {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    AccountType type;

public:
    /**
     * @brief Creates a new bank account.
     * @param accountNumber The account number.
     * @param ownerName The account owner's name.
     * @param initialBalance The initial account balance.
     * @param type The type of account.
     */
    Account(const std::string& accountNumber,
        const std::string& ownerName,
        double initialBalance,
        AccountType type);

    /** @brief Returns the account number. */
    std::string getAccountNumber() const;

    /** @brief Returns the owner's name. */
    std::string getOwnerName() const;

    /** @brief Returns the current balance. */
    double getBalance() const;

    /** @brief Returns the account type. */
    AccountType getType() const;

    /**
     * @brief Deposits money into the account.
     * @param amount The amount to deposit.
     * @return True if the deposit succeeds, false otherwise.
     */
    bool deposit(double amount);

    /**
     * @brief Withdraws money from the account.
     * @param amount The amount to withdraw.
     * @return True if the withdrawal succeeds, false otherwise.
     */
    bool withdraw(double amount);
};

#endif