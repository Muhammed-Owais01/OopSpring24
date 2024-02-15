/**
 * Programmer: Muhammed Owais 
 * Desc: Q3, Calender class
 * Date: 15/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class Calender{
private:
	string january[30];
    string february[30]; 
    string march[30];
    string april[30];
    string may[30];
    string june[30];
    string july[30];
    string august[30];
    string september[30];
    string october[30];
    string november[30];
    string december[30];
public:
	void showMonthTasks(string month[30]) {
		for (int i = 0; i < 30; i++) {
			if (month[i].size() > 0) cout << i + 1 << ": "<< month[i] << endl;
		}
	}

	void showAllTasks();

	void setTask(int month, int date, string task);

	void removeTask(int date, int month);
};

void Calender::showAllTasks() 
{
	cout << "January: ";
	showMonthTasks(january);
	cout << "\n";

	cout << "February: ";
	showMonthTasks(february);
	cout << "\n";

	cout << "March: ";
	showMonthTasks(march);
	cout << "\n";

	cout << "April: ";
	showMonthTasks(april);
	cout << "\n";

	cout << "May: ";
	showMonthTasks(may);
	cout << "\n";

	cout << "June: ";
	showMonthTasks(june);
	cout << "\n";

	cout << "July: ";
	showMonthTasks(july);
	cout << "\n";

	cout << "August: ";
	showMonthTasks(august);
	cout << "\n";

	cout << "September: ";
	showMonthTasks(september);
	cout << "\n";

	cout << "October: ";
	showMonthTasks(october);
	cout << "\n";

	cout << "November: ";
	showMonthTasks(november);
	cout << "\n";

	cout << "December: ";
	showMonthTasks(december);

	cout << "\n";
}

void Calender::setTask(int month, int date, string task)
{
	switch(month) {
		case 1:
			january[date-1] = task;
			break;
		case 2:
			february[date-1] = task;
			break;
		case 3:
			march[date-1] = task;
			break;
		case 4:
			april[date-1] = task;
			break;
		case 5:
			may[date-1] = task;
			break;
		case 6:
			june[date-1] = task;
			break;
		case 7:
			july[date-1] = task;
			break;
		case 8:
			august[date-1] = task;
			break;	
		case 9:
			september[date-1] = task;
			break;
		case 10:
			october[date-1] = task;
			break;
		case 11:
			november[date-1] = task;
			break;
		case 12:
			december[date-1] = task;
			break;
	}
}

void Calender::removeTask(int date, int month)
{
	switch(month) {
		case 1:
			january[date-1] = "";
			break;
		case 2:
			february[date-1] = "";
			break;
		case 3:
			march[date-1] = "";
			break;
		case 4:
			april[date-1] = "";
			break;
		case 5:
			may[date-1] = "";
			break;
		case 6:
			june[date-1] = "";
			break;
		case 7:
			july[date-1] = "";
			break;
		case 8:
			august[date-1] = "";
			break;	
		case 9:
			september[date-1] = "";
			break;
		case 10:
			october[date-1] = "";
			break;
		case 11:
			november[date-1] = "";
			break;
		case 12:
			december[date-1] = "";
			break;
		cout << "TASK REMOVED!\n";
	}
}

bool checkDateValid(int day, int month)
{
	if ((day < 1 || day > 30) || (month < 1 || month > 12))
		return false;
	return true;
}

int main()
{
	Calender calender;

	int day, month, choice;
	string task;
	do
	{
		cout << "1: Add A Task\n"
			 << "2: Remove A Task\n"
			 << "3: Display All Tasks\n"
			 << "-1: Exit\n"
			 << "Input: ";
		cin >> choice;

		if (choice == 1 || choice == 2)
		{
			do 
			{
				cout << "Enter Month: ";
				cin >> month;
				cout << "Enter Day: ";
				cin >> day;
			} while (!checkDateValid(day, month));
		}

		if (choice == 1)
		{
			cout << "Task: ";
			cin.ignore();
			getline(cin, task);
			calender.setTask(month, day, task);
		}
		else if (choice == 2)
			calender.removeTask(day, month);
		else if (choice == 3)
			calender.showAllTasks();

	} while (choice != -1);

	
}