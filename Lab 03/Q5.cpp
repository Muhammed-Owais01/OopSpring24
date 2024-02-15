/**
 * Programmer: Muhammed Owais 
 * Desc: Q5, Stationary Shop
 * Date: 15/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

#define MAX 100

using namespace std;

class stationaryShop
{
private:
	string items[MAX];
	int prices[MAX];

	string userItems[MAX];
	int userQuantity[MAX] = {0};

	int priceIndex(string itemName);
	bool findItem(string itemName);
	void addUserItems(int &currentIndex);
public:
	void addItems(int &currentIndex, string item, int price);
	void listItems();
	void updatePrice();
	void displayAll();
	void printReceipt(int &currentIndex);
};


int stationaryShop::priceIndex(string itemName)
{
	for (int i = 0; i < MAX; i++)
	{
		if (items[i] == itemName)
			return i;
	}
	return -1;
}

bool stationaryShop::findItem(string itemName)
{
	for (auto item: items)
		if (item == itemName)
			return true;
	return false;
}

void stationaryShop::addUserItems(int &currentIndex)
{
	do
	{	
		do 
		{
			currentIndex++;
			cout << "Enter An Item: ";
			cin.ignore();
			getline(cin, userItems[currentIndex]);
		} while (userItems[currentIndex] != "" && !findItem(userItems[currentIndex]));

		if (userItems[currentIndex] == "")
			return;

		do 
		{
			cout << "Enter Quantity: ";
			cin >> userQuantity[currentIndex];	
		} while (userQuantity[currentIndex] < 0);

		cout << "Enter nothing to end add user items\n";
	} while (userItems[currentIndex] != "");
}

void stationaryShop::addItems(int &currentIndex, string item, int price)
{
	this->items[currentIndex] = item;
	this->prices[currentIndex] = price;
	currentIndex++;
}

void stationaryShop::listItems()
{
	for (string item : items)
	{
		if (item != "")
			cout << item << endl;
	}
}

void stationaryShop::updatePrice()
{
	int price, index;
	string itemName;
	do 
	{
		cout << "Enter Item Name Whose Price You Want To Change: ";
		cin.ignore();
		getline(cin, itemName);

		index = this->priceIndex(itemName);
	} while (index == -1);

	cout << "Enter New Price: ";
	cin >> prices[index];
}

void stationaryShop::displayAll()
{
	for (int i = 0; i < MAX; i++)
	{
		if (items[i] != "")
			cout << "Item: " << items[i] << ", Price: " << prices[i] << endl;
	}
}

void stationaryShop::printReceipt(int &currentIndex)
{
	int total = 0;
	this->addUserItems(currentIndex);
	for (int i = 0; i < MAX; ++i)
	{
		if (userItems[i] != "")
		{
			cout << "Item: " << userItems[i];
			cout << ", Quantity Bought: " << userQuantity[i];
			cout << ", Price: " << userQuantity[i] * prices[currentIndex] << endl;
			total = total + (userQuantity[i] * prices[currentIndex]);
		}
	}
	cout << "Total: " << total;
}

int main()
{
	int choice, price, index = 0;
	int userIndex = -1;
	string item;
	stationaryShop shop;

	do
	{
		cout << "1: Add A New Item\n"
			 << "2: Retrieve All Items\n"
			 << "3: Modify Price Of An Item\n"
			 << "4: Display All Items and thier Prices\n"
			 << "-1: Exit\n"
			 << "Input: ";
		cin >> choice;

		switch(choice)
		{
		case 1:
			cout << "Enter Item Name: ";
			cin.ignore();
			getline(cin, item);

			cout << "Enter Item Price: ";
			cin >> price;

			shop.addItems(index, item, price);
			break;
		case 2:
			shop.listItems();
			break;
		case 3:
			shop.updatePrice();
			break;
		case 4:
			shop.displayAll();
			break;
		}
	} while (choice != -1);	
	cout << "User Receipt:\n";
	shop.printReceipt(userIndex);
}