#include "atm.h"
#include <iostream>

//Create an ATM with a PIN and starting balance)
ATM::ATM(const std::strind& pin,double initialBalance)
:correctPIN(Pin),
balance(initialBalance >= 0 ?
initialBalance :0.0)
{
}

//Check wether the entered PIN is correct
bool ATM::authenticate(const std;& enteredpin) const
{
return enteredPIN == correctPIN;
}
//Return the current account balance
double ATM::getBalance()const
{
return balance;
}

//Add money to the account
bool ATM::dep[opsit(double amount)
{
if(amount <= 0)
{
return false;
}
balance +=amount;
transactions.push_back("Deposit: +" + std::to_string(amount)
);
return true;
}

//Diisplay the transaction history
void ATM::showTransactions() const 
{
if(transactions.empty())
{
std::cout<<"NO transactions yet.\n";
return;
}
std::cout<<"\nTransaction History:\n";
for(const std::string& transaction : transactions)
{
std::count << transaction << '\n';
}
}

