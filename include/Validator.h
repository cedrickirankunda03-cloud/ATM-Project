#pragma once
#include <string>
#include <iostream>
#include <limits>

class Validator {
public:
    static int getValidInt(const std::string& prompt, int min, int max) {
        int input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                if (input >= min && input <= max) return input;
                std::cout << "Error: Please enter a number between " << min << " and " << max << ".\n";
            } else {
                std::cout << "Error: Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    static double getValidAmount(const std::string& prompt) {
        double input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                if (input > 0) return input;
                std::cout << "Error: Amount must be greater than zero.\n";
            } else {
                std::cout << "Error: Invalid input. Please enter a valid amount.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
};