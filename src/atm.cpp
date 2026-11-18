#include "atm.h"
#include <iostream>

ATM::ATM() {
    voice = std::make_unique<EnglishVoice>();
    currentBalance = 500.0; // Temporary fake balance
}

void ATM::start() {
    voice->speakWelcome();
    std::cout << "\n[System]: Account loaded: Cedrick (Balance: $" << currentBalance << ")\n";

    bool sessionActive = true;

    while (sessionActive) {
        std::cout << "\n==============================\n";
        std::cout << "          ATM MENU            \n";
        std::cout << "==============================\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Change Language (English/French)\n";
        std::cout << "5. Exit\n";

        int choice = Validator::getValidInt("Enter choice: ", 1, 5);

        if (choice == 1) {
            voice->speakBalance(currentBalance);
        } 
        else if (choice == 2) {
            handleDeposit();
        } 
        else if (choice == 3) {
            handleWithdraw();
        } 
        else if (choice == 4) {
            handleLanguageChange();
        } 
        else if (choice == 5) {
            sessionActive = false;
        }
    }

    // Card Removal Reminder (FR17)
    std::cout << "\n[System]: Please take your bank card.\n";
    Validator::getValidInt("Press 1 to confirm you have taken your card: ", 1, 1);
    voice->speakGoodbye();
}

void ATM::handleDeposit() {
    double amount = Validator::getValidAmount("Enter deposit amount: $");
    // Later: account.deposit(amount);
    currentBalance += amount;
    std::cout << "Success! Deposited $" << amount << "\n";
    voice->speakBalance(currentBalance);
}

void ATM::handleWithdraw() {
    double amount = Validator::getValidAmount("Enter withdraw amount: $");
    // Later: if (account.withdraw(amount)) ...
    if (amount > currentBalance) {
        voice->speakWithdrawFail();
    } else {
        currentBalance -= amount;
        voice->speakWithdrawSuccess(amount);
        std::cout << "Remaining Balance: $" << currentBalance << "\n";
    }
}

void ATM::handleLanguageChange() {
    std::cout << "1. English\n2. French\n";
    int lang = Validator::getValidInt("Select language: ", 1, 2);
    
    if (lang == 1) {
        voice = std::make_unique<EnglishVoice>();
    } else {
        voice = std::make_unique<FrenchVoice>();
    }
    voice->speakWelcome();
}