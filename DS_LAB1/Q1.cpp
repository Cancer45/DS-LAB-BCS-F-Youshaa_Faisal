#include <iostream>

class BankAccount
{
    float balance;
    
    public:
//default constructor
    BankAccount() : balance(0) {}
    
    //parameterized constructor
    BankAccount(float balance) : balance(balance) {}
    
    //copy constructor
    BankAccount(BankAccount& other_account)
    {
        this->balance = other_account.balance;
    }
    
    float getBalance()
    {
        return balance;
    }
    
    void editBalance(float amount)
    {
        balance += amount;
    }
};

int main ()
{
    BankAccount account1;
    std::cout << "Balance (account1): " << account1.getBalance() << std::endl;
    
    BankAccount account2(1000);
    std::cout << "Balance (account2): " << account2.getBalance() << std::endl;
    
    BankAccount account3(account2);
    account3.editBalance(-200);
    std::cout << "Balance (account3): " << account3.getBalance() << std::endl;
    
}