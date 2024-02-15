/**
 * Programmer: Muhammed Owais 
 * Desc: Q5, Office dynamically allocation
 * Date: 15/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class Office
{
private:
	string location;
	int seatingCapacity;
	string* furniture;
public:
	Office(string area, int seatCapacity, int size)
	: location(area), seatingCapacity(seatCapacity)
	{
		this->furniture = new string[size];
	}
	~Office()
	{
		delete this->furniture;
	}
};

int main()
{
	Office* office = new Office("Room 1", 20, 5);

	delete office;
}