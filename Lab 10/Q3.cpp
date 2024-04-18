#include <iostream>

class Shape
{
public:
	int x;
	Shape(int x = 0) : x(x) {}

	int Area() {return x*x;}

	int operator+(Shape& obj)
	{
		return this->Area() + obj.Area();
	}
};

int main()
{
	Shape square1(5), square2(10);
	std::cout << square1 + square2 << std::endl;
}