#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"
#include <string>

/**
 * @brief Abstract base class for bank transactions.
 */
class Transaction
{
protected:
    double amount;

public:
    /**
     * @brief Creates a transaction.
     * @param amount The transaction amount.
     */
    Transaction(double amount);

    virtual ~Transaction() = default;

    /**
     * @brief Executes the transaction.
     * @return True if the transaction succeeds.
     */
    virtual bool execute() = 0;

    /**
     * @brief Returns the transaction description.
     * @return A text describing the transaction.
     */
    virtual std::string getDescription() const = 0;
};

/**
 * @brief Represents a deposit transaction.
 */
class Deposit : public Transaction
{
private:
    Account& account;

public:
    /**
     * @brief Creates a deposit transaction.
     * @param account The account receiving the money.
     * @param amount The amount to deposit.
     */
    Deposit(Account& account, double amount);

    bool execute() override;
    std::string getDescription() const override;
};

/**
 * @brief Represents a withdrawal transaction.
 */
class Withdraw : public Transaction
{
private:
    Account& account;

public:
    /**
     * @brief Creates a withdrawal transaction.
     * @param account The account from which money is withdrawn.
     * @param amount The amount to withdraw.
     */
    Withdraw(Account& account, double amount);

    bool execute() override;
    std::string getDescription() const override;
};

/**
 * @brief Represents a transfer between two accounts.
 */
class Transfer : public Transaction
{
private:
    Account& sender;
    Account& receiver;

public:
    /**
     * @brief Creates a transfer transaction.
     * @param sender The account sending the money.
     * @param receiver The account receiving the money.
     * @param amount The amount to transfer.
     */
    Transfer(Account& sender, Account& receiver, double amount);

    bool execute() override;
    std::string getDescription() const override;
};

#endif