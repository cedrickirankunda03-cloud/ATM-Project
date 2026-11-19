#include "Transaction.h"

/**
 * @brief Creates a transaction with a specified amount.
 * @param amount The transaction amount.
 */
Transaction::Transaction(double amount)
    : amount(amount)
{
}

/**
 * @brief Creates a deposit transaction.
 * @param account The account receiving the money.
 * @param amount The amount to deposit.
 */
Deposit::Deposit(Account& account, double amount)
    : Transaction(amount), account(account)
{
}

/**
 * @brief Executes the deposit.
 * @return True if the deposit succeeds.
 */
bool Deposit::execute()
{
    return account.deposit(amount);
}

/**
 * @brief Returns the deposit description.
 * @return A description of the deposit.
 */
std::string Deposit::getDescription() const
{
    return "Deposit: +" + std::to_string(amount);
}

/**
 * @brief Creates a withdrawal transaction.
 * @param account The account from which money is withdrawn.
 * @param amount The amount to withdraw.
 */
Withdraw::Withdraw(Account& account, double amount)
    : Transaction(amount), account(account)
{
}

/**
 * @brief Executes the withdrawal.
 * @return True if the withdrawal succeeds.
 */
bool Withdraw::execute()
{
    return account.withdraw(amount);
}

/**
 * @brief Returns the withdrawal description.
 * @return A description of the withdrawal.
 */
std::string Withdraw::getDescription() const
{
    return "Withdrawal: -" + std::to_string(amount);
}

/**
 * @brief Creates a transfer transaction.
 * @param sender The account sending the money.
 * @param receiver The account receiving the money.
 * @param amount The amount to transfer.
 */
Transfer::Transfer(Account& sender, Account& receiver, double amount)
    : Transaction(amount), sender(sender), receiver(receiver)
{
}

/**
 * @brief Executes the transfer between two accounts.
 * @return True if the transfer succeeds.
 */
bool Transfer::execute()
{
    if (amount <= 0 || sender.getBalance() < amount)
    {
        return false;
    }

    if (!sender.withdraw(amount))
    {
        return false;
    }

    if (!receiver.deposit(amount))
    {
        sender.deposit(amount);
        return false;
    }

    return true;
}

/**
 * @brief Returns the transfer description.
 * @return A description of the transfer.
 */
std::string Transfer::getDescription() const
{
    return "Transfer: " + std::to_string(amount);
}