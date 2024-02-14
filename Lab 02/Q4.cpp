#include <iostream>
#include <string>

using namespace std;

struct Register{
	int courseId;
	string courseName;
};

struct Student : Register{
	int studentId;
	string firstName;
	string lastName;
	int cellNo;
	string email;
};

int main()
{
	Student students[5];
	for (int i = 0; i < 5; ++i)
	{
		cout << "Student " << i + 1 << endl;
		cout << "Course Id: ";
		cin >> students[i].courseId;
		cout << "Course Name: ";
		cin >> students[i].courseName;
		cout << "Student Id: ";
		cin >> students[i].studentId;
		cout << "First Name: ";
		cin >> students[i].firstName;
		cout << "Last Name: ";
		cin >> students[i].lastName;
		cout << "Cell No: ";
		cin >> students[i].cellNo;
		cout << "Email: ";
		cin >> students[i].email;

		cout << "Student " << i + 1 << endl;
		cout << "Course Id: " << students[i].courseId << endl;;
		cout << "Course Name: " << students[i].courseName << endl;
		cout << "Student Id: " << students[i].studentId << endl;
		cout << "First Name: " << students[i].firstName << endl;
		cout << "Last Name: " << students[i].lastName << endl;
		cout << "Cell No: " << students[i].cellNo << endl;
		cout << "Email: " << students[i].email << endl;
	}
}