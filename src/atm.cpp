
#include "atm.h"
#include <iostream>

// --- Nathan's Code: The Bank Core ---
ATM::ATM(const std::string& pin, double initialBalance)
    : correctPIN(pin),
      balance(initialBalance >= 0 ? initialBalance : 0.0)
{
    voice = std::make_unique<EnglishVoice>(); // Your voice system starts here
}

bool ATM::authenticate(const std::string& enteredPIN) const
{
    return enteredPIN == correctPIN;
}

double ATM::getBalance() const
{
    return balance;
}

bool ATM::deposit(double amount)
{
    if (amount <= 0) return false;
    balance += amount;
    transactions.push_back("Deposit: +" + std::to_string(amount));
    return true;
}

bool ATM::withdraw(double amount)
{
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    transactions.push_back("Withdrawal: -" + std::to_string(amount));
    return true;
}

void ATM::showTransactions() const
{
    if (transactions.empty()) {
        std::cout << "No transactions yet.\n";
        return;
    }
    std::cout << "\nTransaction History:\n";
    for (const std::string& transaction : transactions) {
        std::cout << transaction << '\n';
    }
}

// --- Your Code: The ATM Interface ---
void ATM::start() {
    voice->speakWelcome();
    std::cout << "\n[System]: Account loaded. (Balance: $" << getBalance() << ")\n";

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
            voice->speakBalance(getBalance()); // Now uses Nathan's balance
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
    
    // Call Nathan's deposit function!
    if (deposit(amount)) {
        std::cout << "Success! Deposited $" << amount << "\n";
        voice->speakBalance(getBalance());
    } else {
        std::cout << "Error: Invalid deposit amount.\n";
    }
}

void ATM::handleWithdraw() {
    double amount = Validator::getValidAmount("Enter withdraw amount: $");
    
    // Call Nathan's withdraw function!
    if (withdraw(amount)) {
        voice->speakWithdrawSuccess(amount);
        std::cout << "Remaining Balance: $" << getBalance() << "\n";
    } else {
        voice->speakWithdrawFail();
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
