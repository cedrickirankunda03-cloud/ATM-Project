// include/Validator.h
#pragma once
#include <string>
#include <iostream>
#include <limits>

class Validator {
public:
    // 1. Validates menu choices (ensures they type a number and it's within range)
    static int getValidInt(const std::string& prompt, int min, int max) {
        int input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                if (input >= min && input <= max) {
                    return input;
                } else {
                    std::cout << "Error: Please enter a number between " << min << " and " << max << ".\n";
                }
            } else {
                // This catches if they type a letter instead of a number
                std::cout << "Error: Invalid input. Please enter a number.\n";
                std::cin.clear(); // clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
            }
        }
    }

    // 2. Validates money amounts (ensures it's a number and greater than 0)
    static double getValidAmount(const std::string& prompt) {
        double input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                if (input > 0) {
                    return input;
                } else {
                    std::cout << "Error: Amount must be greater than zero.\n";
                }
            } else {
                std::cout << "Error: Invalid input. Please enter a valid amount.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    // 3. Validates PIN (ensures it is exactly 4 digits)
    static std::string getValidPin(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::cin >> input;
            if (input.length() == 4) {
                return input;
            } else {
                std::cout << "Error: PIN must be exactly 4 digits.\n";
            }
        }
    }
};