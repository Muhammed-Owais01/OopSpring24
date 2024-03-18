/**
 * Programmer: Muhammed Owais 
 * Desc: Q5, Course, Student
 * Date: 18/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

class Course
{
private:
	std::string courseCode, courseName;
	int creditHours;
public:
	// Getters
	std::string getCourseCode() {return courseCode;}
	std::string getCourseName() {return courseName;}
	int getCreditHours() {return creditHours;}

	void setCourseCode(std::string courseCode) {this->courseCode = courseCode;}
	void setCourseName(std::string courseName) {this->courseName = courseName;}
	void setCreditHours(int creditHours) {this->creditHours = creditHours;}
};

class Student
{
private:
	std::string studentID, studentName;
	Course courses[5];
	static int index;
public:
	Student(std::string studentID, std::string studentName) : studentID(studentID), studentName(studentName) {}

	void enroll()
	{
		Course course;
		std::string courseCode, courseName;
		int creditHours;
		std::cout << "Course Code: ";
		getline(std::cin, courseCode);

		std::cout << "Course Name: ";
		getline(std::cin, courseName);

		std::cout << "Creidt Hours: ";
		std::cin >> creditHours;

		course.setCourseCode(courseCode);
		course.setCourseName(courseName);
		course.setCreditHours(creditHours);

		courses[index] = course;
	}

	void drop()
	{
		Course course;
		std::string courseCode, courseName;
		int creditHours;
		std::cout << "Course Code: ";
		getline(std::cin, courseCode);

		std::cout << "Course Name: ";
		getline(std::cin, courseName);

		std::cout << "Creidt Hours: ";
		std::cin >> creditHours;

		for (auto i : courses)
		{
			if (i.getCourseCode() == courseCode && i.getCourseName() == courseName && i.getCreditHours() == creditHours)
			{
				i.setCourseCode("");
				i.setCourseName("");
				i.setCreditHours(-1);
				break;
			}
		}
	}

	int getTotalCreditHours()
	{
		int total = 0;
		for (auto i : courses)
		{
			total += i.getCreditHours();
		}
		return total;
	}

	void printEnrolledCourses()
	{
		for (auto i : courses)
		{
			std::cout << "Course Name: " << i.getCourseName() << ", Course Code: " << i.getCourseCode() << ", Credit Hours: " << i.getCreditHours() << std::endl;
		}
	}
};

int Student::index = 0;

int main()
{

}