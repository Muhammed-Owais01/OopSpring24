/**
 * Programmer: Muhammed Owais 
 * Desc: Q1, BankAccount
 * Date: 18/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

class BankAccount
{
private:
	int accountId, numTransactions;
	double balance;
	int* transactionHistory;
public:
	BankAccount(int accountId, int numTransactions, double balance, int* transactionHistory)
	{
		this->accountId = accountId;
		this->numTransactions = numTransactions;
		this->balance = balance;
		this->transactionHistory = new int[this->numTransactions];
		this->transactionHistory = transactionHistory;
	}
	BankAccount(BankAccount& myAccount)
	{
		this->accountId = myAccount.accountId;
		this->numTransactions = myAccount.numTransactions;
		this->balance = myAccount.balance;
		this->transactionHistory = new int[this->numTransactions];
		this->transactionHistory = myAccount.transactionHistory;
	}
	~BankAccount()
	{
		delete[] transactionHistory;
	}

	// Getters
	int getAccountId() const {return accountId;}
	int getNumTransactions() const {return numTransactions;}
	double getBalance() const {return balance;}
	int* getTransactionHistory() {return transactionHistory;}

	// Setters
	void setAccountId(int newAccountId) {accountId = newAccountId;}
	void setNumTransactions(int newNumTransactions) {numTransactions += newNumTransactions;}
	void setBalance(double newBalance) {balance = newBalance;}
	void setTransactionHistory(int* newTransactionHistory) {
		delete[] transactionHistory;
		transactionHistory = newTransactionHistory;
	}

	void display()
	{
		std::cout << "Account ID: " << this->accountId << ", Balance: " << this->balance << std::endl;
		for (int i = 0; i < this->numTransactions; i++)
			std::cout << this->transactionHistory[i] << std::endl;
	}

	void updateTransactionHistory(int* newTransactionHistory) {
		delete[] transactionHistory;
		std::cout << "TEST";
		transactionHistory = new int[numTransactions];
		for (int i = 0; i < numTransactions; ++i)
		{
			transactionHistory[i] = newTransactionHistory[i];
		}
	}
};

int main()
{
	int transactions[] = {100, -50, 75, -25, 50};
	BankAccount myAccount(47, 5, 200, transactions);

	BankAccount copyAccount(myAccount);

	std::cout << "myAccount:" << std::endl;
	myAccount.display();

	std::cout << "copyAccount:" << std::endl;
	copyAccount.display();

	int newTransactions[] = {100, -50, 70, 25, 60};
	myAccount.updateTransactionHistory(newTransactions);
	std::cout << "After Update: " << std::endl;
	myAccount.display();
}