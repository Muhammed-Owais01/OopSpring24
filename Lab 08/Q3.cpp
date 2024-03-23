/**
 * Programmer: Muhammed Owais 
 * Desc: Q3, Character
 * Date: 21/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>

class Position
{
public:
	int x, y, z;
	Position(int x, int y, int z) : x(x), y(y), z(z) {}
};

class Health
{
public:
	int health;
	Health(int health) : health(health) {}
};

class Character : public Position, public Health
{
public:
	int damage, move;
	Character(int x, int y, int z, int health, int damage, int move) : Position(x, y, z), Health(health), damage(damage), move(move) {}	
	void moveChar() 
	{
		move += 5;
		std::cout << "Moved: " << move << std::endl;
	}
	void display()
	{
		std::cout << "X: " << x << ", Y: " << y << ", Z: " << z << ", Health: " << health << ", Damage: " << damage << ", Move: " << move;
	}
};

int main()
{
	Character myChar(1,2,3, 20, 5, 0);
	myChar.moveChar();

	myChar.display();
}