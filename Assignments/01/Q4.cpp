/**
 * Programmer: Muhammed Owais 
 * Desc: Scenario 4, RollerCoaster
 * Date: 23/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

// RollerCoaster class
class RollerCoaster {
private:
	string name;
	int height;
	int length;
	int speed;
	int capacity;
	int currentNumRiders;
	bool rideInProgress;
public:
	// Default Constructor
	RollerCoaster() 
	: name("roller coaster"), height(500), length(2000), capacity(20), speed(0), currentNumRiders(0), rideInProgress(false)
	{}
	// Parameterized Constructor
	RollerCoaster(string name, int height, int length, int speed, int currentNumRiders, int people) {
		this->name = name;
		this->height = height;
		this->length = length;
		this->speed = speed;
		this->currentNumRiders = currentNumRiders;

		// Capacity should be above 3
		if (people < 3) 
			this->capacity = 4;
		// Multiple of 2 or 3
		else if (people % 2 == 0 || people % 3 == 0)
			this->capacity = people;
		// Round of to closest multiple of 2
		else
			this->capacity = (people + 2 - (people % 2));
	}

	// SETTERS
	void setName(string name) { this->name = name; }
	void setHeight(int height) { this->height = height; }
	void setLength(int length) { this->length = length; }
	void setSpeed(int speed) { this->speed = speed; }
	void setCapacity(int capacity) {
		if (capacity < 3) 
			this->capacity = 4;
		else if (this->capacity % 2 == 0 || this->capacity % 3 == 0)
			this->capacity = this->capacity;
		else
			this->capacity = (this->capacity + 2 - (this->capacity % 2));
	}
	void setRiders(int currentNumRiders) { this->currentNumRiders = currentNumRiders; }
	void setProgress(bool rideInProgress) { this->rideInProgress = rideInProgress; }

	// GETTERS
	string getName() { return this->name; }
	int getHeight() { return this->height; }
	int getLength() { return this->length; }
	int getSpeed() { return this->speed; }
	int getCapacity() { 
		if (this->capacity < 3) 
			this->capacity = 4;
		else if (this->capacity % 2 == 0 || this->capacity % 3 == 0)
			this->capacity = this->capacity;
		else
			this->capacity = (this->capacity + 2 - (this->capacity % 2));
		return this->capacity; 
	}
	int getRiders() { return this->currentNumRiders; }
	bool getProgress() { return this->rideInProgress; }

	// Seat People
	int seatPeople() {
		int remaining;
		// If ride not in progress
		if (!rideInProgress)
			// If riders are more than capacity
			if (this->currentNumRiders > this->capacity) {
				// Remaining riders that could not be seated
				remaining = this->currentNumRiders - this->capacity;
				// Remaining capacity on ride now zero
				capacity = 0;
			}
			// If less than or equals to capacity
			else {
				remaining = 0;
				this->capacity -= this->currentNumRiders;
			}
		return remaining;
	}

	// Start the ride
	int startRide() {
		// If ride is in progress return -1
		if (this->rideInProgress) return -1;
		this->rideInProgress = true;

		// If capacity of the ride is not zero then return capacity
		if (this->capacity != 0) return this->capacity;

		return 0;
	}

	// Stop the ride
	void stopRide() { this->rideInProgress = false; }

	// Unload the ride
	int unloadPeople() {
		// Cannot unload when ride is in progress
		if (this->rideInProgress == true)
			return -1;
		else {
			// Add back the capacity to the ride
			this->capacity += this->currentNumRiders;
			return this->currentNumRiders;
		}
	}

	// Accelerate so increase the speed
	void accelerate(int rollNo) {
		int temp = rollNo % 10;
		while (temp == 0) {
			rollNo /= 10;
			temp = rollNo % 10;
		}
		this->speed += temp;
	}

	// Brake, so decrease the speed
	void brake(int rollNo) {
		int temp = rollNo % 10;
		while (temp == 0) {
			rollNo /= 10;
			temp = rollNo % 10;
		}
		this->speed -= temp;
	}


};

int main() {
	cout << "Name: Muhammed Owais\nStudent ID: 23K-0047\n\n";
	// Default constructor object
	RollerCoaster Coaster1;
	// Outputting all its attributes
	cout << "Coaster 1 is:\nName: " << Coaster1.getName()
		 << ", Height: " << Coaster1.getHeight() 
		 << ", Length: " << Coaster1.getLength() 
		 << ", Speed: " << Coaster1.getSpeed() 
		 << ", Capacity: " << Coaster1.getCapacity() 
		 << ", Riders: " << Coaster1.getRiders() 
		 << ", Progress: " << (Coaster1.getProgress() == true ? "Running\n" : "Stopped\n");

	// Parameterized Constructor Object
	RollerCoaster Coaster2("My Roller Coaster", 600, 3000, 10, 23, 30);
	// Outputting all its attributes
	cout << "Coaster 2 is:\nName: " << Coaster2.getName() 
		 << ", Height: " << Coaster2.getHeight() 
		 << ", Length: " << Coaster2.getLength() 
		 << ", Speed: " << Coaster2.getSpeed() 
		 << ", Capacity: " << Coaster2.getCapacity() 
		 << ", Riders: " << Coaster2.getRiders() 
		 << ", Progress: " << (Coaster2.getProgress() == true ? "Running\n" : "Stopped\n");

	// Changing the attributes through setters
	Coaster2.setName("Park 2 Red Coaster");
	Coaster2.setHeight(700);
	Coaster2.setLength(3100);
	Coaster2.setSpeed(12);
	Coaster2.setRiders(24);
	Coaster2.setCapacity(30);

	// Outputting the changes
	cout << "After Change:- \n";
	cout << "Coaster 2 is:\nName: " << Coaster2.getName() << ", Height: " << Coaster2.getHeight() << ", Length: " << Coaster2.getLength() << ", Speed: " << Coaster2.getSpeed() 
	<< ", Capacity: " << Coaster2.getCapacity() << ", Riders: " << Coaster2.getRiders() << ", Progress: " << (Coaster2.getProgress() == true ? "Running\n" : "Stopped\n");

	// Seating People
	int seatedPeople = Coaster2.seatPeople();
	if (seatedPeople == -1) cout << "Ride is moving cannot seat people\n";
	else cout << "Riders Seated Unsucessfully: " << seatedPeople << endl;

	// Starting the ride
	int startTheRide = Coaster2.startRide();
	if (startTheRide == -1) cout << "Ride Already In Progress: Cannot Start It\n";
	else cout << "Number of empty seats: " << startTheRide << endl;

	// Increasing the speed of the ride
	cout << "Speed Before: " << Coaster2.getSpeed() << endl;
	Coaster2.accelerate(0047);
	cout << "Speed After Acceleration: " << Coaster2.getSpeed() << endl;

	// Decreasing the speed of the ride
	cout << "Speed Before Brake: " << Coaster2.getSpeed() << endl;
	Coaster2.brake(0060);
	cout << "Speed After Brake: " << Coaster2.getSpeed() << endl;

	// Stopping the ride
	Coaster2.stopRide();
	
	// Unloading people from the ride
	int unloadedPeople = Coaster2.unloadPeople();
	if (unloadedPeople == -1) cout << "Cannot Unload People: Ride in Progress\n";
	else cout << "People Unloaded: " << unloadedPeople;
}