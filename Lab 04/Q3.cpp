/**
 * Programmer: Muhammed Owais 
 * Desc: Q3, WeekDays class
 * Date: 15/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class WeekDays
{
private:
	string days[7];
	int currentDay;
public:
	WeekDays()
	{
		this->days[0] = "Sunday";
		this->days[1] = "Monday";
		this->days[2] = "Tuesday";		
		this->days[3] = "Wednesday";		
		this->days[4] = "Thursday";		
		this->days[5] = "Friday";		
		this->days[6] = "Saturday";		
	}
	WeekDays(int currentDay)
	{
		(currentDay > 7) ? (this->currentDay = currentDay % 7) : (this->currentDay = currentDay);
		this->days[0] = "Sunday";
		this->days[1] = "Monday";
		this->days[2] = "Tuesday";		
		this->days[3] = "Wednesday";		
		this->days[4] = "Thursday";		
		this->days[5] = "Friday";		
		this->days[6] = "Saturday";	
	}
	string getCurrentDay()
	{
		return this->days[this->currentDay - 1];
	}
	string getNextDay()
	{
		return this->days[this->currentDay];
	}
	string getPreviousDay()
	{
		return this->days[this->currentDay - 2];
	}
	string getNthDayFromToday(int n)
	{
		(this->currentDay + n > 7) ? (this->currentDay = (n + this->currentDay) % 7) : (this->currentDay = n);
		return this->days[this->currentDay - 1];
	}
};

int main()
{

}