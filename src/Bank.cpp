#include "Bank.h"
#include <algorithm>

/**
 * @brief Adds a new account to the bank.
 * @param account The account to add.
 * @return True if the account is added successfully.
 */
bool Bank::addAccount(const Account& account)
{
    const std::string number = account.getAccountNumber();

    if (accounts.find(number) != accounts.end())
    {
        return false;
    }

    accounts.emplace(number, account);
    return true;
}

/**
 * @brief Finds an account by its number.
 * @param accountNumber The account number.
 * @return A pointer to the account, or nullptr if not found.
 */
Account* Bank::findAccount(const std::string& accountNumber)
{
    auto it = accounts.find(accountNumber);

    if (it == accounts.end())
    {
        return nullptr;
    }

    return &it->second;
}

/**
 * @brief Deposits money into an account.
 * @param accountNumber The account number.
 * @param amount The amount to deposit.
 * @return True if the deposit succeeds.
 */
bool Bank::deposit(const std::string& accountNumber, double amount)
{
    Account* account = findAccount(accountNumber);

    if (account == nullptr)
    {
        return false;
    }

    Deposit transaction(*account, amount);

    if (!transaction.execute())
    {
        return false;
    }

    transactionHistory.push_back(transaction.getDescription());
    return true;
}

/**
 * @brief Withdraws money from an account.
 * @param accountNumber The account number.
 * @param amount The amount to withdraw.
 * @return True if the withdrawal succeeds.
 */
bool Bank::withdraw(const std::string& accountNumber, double amount)
{
    Account* account = findAccount(accountNumber);

    if (account == nullptr)
    {
        return false;
    }

    Withdraw transaction(*account, amount);

    if (!transaction.execute())
    {
        return false;
    }

    transactionHistory.push_back(transaction.getDescription());
    return true;
}

/**
 * @brief Transfers money between two accounts.
 * @param senderNumber The sender's account number.
 * @param receiverNumber The receiver's account number.
 * @param amount The amount to transfer.
 * @return True if the transfer succeeds.
 */
bool Bank::transfer(const std::string& senderNumber,
    const std::string& receiverNumber,
    double amount)
{
    Account* sender = findAccount(senderNumber);
    Account* receiver = findAccount(receiverNumber);

    if (sender == nullptr || receiver == nullptr || sender == receiver)
    {
        return false;
    }

    Transfer transaction(*sender, *receiver, amount);

    if (!transaction.execute())
    {
        return false;
    }

    transactionHistory.push_back(transaction.getDescription());
    return true;
}

/**
 * @brief Returns the complete transaction history.
 * @return A vector containing all transactions.
 */
std::vector<std::string> Bank::getTransactionHistory() const
{
    return transactionHistory;
}

/**
 * @brief Returns the five most recent transactions.
 * @return A vector containing the latest transactions.
 */
std::vector<std::string> Bank::getMiniStatement() const
{
    std::vector<std::string> statement;

    size_t start = transactionHistory.size() > 5
        ? transactionHistory.size() - 5
        : 0;

    for (size_t i = start; i < transactionHistory.size(); ++i)
    {
        statement.push_back(transactionHistory[i]);
    }

    return statement;
}