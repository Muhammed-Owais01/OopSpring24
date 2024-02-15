/**
 * Programmer: Muhammed Owais 
 * Desc: Q4, Office Class
 * Date: 15/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class Office
{
private:
	string location;
	int seatingCapacity;
	string furniture[3];
public:
	Office()
	: location(" "), seatingCapacity(0), furniture{"", "", ""}
	{}

	Office(string area, int seatCapacity, string furn)
	: location(area), seatingCapacity(seatCapacity), furniture{furn, "", ""}
	{}

	Office(string area, int seatCapacity, string furn, string furn2)
	: location(area), seatingCapacity(seatCapacity), furniture{furn, furn2, ""}
	{}

	Office(string area, int seatCapacity, string furn, string furn2, string furn3)
	: location(area), seatingCapacity(seatCapacity), furniture{furn, furn2, furn3}
	{}
};

int main()
{
	Office office;
	Office office1("Room 1", 3, "Table");
	Office office2("Room 2", 5, "Table", "Cupboard");
	Office office3("Room 3", 7, "Table", "Cupboard", "Chairs");
}