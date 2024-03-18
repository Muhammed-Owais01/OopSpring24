/**
 * Programmer: Muhammed Owais 
 * Desc: Q4, Inline Functions
 * Date: 18/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

inline float battingAverage(int runs, int dismissed);
inline float strikeRate(int runs, int balls);
int main()
{
	int runs, balls;
	std::cout << "Enter Runs: ";
	std::cin >> runs;
	std::cout << "Enter Balls: ";
	std::cin >> balls;

	std::cout << "Batting Average: " << battingAverage(runs, 5) << std::endl;
	std::cout << "Strike Rate: " << strikeRate(runs, balls) << std::endl;
}

inline float battingAverage(int runs, int dismissed)
{
	return (runs / dismissed);
}

inline float strikeRate(int runs, int balls)
{
	return (runs / balls) * 100;
}