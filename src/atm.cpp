#include "atm.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <cstdlib>

// Helper function: format money to two decimal places
namespace
{
    std::string formatMoney(double amount)
    {
        std::ostringstream output;
        output << std::fixed << std::setprecision(2) << amount;
        return output.str();
    }

    std::string accountName(AccountType type)
    {
        return type == AccountType::Savings
            ? "Savings"
            : "Current";
    }

    bool isValidPIN(const std::string& pin)
    {
        return pin.size() == 4 &&
            std::all_of(pin.begin(), pin.end(),
                [](unsigned char character)
                {
                    return std::isdigit(character) != 0;
                });
    }

    bool isNewDay(std::time_t previousDate)
{
    std::time_t currentDate = std::time(nullptr);

    std::tm previous = *std::localtime(&previousDate);
    std::tm current = *std::localtime(&currentDate);

    return previous.tm_year != current.tm_year ||
           previous.tm_yday != current.tm_yday;
}

std::string formatDateTime(std::time_t transactionTime)
{
    std::tm* timeInfo = std::localtime(&transactionTime);

    if (timeInfo == nullptr)
    {
        return "Date unavailable";
    }

    std::ostringstream output;

    output << std::put_time(timeInfo, "%Y-%m-%d %H:%M:%S");

    return output.str();
}
}

// Constructor
ATM::ATM(const std::string& pin, double initialBalance)
    : correctPIN(pin),
      savingsAccountNumber("SAV-1001"),
      currentAccountNumber("CUR-1001"),
      savingsBalance(std::isfinite(initialBalance) &&
                     initialBalance >= 0
                         ? initialBalance : 0.0),
      currentBalance(0.0),
      selectedAccount(AccountType::Savings),
      failedPINAttempts(0),
      accountLocked(false),
      dailyWithdrawn(0.0),
      lastWithdrawalDate(std::time(nullptr))
{
}

void ATM::checkDailyWithdrawalReset()
{
    if (isNewDay(lastWithdrawalDate))
    {
        dailyWithdrawn = 0.0;
        lastWithdrawalDate = std::time(nullptr);
    }
}

// PIN authentication
bool ATM::authenticate(const std::string& enteredPIN)
{
    if (accountLocked)
    {
        return false;
    }

    if (enteredPIN == correctPIN)
    {
        failedPINAttempts = 0;
        return true;
    }

    ++failedPINAttempts;

    if (failedPINAttempts >= MAX_PIN_ATTEMPTS)
    {
        accountLocked = true;
    }

    return false;
}

// Check whether the account is locked
bool ATM::isLocked() const
{
    return accountLocked;
}

// Get remaining PIN attempts
int ATM::getPINAttemptsRemaining() const
{
    if (accountLocked)
    {
        return 0;
    }

    return MAX_PIN_ATTEMPTS - failedPINAttempts;
}

// Change customer PIN
bool ATM::changePIN(
    const std::string& oldPIN,
    const std::string& newPIN)
{
    if (accountLocked || oldPIN != correctPIN)
    {
        return false;
    }

    if (!isValidPIN(newPIN) || newPIN == correctPIN)
    {
        return false;
    }

    correctPIN = newPIN;

    transactions.push_back("PIN successfully changed");

    return true;
}

// Select an account
bool ATM::selectAccount(AccountType type)
{
    if (type != AccountType::Savings &&
        type != AccountType::Current)
    {
        return false;
    }

    selectedAccount = type;
    return true;
}

// Get selected account
AccountType ATM::getSelectedAccount() const
{
    return selectedAccount;
}

// Get selected account balance
double ATM::getBalance() const
{
    return getBalance(selectedAccount);
}

// Get specific account balance
double ATM::getBalance(AccountType type) const
{
    if (type == AccountType::Savings)
    {
        return savingsBalance;
    }

    if (type == AccountType::Current)
    {
        return currentBalance;
    }

    return 0.0;
}

// Deposit money
bool ATM::deposit(double amount)
{
    if (!std::isfinite(amount) || amount <= 0)
    {
        return false;
    }

    if (selectedAccount == AccountType::Savings)
    {
        savingsBalance += amount;
    }
    else
    {
        currentBalance += amount;
    }

    lastTransactionType = "Deposit";
lastTransactionAmount = amount;
lastTransactionAccount = selectedAccount;
lastTransactionTime = std::time(nullptr);
    transactions.push_back(
        "Deposit (" + accountName(selectedAccount) +
        "): +" + formatMoney(amount)
    );

    return true;
}

// Withdraw money
bool ATM::withdraw(double amount)
{
     checkDailyWithdrawalReset();

    if (!std::isfinite(amount) || amount <= 0)
    {
        return false;
    }

    if (amount > getBalance())
    {
        return false;
    }

    if (amount > getDailyWithdrawalRemaining())
    {
        return false;
    }

    if (selectedAccount == AccountType::Savings)
    {
        savingsBalance -= amount;
    }
    else
    {
        currentBalance -= amount;
    }

    dailyWithdrawn += amount;

    lastTransactionType = "Withdrawal";
lastTransactionAmount = amount;
lastTransactionAccount = selectedAccount;
lastTransactionTime = std::time(nullptr);

    transactions.push_back(
        "Withdrawal (" + accountName(selectedAccount) +
        "): -" + formatMoney(amount)
    );

    return true;
}

// Transfer money between accounts
bool ATM::transfer(
    double amount,
    AccountType destination)
{
    if (!std::isfinite(amount) || amount <= 0)
    {
        return false;
    }

    if (destination != AccountType::Savings &&
        destination != AccountType::Current)
    {
        return false;
    }
   
 if (destination == selectedAccount)
    {
        return false;
    }

    if (amount > getBalance())
    {
        return false;
    }

    // Deduct from source account
    if (selectedAccount == AccountType::Savings)
    {
        savingsBalance -= amount;
    }
    else
    {
        currentBalance -= amount;
    }

    // Add to destination account
    if (destination == AccountType::Savings)
    {
        savingsBalance += amount;
    }
    else
    {
        currentBalance += amount;
    }

    // Record successful transfer for receipt
lastTransactionType = "Transfer";
lastTransactionAmount = amount;
lastTransactionAccount = selectedAccount;
lastTransactionTime = std::time(nullptr);

    transactions.push_back(
        "Transfer from " + accountName(selectedAccount) +
        " to " + accountName(destination) +
        ": " + formatMoney(amount)

    );

    return true;
}

// Get remaining daily withdrawal allowance
double ATM::getDailyWithdrawalRemaining() const
{
    const_cast<ATM*>(this)->checkDailyWithdrawalReset();

    return DAILY_WITHDRAWAL_LIMIT - dailyWithdrawn;
}

// Reset daily withdrawal tracking
void ATM::resetDailyWithdrawalLimit()
{
    dailyWithdrawn = 0.0;
    lastWithdrawalDate = std::time(nullptr);
}

// Display account information
void ATM::showAccountInfo() const
{
    std::cout << "\n===== ACCOUNT INFORMATION =====\n";

    std::cout << "Savings Account: "
              << savingsAccountNumber << '\n';

    std::cout << "Savings Balance: "
              << formatMoney(savingsBalance) << '\n';

    std::cout << "\nCurrent Account: "
              << currentAccountNumber << '\n';

    std::cout << "Current Balance: "
              << formatMoney(currentBalance) << '\n';

    std::cout << "\nSelected Account: "
              << accountName(selectedAccount) << '\n';

    std::cout << "Daily Withdrawal Remaining: "
              << formatMoney(getDailyWithdrawalRemaining())
              << '\n';
}

// Display complete transaction history
void ATM::showTransactions() const
{
    if (transactions.empty())
    {
        std::cout << "No transactions yet.\n";
        return;
    }

    std::cout << "\n===== TRANSACTION HISTORY =====\n";

    for (const std::string& transaction : transactions)
    {
        std::cout << transaction << '\n';
    }
}

// Display the five most recent transactions
void ATM::showMiniStatement() const
{
    if (transactions.empty())
    {
        std::cout << "No transactions yet.\n";
        return;
    }

    std::cout << "\n===== MINI STATEMENT =====\n";

    int start = static_cast<int>(transactions.size()) - 5;

    if (start < 0)
    {
        start = 0;
    }

    for (int i = static_cast<int>(transactions.size()) - 1;
         i >= start; --i)
    {
        std::cout << transactions[i] << '\n';
    }
}

// Get the latest transaction receipt
std::string ATM::getLastReceipt() const
{
   if (lastTransactionType.empty())
{
    return "No transaction receipt available.";
}

    std::string accountNumber =
        lastTransactionAccount == AccountType::Savings
        ? savingsAccountNumber
        : currentAccountNumber;

    double balance = getBalance(lastTransactionAccount);

    std::ostringstream receipt;

    receipt << "\n========== ATM RECEIPT ==========\n";

    receipt << "Date: "
            << formatDateTime(lastTransactionTime) << '\n';

    receipt << "Account: " << accountNumber << '\n';

    receipt << "Account Type: "
            << accountName(lastTransactionAccount) << '\n';

    receipt << "Transaction: "
            << lastTransactionType << '\n';

    receipt << "Amount: "
            << formatMoney(lastTransactionAmount) << '\n';

    receipt << "Balance: "
            << formatMoney(balance) << '\n';

    receipt << "=================================\n";

    return receipt.str();
}

// Set ATM language
bool ATM::setLanguage(Language language)
{
    if (language != Language::English &&
        language != Language::French &&
        language != Language::Russian)
    {
        return false;
    }

    selectedLanguage = language;
    return true;
}

// Get selected ATM language
Language ATM::getLanguage() const
{
    return selectedLanguage;
}

// Get translated message
std::string ATM::getMessage(const std::string& key) const
{
    if (selectedLanguage == Language::French)
    {
        if (key == "welcome") return "Bienvenue au distributeur automatique";
        if (key == "balance") return "Votre solde";
        if (key == "deposit") return "Depot effectue avec succes";
        if (key == "withdraw") return "Retrait effectue avec succes";
        if (key == "invalid") return "Operation invalide";
    }

    if (selectedLanguage == Language::Russian)
    {
        if (key == "welcome") return "Dobro pozhalovat v bankomat";
        if (key == "balance") return "Vash balans";
        if (key == "deposit") return "Vnesenie sredstv vypolneno";
        if (key == "withdraw") return "Snyatie sredstv vypolneno";
        if (key == "invalid") return "Nedopustimaya operatsiya";
    }

    if (key == "welcome") return "Welcome to the ATM";
    if (key == "balance") return "Your balance";
    if (key == "deposit") return "Deposit successful";
    if (key == "withdraw") return "Withdrawal successful";
    if (key == "invalid") return "Invalid operation";

    return "Unknown message";
}

// Enable or disable voice guidance
void ATM::setVoiceEnabled(bool enabled)
{
    voiceEnabled = enabled;
}

// Check whether voice guidance is enabled
bool ATM::isVoiceEnabled() const
{
    return voiceEnabled;
}

// Speak a message using Windows text-to-speech
void ATM::speak(const std::string& message) const
{
    if (!voiceEnabled)
    {
        return;
    }

#ifdef _WIN32
    std::string command =
        "PowerShell -NoProfile -Command \""
        "Add-Type -AssemblyName System.Speech; "
        "$speaker = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
        "$speaker.Speak('" + message + "'); "
        "$speaker.Dispose()\"";

    std::system(command.c_str());
#else
    std::cout << "[VOICE] " << message << '\n';
#endif
}

// Insert bank card
bool ATM::insertCard()
{
    if (cardInserted)
    {
        return false;
    }

    cardInserted = true;
    return true;
}

// Remove bank card
bool ATM::removeCard()
{
    if (!cardInserted)
    {
        return false;
    }

    cardInserted = false;
    return true;
}

// Check card status
bool ATM::isCardInserted() const
{
    return cardInserted;
}

// Get card removal reminder
std::string ATM::getCardRemovalReminder() const
{
    if (!cardInserted)
    {
        return "";
    }

    if (selectedLanguage == Language::French)
    {
        return "Veuillez retirer votre carte bancaire.";
    }

    if (selectedLanguage == Language::Russian)
    {
        return "Pozhaluysta, zabерите svoyu bankovskuyu kartu.";
    }

    return "Please remove your bank card.";
}