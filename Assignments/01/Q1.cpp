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
	: healthStatus("Healthy"), hungerLevel(0), happinessLevel(10)
	{}
	void displayPetDetails();
	void updateHappiness();
	void updateHealth(bool clean, bool groomed);
	void updateHunger(int feed);
	void setPetName();
	vector<string> getSpecialSkills() {return this->specialSkills;}
	void setSpecialSkills(string skill);
	string getPetName() {return this->name;}
};

void Pet::displayPetDetails()
{
	cout << "Health Status: " << this->healthStatus << endl;
	cout << "Hunger Level: " << this->hungerLevel << endl;
	cout << "Happiness Level: " << this->happinessLevel << endl;
	cout << "Special Skills: ";
	for (string skills: this->specialSkills)
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
		}
	} while (choice != -1);
}