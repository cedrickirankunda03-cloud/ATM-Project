#ifndef ATM_H
#define ATM_H

#include <string>
#include <vector>
#include <memory>
#include "VoiceGuidance.h"
#include "Validator.h"

class ATM
{
private:
    std::string correctPIN;
    double balance;
    std::vector<std::string> transactions;
    
    // Cedrick's Voice System
    std::unique_ptr<VoiceGuidance> voice;

    // Cedrick's Menu Helpers
    void handleDeposit();
    void handleWithdraw();
    void handleLanguageChange();

public:
    // Constructor (Nathan's parameters + Cedrick's voice setup)
    ATM(const std::string& pin, double initialBalance);

    // Cedrick's Main Loop
    void start();

    // Nathan's Bank Core
    bool authenticate(const std::string& enteredPIN) const;
    double getBalance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
    void showTransactions() const;
};

#endif