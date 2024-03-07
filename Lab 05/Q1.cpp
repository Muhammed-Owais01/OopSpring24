/**
 * Programmer: Muhammed Owais 
 * Desc: Q1, Square Class
 * Date: 26/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

// Class Square 
class Square
{
private:
	float sideLength, area;
	static float allareas;
public:
	// Default Constructor
	Square() : sideLength(0), area(0) {}
	// Parameterized Constructor
	Square(int sideLength)
	{
		this->sideLength = sideLength;
	}

	// Calculating Area
	void calculateArea()
	{
		// Squaring sideLength
		this->area = this->sideLength * this->sideLength;
		allareas += area;
	}

	// Getters
    float getSideLength() const {return this->sideLength;}
    float getArea() const {return area;}
    static float getAllAreas() {return allareas;}

    // Setters
    void setSideLength(float sideLength) {this->sideLength = sideLength;}
    
};

float Square::allareas = 0;

int main()
{
	// Objects
	Square sq1(2);
	Square sq2(3);
	Square sq3(4);

	// Calculating their area
	sq1.calculateArea();
	sq2.calculateArea();
	sq3.calculateArea();

	// Displaying
	std::cout << "Square 1: " << sq1.getArea() << ", Square 2: " << sq2.getArea() << ", Square 3: " << sq3.getArea() << std::endl;
	std::cout << "All Areas: " << Square::getAllAreas();
}