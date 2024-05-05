#include <iostream>

class Vehicle
{
protected:
    std::string make, model;
    int speed;
public:
    Vehicle(std::string make, std::string model, int speed) : make(make), model(model), speed(speed) {}

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;
    
    std::string getMake() {return this->make;}
    std::string getModel() {return this->model;}
    int getSpeed() {return this->speed;}
};

class Car : public Vehicle
{
private:
    double fuelCapacity;
public:
    Car(std::string make, std::string model, int speed) : Vehicle(make, model, speed) {}

    void accelerate() override {this->speed += 5;}
    void brake() override {this->speed = 0;}
    void calculateFuelEfficiency() override {std::cout << "Fuel Efficiency: " << this->fuelCapacity / this->speed << std::endl;}
};

class Truck : public Vehicle
{
private:
    int cargoCapacity;
public:
    Truck(std::string make, std::string model, int speed) : Vehicle(make, model, speed) {}

    void accelerate() override {this->speed += 2;}
    void brake() override {this->speed = 0;}
    void calculateFuelEfficiency() override {std::cout << "Fuel Efficiency: 0" << std::endl;}
};

int main()
{

}