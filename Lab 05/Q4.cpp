/**
 * Programmer: Muhammed Owais 
 * Desc: Q4, BankAccount
 * Date: 18/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class BankAccount {
private:
	string accountNumber;
	string accountHolderName;
	double balance;
public:
	// BankAccount();
	BankAccount(string accountNumber = "0000", string accountHolderName = "", double balance = 0)
	: accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance){}

	// Getters
	string getAccountNumber() {return this->accountNumber;}
	string getAccountHolderName() {return this->accountHolderName;}
	double getBalance() {return this->balance;}

	// Setters
	void setAccountNumber(string accountNumber) {this->accountNumber = accountNumber;}
	void setAccountHolderName(string accountHolderName) {this->accountHolderName = accountHolderName;}
	void setBalance(double balance) {this->balance = balance;}

	void deposit(double amount);
	void withdraw(double amount);
	void display();
};

void BankAccount::deposit(double amount)
{
	this->balance += amount;
}

void BankAccount::withdraw(double amount)
{
	if (this->balance < amount) cout << "Insufficient Balance\n";
	else 
	{
		this->balance -= amount;
		cout << "Deposited!!\n";
	}
}

void BankAccount::display()
{
	cout << "Account Number: " << this->accountNumber
	<< "\nAccount Holder Name: " << this->accountHolderName
	<< "\nBalance: " << this->balance << endl;
}

int main()
{
	BankAccount users[3] = {
		{"32113", "Ali", 40},
		{"32543", "Fasih", 220},
		{"32893", "Abser", 7900}
	};

	for (int i = 0; i < 3; ++i)
	{
		users[i].display();
	}


	users[2].deposit(500.0);
	users[2].display();
	users[0].withdraw(200.0);
	users[0].display();

}