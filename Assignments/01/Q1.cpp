/**
 * Programmer: Muhammed Owais 
 * Desc: Scenario 1, Pet
 * Date: 25/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Pet
{
private:
	string healthStatus, name;
	int hungerLevel, happinessLevel;
	vector<string> specialSkills;
public:
	Pet()
	: healthStatus("Healthy"), hungerLevel(rand() % 10), happinessLevel(10)
	{}
	void displayPetDetails();
	void updateHappiness();
	void updateHealth(bool clean, bool overEating);
	void updateHunger(int feed);
	void setPetName();
	vector<string> getSpecialSkills() {return this->specialSkills;}
	void setSpecialSkills(string skill);

	// Getters
	string getPetName() {return this->name;}
	int getHunger() {return this->hungerLevel;}
	int getPetHappiness() {return this->happinessLevel;}
	string getHealthStatus() {return this->healthStatus;}
};

void Pet::displayPetDetails()
{
	cout << "Health Status: " << this->healthStatus << endl;
	cout << "Hunger Level: " << this->hungerLevel << endl;
	cout << "Happiness Level: " << this->happinessLevel << endl;
	cout << "Special Skills: ";
	for (string skills : this->specialSkills)
		cout << skills << " ";
}

void Pet::updateHappiness()
{
	(this->hungerLevel > 5) ? (this->happinessLevel--) : (this->happinessLevel++);
}

void Pet::updateHealth(bool clean, bool overEating)
{
	(clean && !overEating) ? (this->healthStatus = "Healthy") : (this->healthStatus = "Sick");
}

void Pet::updateHunger(int feed)
{
	if (feed < 5)
	{
		this->hungerLevel++;
	}
}

void Pet::setPetName()
{
	cout << "Name: "; 
	cin >> this->name;
}

void Pet::setSpecialSkills(string skill)
{
	this->specialSkills.push_back(skill);
}

class Adopter
{
private:
	string adopterName, adopterNumber;
	vector<Pet> adoptedPetRecords;
public:
	Adopter(string name, string num)
	: adopterName(name), adopterNumber(num)
	{}

	void adoptPet(vector<Pet>& petList);
	void returnPet(vector<Pet>& petList);
	void feedPet();
	void healthReport();
	void displayAdoptedPets();
};

void Adopter::adoptPet(vector<Pet>& petList)
{
	string name;
	cout << "Enter Pet Name: ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < petList.size(); ++i)
	{
		if (petList[i].getPetName() == name)
		{
			this->adoptedPetRecords.push_back(petList[i]);
			petList.erase(petList.begin() + i);
		}
	}
}

void Adopter::returnPet(vector<Pet>& petList)
{
	string name;
	cout << "Enter Pet Name: ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < adoptedPetRecords.size(); i++)
	{
		if (adoptedPetRecords[i].getPetName() == name)
		{
			petList.push_back(adoptedPetRecords[i]);
			adoptedPetRecords.erase(adoptedPetRecords.begin() + i);
		}
	}
}

void Adopter::displayAdoptedPets()
{
	for (Pet pet : adoptedPetRecords)
	{
		cout << "Name: " << pet.getPetName() << endl;
		pet.displayPetDetails();
		cout << endl;
	}
}

void Adopter::feedPet()
{
	int food;
	cout << "Enter Food Amount: ";
	cin >> food;
	for (Pet pet : adoptedPetRecords)
	{
		pet.updateHunger(food);
		pet.updateHappiness();
		std::cout << "Name: " << pet.getPetName() << ", Hunger: " << pet.getHunger() << ", Happiness: " << pet.getPetHappiness() << endl;
	}
}

void Adopter::healthReport()
{
	char cln, oE;
	bool clean, overEating;
	for (Pet pet : adoptedPetRecords)
	{
		cout << "Is Your Pet Clean(Y/N): ";
		cin >> cln;
		clean = (cln == 'Y') ? true : false;
		cout << "Is Your Pet Over Eating(Y/N): ";
		cin >> oE;
		overEating = (oE == 'Y') ? true : false;

		pet.updateHealth(clean, overEating);

		std::cout << "Name: " << pet.getPetName() << ", Health Status: " << pet.getHealthStatus() << endl;
	}
}

Pet initPet()
{
	Pet pet;
	pet.setPetName();
	string temp;

	cin.ignore();
	while (1)
	{
		cout << "Enter Nothing To End Adding Skills" << endl;
		cout << "Enter A Skill: ";
		getline(cin, temp);
		if (temp == "")
			break;
		pet.setSpecialSkills(temp);
	}
	return pet;
}

void showPetList(vector<Pet> petList)
{
	for (Pet pet : petList)
	{
		cout << "Name: " << pet.getPetName() << endl;
		pet.displayPetDetails();
		cout << endl;
	}
}


int main()
{
	cout << "Name: Muhammed Owais, Student ID: 23K-0047\n";
	int choice;

	vector<Pet> petList;
	Adopter shop("Jane", "021314");

	do
	{
		cout << "1: Add A Pet\n"
		 << "2: Show All Pets\n"
		 << "3: Adopt A Pet\n"
		 << "4: Show Adopted Pets\n"
		 << "5: Return A Pet\n"
		 << "6: Feed Your Pets\n"
		 << "7: Maintain Your Pet\n"
		 << "-1: Exit\n"
		 << "Input: ";
		cin >> choice;
		cout << endl;

		switch(choice)
		{
		case 1:
			petList.push_back(initPet());
			break;
		case 2:
			showPetList(petList);
			break;
		case 3:
			shop.adoptPet(petList);
			break;
		case 4:
			shop.displayAdoptedPets();
			break;
		case 5:
			shop.returnPet(petList);
			break;
		case 6:
			shop.feedPet();
			break;
		case 7:
			shop.healthReport();
			break;
		}
	} while (choice != -1);
}