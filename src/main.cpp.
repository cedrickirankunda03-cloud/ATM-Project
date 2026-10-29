#include "atm.h"
#include <iostream>
#include <limits>

int main()
{
    ATM atm("1234", 500.0);

    std::string enteredPIN;

    std::cout << "Welcome to the ATM!\n";
    std::cout << "Enter your PIN: ";
    std::cin >> enteredPIN;

    if (!atm.authenticate(enteredPIN))
    {
        std::cout << "Incorrect PIN. Access denied.\n";
        return 0;
    }

    std::cout << "Login successful!\n";

    int choice = 0;

    do
    {
        std::cout << "\n===== ATM MENU =====\n";
        std::cout << "1. Check balance\n";
        std::cout << "2. Deposit money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. Transaction history\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        double amount = 0.0;

        switch (choice)
        {
            case 1:
                std::cout << "Current balance: "
                          << atm.getBalance() << '\n';
                break;

            case 2:
                std::cout << "Enter deposit amount: ";
                if (std::cin >> amount)
                {
                    if (atm.deposit(amount))
                        std::cout << "Deposit successful.\n";
                    else
                        std::cout << "Invalid deposit amount.\n";
                }
                else
                {
                    std::cout << "Please enter a valid number.\n";
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n'
                    );
                }
                break;

            case 3:
                std::cout << "Enter withdrawal amount: ";
                if (std::cin >> amount)
                {
                    if (atm.withdraw(amount))
                        std::cout << "Withdrawal successful.\n";
                    else
                        std::cout << "Withdrawal rejected.\n";
                }
                else
                {
                    std::cout << "Please enter a valid number.\n";
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n'
                    );
                }
                break;

            case 4:
                atm.showTransactions();
                break;

            case 5:
                std::cout << "Thank you for using the ATM!\n";
                break;

            default:
                std::cout << "Invalid choice. Choose 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}
