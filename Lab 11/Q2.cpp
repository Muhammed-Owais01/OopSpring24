#include <iostream>

class Account
{
protected:
    int accountNum; 
    double balance;
public:
    Account(int accountNum, double balance) : accountNum(accountNum), balance(balance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;

    int getAccountNumber() {return this->accountNum;}
    double getBalance() {return this->balance;}

    void setBalance(double amount) {this->balance = amount;}
};

class SavingsAccount : public Account
{
private:
    double interestRate;
public:
    SavingsAccount(int accountNum, double balance) : Account(accountNum, balance) {}

    void deposit(double amount) override {this->setBalance(this->getBalance() + amount);}
    void withdraw(double amount) override {this->setBalance(this->getBalance() - amount);}
    void calculateInterest() override {std::cout << this->getBalance() * this->interestRate;}
};

class CurrentAccount : public Account
{
private:
    double overdraftLimit;
public:
    CurrentAccount(int accountNum, double balance) : Account(accountNum, balance) {}

    void deposit(double amount) override {this->setBalance(this->getBalance() + amount);}
    void withdraw(double amount) override 
    {
        if (this->overdraftLimit < amount)
            std::cout << "Overdraft Limit Reached" << std::endl;
        else
            this->setBalance(this->getBalance() - amount);
    }
    void calculateInterest() override {std::cout << "No Interest" << std::endl;}
};

int main()
{

}