/**
 * Programmer: Muhammed Owais 
 * Desc: Q2, Wizard
 * Date: 19/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>

class Character
{
public:	
	int health, damage;
	Character(int health, int damage) : health(health), damage(damage) {}
	void display() {std::cout << "Health: " << health << ", Damage: " << damage << std::endl;}
};

class Enemy : public Character
{
public:
	Enemy(int health, int damage) : Character(health, damage) {}
	void display() {std::cout << "Health: " << health << ", Damage: " << damage << std::endl;}
};

class Player : public Character
{
public:
	Player(int health, int damage) : Character(health, damage) {}
	void display() {std::cout << "Health: " << health << ", Damage: " << damage << std::endl;}
};

class Wizard : public Player
{
public:
	int magicPower;
	std::string spells;
	Wizard(int magicPower, std::string spells, int health, int damage) : magicPower(magicPower), spells(spells), Player(health, damage) {}
	void display() 
	{
		std::cout << "Health: " << health << ", Damage: " << damage << ", Magic Power: " << magicPower 
		<< ", Spells: " << spells << std::endl;
	}
};

int main()
{
	Wizard myWizard(100, "Fireball, Ice Shard", 150, 30);
	myWizard.display();
}