#pragma once
#include "VoiceGuidance.h"
#include "Validator.h"
#include <memory>

class ATM {
private:
    // Use std::unique_ptr (STL) to manage memory automatically
    std::unique_ptr<VoiceGuidance> voice;
    double currentBalance; // This will eventually be Nathan's Account object

    void handleWithdraw();
    void handleDeposit();
    void handleLanguageChange();

public:
    ATM();
    void start(); // This runs the main menu loop
};