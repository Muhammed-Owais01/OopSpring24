/**
 * Programmer: Muhammed Owais 
 * Desc: Q6, GameEngine
 * Date: 07/03/2024
 * Roll-No: 23K-0047
 */ 

#include <iostream>

class GameEngine
{
private:
	std::string renderEngine, inputHandle, physicsEngine;
public:
	GameEngine(std::string renderEngine, std::string inputHandle, std::string physicsEngine)
	{
		this->renderEngine = renderEngine;
		this->inputHandle = inputHandle;
		this->physicsEngine = physicsEngine;
	}
};

int main()
{
	std::string renderEngine = "UnrealEngine";
	std::string inputHandle = "WASD";
	std::string physicsEngine = "Random";
	GameEngine game_engine(renderEngine, inputHandle, physicsEngine);
}