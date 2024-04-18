/**
 * Programmer: Muhammed Owais 
 * Desc: Q2, Character, Enemy
 * Date: 28/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>
#include <cstdlib>

class Player
{
public:
	int playerID, health;
	std::string playerName;
	Player(int playerID, std::string playerName) : playerID(playerID), playerName(playerName), health(100) {}
};

class Weapon
{
private:
	std::string weaponsList[5];
public:
	Weapon()
	{
		weaponsList[0] = "Sword";
		weaponsList[1] = "Bow";
		weaponsList[2] = "Staff";
		weaponsList[3] = "Axe";
		weaponsList[4] = "Dagger";
	}
	std::string use()
	{
		int in;
		std::cout << "Pick A Weapon: " << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			std::cout << i + 1 << "- " << weaponsList[i] << std::endl;
		}
		std::cout << "Input: ";
		std::cin >> in;
		return weaponsList[in - 1];
	}
};

class Enemy;
class Character : public Player, public Weapon
{
private:
	int level, points;
	std::string experience;
public:
	Character(int playerID, std::string playerName) : level(0), points(0), experience("Beginner"), Player(playerID, playerName) {}
	void levelUp()
	{
		if (points % 10 == 0)
		{
			if (experience == "Beginner")
			{
				experience = "Intermediate";
			}
			else if (experience == "Intermediate")
			{
				experience = "Advanced";
			}
			else if (experience == "Advanced")
			{
				experience = "Expert";
			}
			level++;
		}
	}
	void playGame(Enemy &enemy);
	int getHealth() {return health;}
	int getLevel() {return level;}
	std::string getExperience() {return experience;}
};

class Enemy : public Player
{
private:
	int damage;
public:
	Enemy(int playerID, std::string playerName) : damage(rand() % 10 + 1), Player(playerID, playerName) {}
	void attack(Character* character)
	{
		character->health -= damage;
	}
	int getHealth() {return health;}
	void setHealth(int health) {this->health -= health;}
};

void Character::playGame(Enemy &enemy)
{
	enemy.setHealth(-5);
	points += 10;
}

int main()
{
	srand(time(NULL));
	std::cout << "Muhammed Owais 23K-0047\n";
	Character myChar(12345, "Manoq");
	Enemy enemy(56789, "Not Manoq");
	std::string weapon = myChar.use();
	std::cout << "Character:\n" 
	<<"Player Id: " << myChar.playerID
	<<", Player Name: " << myChar.playerName
	<< ", Health: " << myChar.health
	<< ", Level: " << myChar.getLevel()
	<< ", Experience: " << myChar.getExperience() 
	<< ", Weapon: " << weapon << std::endl;

	std::cout << "Enemy:\n" 
	<<"Player Id: " << enemy.playerID
	<<", Player Name: " << enemy.playerName
	<< ", Health: " << enemy.health << std::endl;

	myChar.playGame(enemy);
	myChar.levelUp();
	std::cout << "PlayGame and Level Up:\n"; 
	std::cout << "Character:\n" 
	<<"Player Id: " << myChar.playerID
	<<", Player Name: " << myChar.playerName
	<< ", Health: " << myChar.health
	<< ", Level: " << myChar.getLevel()
	<< ", Experience: " << myChar.getExperience() 
	<< ", Weapon: " << weapon << std::endl;

	enemy.attack(&myChar);

	std::cout << "Enemy Attack: \n";
	std::cout << "Character:\n" 
	<<"Player Id: " << myChar.playerID
	<<", Player Name: " << myChar.playerName
	<< ", Health: " << myChar.health
	<< ", Level: " << myChar.getLevel()
	<< ", Experience: " << myChar.getExperience()
	<< ", Weapon: " << weapon << std::endl;

	std::cout << "Enemy:\n" 
	<<"Player Id: " << enemy.playerID
	<<", Player Name: " << enemy.playerName
	<< ", Health: " << enemy.health << std::endl;
}