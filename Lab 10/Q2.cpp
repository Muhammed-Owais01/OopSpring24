#include <iostream>

class Base
{
public:
	int x;
	Base(int x = 0) : x(x) {}

	Base& operator--(int)
	{
		this->x /= 4;
		return *this;
	}

	Base& operator--()
	{
		this->x *= 4;
		return *this;
	}

	void display() { std::cout << x << std::endl;}
};

int main()
{
	Base b1(4);

	--b1;
	b1.display();

	b1--;
	b1.display();
}