#ifndef ATM_H
#define ATM_H

#include<string>
include<vector>

class ATM
{
private:
std:string correctPIN;
double balance;
std::vector<std::string>transactions;

public:
// Constructor
ATM(const std:string& pin, double initiaBalance);

// PIN authentication
bool authenticate(const;
std::string& enteredPIN) const;

//Check balance
double getBalance() const;

// Deposit and withdrawl
bool deposit(double amount);
bool withdraw(double amount);

// Display transacton history
void showTransactions() const;
};
#endif


