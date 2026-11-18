#include "atm.h"
#include <iostream>

int main() {
    // Create the ATM with Nathan's PIN and initial balance
    ATM atmMachine("1234", 5000.0); 
    
    // Start Cedrick's menu loop
    atmMachine.start();
    
    return 0;
}