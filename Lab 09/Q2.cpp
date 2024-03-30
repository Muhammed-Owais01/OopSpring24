#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Shape
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void displayProperties() const = 0;
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double radius) : radius(radius) {}
	double area() const {return M_PI * radius * radius;}
	double perimeter() const {return 2 * M_PI * radius;}
	void displayProperties()const 
	{
		cout << "Area: " << this->area() << endl
		<< "Perimeter: " << this->perimeter() << endl
		<< "Radius: " << this->radius << endl;
	}
};

class Rectangle : public Shape
{
private:
	double length, height;
public:
	Rectangle(double length, double height) : length(length), height(height) {}
	double area() const{return length * height;}
	double perimeter() const {return 2 * length + 2 * height;}
	void displayProperties() const
	{
		cout << "Area: " << this->area() << endl
		<< "Perimeter: " << this->perimeter() << endl
		<< "Length: " << this->length << endl
		<< "Height: " << this->height << endl;
	}
};

class Square : public Shape
{
private:
	double length;
public:
	Square(double length) : length(length) {}
	double area() const {return length * length;}
	double perimeter() const {return length * 4;}
	void displayProperties()const 
	{
		cout << "Area: " << this->area() << endl
		<< "Perimeter: " << this->perimeter() << endl
		<< "Length: " << this->length << endl;
	}
};

class Triangle : public Shape
{
private:
	double a, b, c;
public:
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
	double area() const {
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	double perimeter() const {return a + b + c;}
	void displayProperties()const 
	{
		cout << "Area: " << this->area() << endl
		<< "Perimeter: " << this->perimeter() << endl
		<< "Side 1: " << this->a << endl
		<< "Side 2: " << this->b << endl
		<< "Side 3: " << this->c << endl;
	}
};

class EquilateralTriangle : public Triangle
{
private:
	double side;
public:
	EquilateralTriangle(double side) : side(side) {}
	double area() const {
		const double constant = 0.43301270189f;
		return constant * side * side;
	}
	double perimeter() const {return 3 * side;}
	void displayProperties()const 
	{
		cout << "Area: " << this->area() << endl
		<< "Perimeter: " << this->perimeter() << endl
		<< "Side 1: " << this->a << endl
		<< "Side 2: " << this->b << endl
		<< "Side 3: " << this->c << endl;
	}
};

void display()
{
	cout << "Please select a shape: " << endl
	<< "1. Circle\n" 
	<< "2. Rectangle\n"
	<< "3. Square\n"
	<< "4. Triangle\n"
	<< "Enter your choice: "; 
}

void choice()
{
	
}

int main()
{
	Shape* shape;
	int choice;

	display();

}