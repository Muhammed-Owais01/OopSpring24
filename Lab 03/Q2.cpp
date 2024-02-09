/**
 * Programmer: Muhammed Owais 
 * Desc: Q2, WaterBottle class
 * Date: 07/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class WaterBottle{
private:
	string company, color;
	int waterCapacityl, waterCapacityml;
public:
	// Getters
	string getCompany() {return company;}
	string getColor() {return color;}
	int getWaterCapacityl() {return waterCapacityl;}
	int getWaterCapacityml() {return waterCapacityml;}

	// Setters
	void setCompany(string company) {this->company = company;}
	void setColor(string color) {this->color = color;}
	void setWaterCapacityl(int waterCapacityl) {this->waterCapacityl = waterCapacityl;}
	void setWaterCapacityml(int waterCapacityml) {this->waterCapacityml = waterCapacityml;}

	// Functions
	void updateWaterCapacity(int capacity)
	{
		setWaterCapacityl(capacity);
		setWaterCapacityml(capacity / 1000);
	}
};

int main()
{
	int num;
	cout << "Enter Water capacity: ";
	cin >> num;

	WaterBottle bottle;
	bottle.setCompany("Nestle");
	bottle.setColor("Blue");
	bottle.updateWaterCapacity(num);

	cout << "Company: " << bottle.getCompany() << "\nColor: " << bottle.getColor() 
	<< "\nCapacity(Litres): " << bottle.getWaterCapacityl() << "\nCapacity(Mililitres): " << bottle.getWaterCapacityml();
}