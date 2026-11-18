#include "atm.h"
#include <iostream>
#include <string>

int main() {
    // 1. Create the ATM object. 
    // Nathan needs to add his account number and account type to the ATM constructor later.
    // For now, we give it his PIN ("1234") and his starting balance ($5000.0).
    ATM atmMachine("1234", 5000.0); 
    
    // 2. Start the ATM menu loop
    atmMachine.start();
    
    return 0;
}