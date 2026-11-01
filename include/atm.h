
#ifndef ATM_H
#define ATM_H

#include <string>
#include <vector>

class ATM
{
private:
    std::string correctPIN;
    double balance;
    std::vector<std::string> transactions;

public:
    // Constructor
    ATM(const std::string& pin, double initialBalance);

    // PIN authentication
    bool authenticate(const std::string& enteredPIN) const;

    // Check balance
    double getBalance() const;

    // Deposit and withdraw
    bool deposit(double amount);
    bool withdraw(double amount);

    // Display transaction history
    void showTransactions() const;
};

#endif
