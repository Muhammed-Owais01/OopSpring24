/**
 * Programmer: Muhammed Owais 
 * Desc: Q4, SmartPhone
 * Date: 13/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class SmartPhone
{
private:
	string brand, mode, displayRes;
	int RAM, ROM, storage;
public:
	// Getter
	string getBrand() {return brand;}
	string getModel() {return mode;}
	string getDisplayRes() {return displayRes;}
	int getRAM() {return RAM;}
	int getROM() {return ROM;}
	int getStorage() {return storage;}

	// Setter
	void setBrand(string brand) {this->brand = brand;}
	void setModel(string mode) {this->mode = mode;}
	void setDisplayRes(string displayRes) {this->displayRes = displayRes;}
	void setRAM(int RAM) {this->RAM = RAM;}
	void setROM(int ROM) {this->ROM = ROM;}
	void setStorage(int storage) {this->storage = storage;}

	// Functions
	void makeACall()
	{
		string num;
		int random;
		cout << "Dial a number: ";
		cin >> num;
		cout << "Calling " << num << endl;
		random = rand() % 2 + 1;
		(random == 1) ? cout << "Call Successfully Connected\n\n" : cout << "Call Did Not Connect\n\n";
	}

	void sendMessage()
	{
		string num;
		string msg;
		cout << "Dial a number to send a message to: ";
		cin >> num;
		cout << "Type the message you want to send: ";
		cin.ignore();
		getline(cin, msg);
		cout << "Message: \"" << msg << "\" sent to " << num << endl;
		cout << "\n";
	}

	void connectToWifi()
	{
		int choice, random;
		cout << "Connect to: \n1- Wifi A\n2- Wifi B\n3- Wifi C\nInput: ";
		cin >> choice;
		random = rand() % 2 + 1;
		(random == 1) ? cout << "Wifi Successfully Connected\n\n\n" : cout << "Wifi Did Not Connect\n\n";
	}

	void browseInternet()
	{
		string url;
		int random;
		cout << "Enter the URL: ";
		cin.ignore();
		getline(cin, url);
		random = rand() % 2 + 1;
		(random == 1) ? cout << "URL Successfully Connected\n\n" : cout << "URL Did Not Connect\n\n";
	}
};


int main()
{
	int choice = 0;
	SmartPhone phone;

	phone.setRAM(4);
	phone.setROM(64);
	phone.setModel("Samsung Galaxy S21");
	phone.setBrand("Samsung");
	phone.setStorage(128);
	phone.setDisplayRes("1080 x 2340");

	cout << "RAM: " << phone.getRAM() << "\nROM: " << phone.getROM() << "\nModel: " << phone.getModel() 
	<< "\nBrand: " << phone.getBrand() << "\nStorage: " << phone.getStorage() << "\nDisplay Resolution: " << phone.getDisplayRes() << endl;

	while (choice != - 1)
	{
		cout << "1- Make A Phone Call\n"
			 << "2- Send A Message\n"
			 << "3- Connect To A WiFi\n"
			 << "4- Browse Internet\n"
			 << "-1 Exit\n"
			 << "Input: ";
		cin >> choice;

		switch(choice)
		{
		case 1:
			phone.makeACall();
			break;
		case 2:
			phone.sendMessage();
			break;
		case 3:
			phone.connectToWifi();
			break;
		case 4:
			phone.browseInternet();
			break;
		}
	}
}