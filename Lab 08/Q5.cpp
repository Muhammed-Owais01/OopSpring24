/**
 * Programmer: Muhammed Owais 
 * Desc: Q5, ElectricCar
 * Date: 23/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>

class Vehicle
{
public:
	std::string make, model;
	int year;
	Vehicle(std::string make, std::string model, int year) : make(make), model(model), year(year) {}
};

class Car : public Vehicle
{
public:
	int doors, fuelEfficiency;
	Car(int doors, int fuelEfficiency, std::string make, std::string model, int year) 
	: doors(doors), fuelEfficiency(fuelEfficiency), Vehicle(make, model, year) {} 
};

class ElectricCar : public Car
{
public:
	int batteryLife;
	ElectricCar(int batteryLife, int doors, int fuelEfficiency, std::string make, std::string model, int year)
	: batteryLife(batteryLife), Car(doors, fuelEfficiency, make, model, year) {}

	void display()
	{
		std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Doors: " << doors << ", Fuel Efficiency: " << fuelEfficiency
		<< ", Battery Life: " << batteryLife;
	}
};

int main()
{
	ElectricCar myCar(300, 4, 30, "Tesla", "S", 2022);
	myCar.display();
}