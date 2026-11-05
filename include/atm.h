
#ifndef ATM_H
#define ATM_H

#include <string>
#include <vector>
#include <ctime>


// Supported account types
enum class AccountType
{
    Savings,
    Current
};

// Supported ATM languages
enum class Language
{
    English,
    French,
    Russian
};

class ATM
{
private:
    // Customer PIN
    std::string correctPIN;

    // Account numbers
    std::string savingsAccountNumber;
    std::string currentAccountNumber;

    void checkDailyWithdrawalReset();

    // Account balances
    double savingsBalance;
    double currentBalance;

    // Currently selected account
    AccountType selectedAccount;

    // Date of the last withdrawal tracking update
std::time_t lastWithdrawalDate;

    // Bank card status
bool cardInserted = false;

    // Currently selected language
Language selectedLanguage = Language::English;


    // Stores transaction history
    std::vector<std::string> transactions;

    // Voice guidance setting
bool voiceEnabled = false;

    // PIN security
    int failedPINAttempts;
    static constexpr int
    MAX_PIN_ATTEMPTS = 3;
    bool accountLocked;

    // Dailly withdraw limit
    double dailyWithdrawn;
    static constexpr double
    DAILY_WITHDRAWAL_LIMIT = 1000.0;

    // Last transaction details
std::string lastTransactionType;
double lastTransactionAmount = 0.0;
AccountType lastTransactionAccount = AccountType::Savings;
std::time_t lastTransactionTime = 0;

public:
    // Constructor
    ATM(const std::string& pin, double initialBalance);

    // PIN authentication and security
    bool authenticate(const std::string& enteredPIN) ;
    bool isLocked() const;
    int getPINAttemptsRemaining() const;
    bool changePIN(const std::string&
         oldPIN,
                           const std::string&
    newPIN);

    // Account selection
    bool selectAccount(AccountType type);
    AccountType getSelectedAccount() const;

    // Balance information
    double getBalance() const;
    double getBalance(AccountType type) const;

    // Money operations
    bool deposit(double amount);
    bool withdraw(double amount);
    bool transfer(double amount, AccountType destination);

    // Daily withdrawl limit
    double
    getDailyWithdrawalRemaining() const;
    void resetDailyWithdrawalLimit();


    // Account information
    void showAccountInfo() const;

    // Transaction history
    void showTransactions() const;
    void showMiniStatement() const;

    // Transaction receipt
    std::string getLastReceipt() const;

    // Language selection
bool setLanguage(Language language);
Language getLanguage() const;
std::string getMessage(const std::string& key) const;

// Voice guidance
void setVoiceEnabled(bool enabled);
bool isVoiceEnabled() const;
void speak(const std::string& message) const;

// Bank card management
bool insertCard();
bool removeCard();
bool isCardInserted() const;
std::string getCardRemovalReminder() const;
};

#endif
