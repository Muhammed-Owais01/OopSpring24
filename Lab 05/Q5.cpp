/**
 * Programmer: Muhammed Owais 
 * Desc: Q5, Aggregation, Composition
 * Date: 06/03/2024
 * Roll-No: 23K-0047
 */ 

#include <iostream>

class CarComposition
{
private:
	int engine, wheels, headlights, steering;
public:
	CarComposition(int engine, int wheels, int headlights, int steering) : engine(engine), wheels(wheels), headlights(headlights), steering(steering) {}

	void setEngine(int engine) { this->engine = engine;}
	void setWheels(int wheels) { this->wheels = wheels;}
	void setHeadlights(int headlights) { this->headlights = headlights;}
	void setSteering(int steering) { this->steering = steering;}

	void print() { std::cout << "engine: " << this->engine << " wheels: " << this->wheels << " headlights: " << this->headlights << " steering: " << this->steering << std::endl;}
};

class CarAggregation
{
private:
	int *engine, *wheels, *headlights, *steering;
public:
	CarAggregation(int *engine, int *wheels, int *headlights, int *steering) : engine(engine), wheels(wheels), headlights(headlights), steering(steering) {}

	void setEngine(int engine)
	{ 
		this->engine = new int;
		*this->engine = engine;
	}
	void setWheels(int wheels) 
	{ 
		this->wheels = new int;
		*this->wheels = wheels;
	}
	void setHeadlights(int headlights) 
	{ 
		this->headlights = new int;
		*this->headlights = headlights;
	}
	void setSteering(int steering) 
	{ 
		this->steering = new int;
		*this->steering = steering;
	}

	void print() { std::cout << "engine: " << *this->engine << " wheels: " << *this->wheels << " headlights: " << *this->headlights << " steering: " << *this->steering << std::endl;}
};

int main()
{
	int engine = 1200, wheels = 4, headlights = 2, steering = 1;

	// Composition
	CarComposition car1(engine, wheels, headlights, steering);
	car1.print();

	// Aggregation
	CarAggregation car2(&engine, &wheels, &headlights, &steering);
	std::cout << "Aggregation:\n";
	car2.print();
	car2.setEngine(1400);
	std::cout << "Changed Engine Value: " << engine;

}