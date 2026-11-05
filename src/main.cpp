#include "atm.h"

#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;

// Read a valid menu choice
int readChoice()
{
    int choice;

    while (!(cin >> choice))
    {
        cout << "Invalid input. Enter a number: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return choice;
}

// Read a valid transaction amount
double readAmount()
{
    double amount;

    while (!(cin >> amount) || !isfinite(amount))
    {
        cout << "Invalid amount. Enter a valid number: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return amount;
}

// Display ATM menu
void displayMenu()
{
    cout << "\n========== ATM MENU ==========\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Transfer Money\n";
    cout << "5. Transaction History\n";
    cout << "6. Mini Statement\n";
    cout << "7. Account Information\n";
    cout << "8. Change PIN\n";
    cout << "9. Select Account Type\n";
    cout << "10. Select Language\n";
    cout << "0. Exit\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}

int main()
{
    // Create demonstration accounts
    ATM customer("1234", 5000.0,
                 "10000001", "Savings");

    ATM recipient("5678", 2000.0,
                  "10000002", "Current");

    cout << "================================\n";
    cout << "       WELCOME TO ATM SYSTEM    \n";
    cout << "================================\n";

    customer.voiceMessage("Welcome to our ATM system.");

    // Language selection
    cout << "\nSelect Language:\n";
    cout << "1. English\n";
    cout << "2. French\n";
    cout << "Choice: ";

    int languageChoice = readChoice();

    if (languageChoice == 2)
        customer.selectLanguage("French");
    else
        customer.selectLanguage("English");

    // PIN authentication
    bool authenticated = false;

    while (!authenticated)
    {
        string enteredPIN;

        cout << "\nEnter your 4-digit PIN: ";
        cin >> enteredPIN;

        if (customer.authenticate(enteredPIN))
        {
            authenticated = true;
            cout << "\nAuthentication successful!\n";
            customer.voiceMessage("Welcome. Access granted.");
        }
        else if (customer.isAccountBlocked())
        {
            cout << "\nToo many incorrect attempts.\n";
            cout << "Please wait 30 seconds.\n";

            while (customer.isAccountBlocked())
            {
                this_thread::sleep_for(
                    chrono::seconds(1));
            }

            cout << "You can try again now.\n";
        }
        else
        {
            cout << "Authentication failed.\n";
        }
    }

    // Main ATM operations
    bool running = true;

    while (running)
    {
        displayMenu();

        int choice = readChoice();

        switch (choice)
        {
            case 1:
                cout << "\nCurrent Balance: $"
                     << customer.getBalance() << '\n';

                customer.announceBalance();
                break;

            case 2:
            {
                cout << "Enter deposit amount: $";

                double amount = readAmount();

                if (customer.deposit(amount))
                    cout << "Deposit successful!\n";
                else
                    cout << "Invalid deposit amount.\n";

                break;
            }

            case 3:
            {
                cout << "Enter withdrawal amount: $";

                double amount = readAmount();

                if (customer.withdraw(amount))
                    cout << "Withdrawal successful!\n";
                else
                    cout << "Withdrawal failed. Check your balance, "
                         << "ATM cash and daily limit.\n";

                break;
            }

            case 4:
            {
                string destination;
cout << "Enter recipient account number: ";
                cin >> destination;

                if (destination != recipient.getAccountNumber())
                {
                    cout << "Recipient account not found.\n";
                    break;
                }

                cout << "Enter transfer amount: $";

                double amount = readAmount();

                if (customer.transfer(recipient, amount))
                    cout << "Transfer successful!\n";
                else
                    cout << "Transfer failed.\n";

                break;
            }

            case 5:
                customer.showTransactions();
                break;

            case 6:
                customer.showMiniStatement();
                break;

            case 7:
                customer.showAccountInformation();
                break;

            case 8:
            {
                string oldPIN, newPIN;

                cout << "Enter current PIN: ";
                cin >> oldPIN;

                cout << "Enter new 4-digit PIN: ";
                cin >> newPIN;

                if (customer.changePIN(oldPIN, newPIN))
                    cout << "PIN changed successfully!\n";
                else
                    cout << "PIN change failed. Check your "
                         << "current PIN and new PIN format.\n";

                break;
            }

            case 9:
            {
                cout << "\nSelect Account Type:\n";
                cout << "1. Savings\n";
                cout << "2. Current\n";
                cout << "Choice: ";

                int typeChoice = readChoice();

                if (typeChoice == 1)
                    customer.setAccountType("Savings");
                else if (typeChoice == 2)
                    customer.setAccountType("Current");
                else
                    cout << "Invalid account type.\n";

                break;
            }

            case 10:
            {
                cout << "\nSelect Language:\n";
                cout << "1. English\n";
                cout << "2. French\n";
                cout << "Choice: ";

                int lang = readChoice();

                if (lang == 1)
                    customer.selectLanguage("English");
                else if (lang == 2)
                    customer.selectLanguage("French");
                else
                    cout << "Invalid language selection.\n";

                break;
            }

            case 0:
                running = false;
                break;

            default:
                cout << "Invalid menu choice. Try again.\n";
        }
    }

    // Card removal procedure
    customer.voiceMessage("Your ATM session is ending.");

    bool cardRemoved = false;

    while (!cardRemoved)
    {
        customer.remindCardRemoval();
        cardRemoved = customer.confirmCardRemoval();
    }

    cout << "\nThank you for using our ATM!\n";

    return 0;
}
