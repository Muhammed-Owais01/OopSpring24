/**
 * Programmer: Muhammed Owais 
 * Desc: Scenario 2, Tables
 * Date: 18/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <cstdlib>

using namespace std;

// Table class
class Tables {
private:
	// Attributes
	int seats;
	int occupied;
	int free;
	bool clean;
public:
	// Non Parameterized Constructor
	Tables()
	: seats(4), occupied(0), free(4), clean(true)
	{}
	// Parameterized constructor
	Tables(int seats) {
		// When parameter seats is not 4 or 8
		if (seats != 4 || seats != 8) {
			// set seats to 4 or 8 which ever the given number is closer to
			seats = (abs(8 - seats) < abs(4 - seats)) ? 8 : 4;
		}
		this->seats = seats;
		this->occupied = 0;
		this->clean = true;
		this->free = seats;
	}

	// Getters
	int getSeats() {return this->seats;}
	int getOccupied() {return this->occupied;}
	int getFree() {return this->free;}

	// Setters
	void setOccupied(int occupied) {this->occupied = occupied;}
	void setFree(int free) {this->free = free;}

	bool useTable(int size);
	void hadLunch(bool clean);
	void leaveTable() {this->occupied = 0;}
	void cleanTable() {(this->occupied == 0) ? ((this->clean = true), (this->free = this->seats)) : this->clean = false;}
};

// See if the table can be used
bool Tables::useTable(int size)
{
	// Clean the table if its not clean
	if (!this->clean)
		this->clean = true;

	// if group size is more than 4 occupy table with 8 seats
	if (size > 4 && this->seats == 8)
		return true;
	// if group size is less than or equals to 4 than occupy table with 4 seats
	else if (size <= 4 && this->seats == 4)
		return true;
	// return false if both conditions fail
	return false;
}

void Tables::hadLunch(bool clean)
{
	// if clean is true, then unclean the table
	if (clean)
		this->clean = false;
	else
		this->clean = true;
}

// To occupy a table 
int OccupyTable(Tables tables[], int size)
{
	// Loop through the whole array
	for (int i = 0; i < 5; ++i)
	{
		// see if the table can be occupied
		if (tables[i].useTable(size))
		{
			// set occupied to the size of people
			tables[i].setOccupied(size);
			// and free to remaining seats
			tables[i].setFree(tables[i].getSeats() - size);
			cout << "Table " << i + 1 << " has been occupied" << endl;
			cout << "Seats: " << tables[i].getSeats() << endl;
			return i;
		}
	}
	return -1;
}

void EmptyTable(Tables tables[], int tableNum)
{
	// Table empty so occupy 0
	tables[tableNum].setOccupied(0);
	// Clean the table and reset the free seats to actual seats on table
	tables[tableNum].cleanTable();
}

int main()
{
	cout << "Name: Muhammed Owais\n" << "Student ID: 23K-0047\n";

	int index;
	Tables tables[5];

	// Table 1
	tables[0] = Tables(8);
	// Table 2
	tables[1] = Tables(8);
	// Table 3
	tables[2] = Tables(4);
	// Table 4
	tables[3] = Tables(4);
	// Table 5
	tables[4] = Tables(4);

	// Table 1
	index = OccupyTable(tables, 4);
	if (index != -1)
	{
		tables[index].hadLunch(true);
		tables[index].leaveTable();
		tables[index].cleanTable();
	}

	// Table 2
	index = OccupyTable(tables, 6);
	if (index != - 1)
		EmptyTable(tables, index);
}