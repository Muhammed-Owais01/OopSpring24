/**
 * Programmer: Muhammed Owais 
 * Desc: Product management
 * Date: 07/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

#define MAX 100
using namespace std;

struct productManage {
	string prodName;
	int price, quantity, id;
};

void addNewProd(productManage products[], int &count);
int findProd(productManage products[], int count);
void outProd(productManage products[], int count);
void updateProd(productManage products[], int count);
int main()
{
	productManage products[MAX];
	int n, count = 0;
	while (n != - 1)
	{
		cout << "1: Add a new product\n"
			 << "2: Update a product\n"
			 << "3: Display a product\n"
			 << "-1: Exit\n"
			 << "Input: ";
		cin >> n;
		switch(n)
		{
		case 1:
			addNewProd(products, count);
			break;
		case 2:
			updateProd(products, count);
			break;
		case 3:
			outProd(products, findProd(products, count));
			break;
		}
	}
}

void addNewProd(productManage products[], int &count)
{
	cout << "Product Name: ";
	cin.ignore();
	getline(cin, products[count].prodName);

	cout << "Product Price: ";
	cin >> products[count].price;

	cout << "Product Quantity: ";
	cin >> products[count].quantity;

	cout << "Product ID: ";
	cin >> products[count].id;

	count++;
}

void outProd(productManage products[], int index)
{
	if (index != -1)
	{
		cout << "Product Name: " << products[index].prodName << endl
		 << "Product Price: " << products[index].price << endl
		 << "Product Quantity: " << products[index].quantity << endl
		 << "Product ID: " << products[index].id << endl;
	}
	else
		cout << "Product not available\n";

}

int findProd(productManage products[], int count)
{
	int id, index = 0;
	cout << "Enter Product ID: ";
	cin >> id;
	while (index < count)
	{
		if (products[index].id == id)
			return index;
		index++;
	}
	return -1;
}

void updateProd(productManage products[], int count)
{
	int index = findProd(products, count);
	if (index != -1)
		addNewProd(products, index);
	else
		cout << "Product not available\n";
}