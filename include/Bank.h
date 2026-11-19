#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Transaction.h"
#include <map>
#include <vector>
#include <string>

/**
 * @brief Manages bank accounts and transactions.
 */
class Bank
{
private:
    std::map<std::string, Account> accounts;
    std::vector<std::string> transactionHistory;

public:
    /**
     * @brief Adds a new account to the bank.
     * @param account The account to add.
     * @return True if the account is added successfully.
     */
    bool addAccount(const Account& account);

    /**
     * @brief Finds an account by its number.
     * @param accountNumber The account number.
     * @return A pointer to the account, or nullptr if not found.
     */
    Account* findAccount(const std::string& accountNumber);

    /**
     * @brief Deposits money into an account.
     * @param accountNumber The account number.
     * @param amount The amount to deposit.
     * @return True if the deposit succeeds.
     */
    bool deposit(const std::string& accountNumber, double amount);

    /**
     * @brief Withdraws money from an account.
     * @param accountNumber The account number.
     * @param amount The amount to withdraw.
     * @return True if the withdrawal succeeds.
     */
    bool withdraw(const std::string& accountNumber, double amount);

    /**
     * @brief Transfers money between two accounts.
     * @param senderNumber The sender's account number.
     * @param receiverNumber The receiver's account number.
     * @param amount The amount to transfer.
     * @return True if the transfer succeeds.
     */
    bool transfer(const std::string& senderNumber,
        const std::string& receiverNumber,
        double amount);

    /**
     * @brief Returns the complete transaction history.
     */
    std::vector<std::string> getTransactionHistory() const;

    /**
     * @brief Returns the five most recent transactions.
     */
    std::vector<std::string> getMiniStatement() const;
};

#endif