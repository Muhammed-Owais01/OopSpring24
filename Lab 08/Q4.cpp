/**
 * Programmer: Muhammed Owais 
 * Desc: Q4, GraduateStudent
 * Date: 23/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>

class Person
{
public:
	std::string name;
	int age;
	Person(std::string name, int age) : name(name), age(age) {}
};

class Student : virtual public Person
{
public:
	int studentId, gradeLevel;
	Student(int studentId, int gradeLevel, std::string name, int age) : studentId(studentId), gradeLevel(gradeLevel), Person(name, age) {}
};

class Teacher : virtual public Person
{
public:
	std::string subject;
	int roomNum;
	Teacher(std::string subject, int roomNum, std::string name, int age) : subject(subject), roomNum(roomNum), Person(name, age) {}
};

class GraduateStudent : public Student, public Teacher
{
public:
	GraduateStudent(std::string name, int age, int studentId, int gradeLevel, std::string subject, int roomNum) 
	: Student(studentId, gradeLevel, name, age), Teacher(subject, roomNum, name, age), Person(name, age) {}

	void display()
	{
		std::cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentId 
		<< ", Grade Level: " << gradeLevel << ", Subject: " << subject << ", Room Number: " << roomNum << std::endl;
	}
};

int main()
{
	GraduateStudent newTeacher("Hassam", 40, 24090, 7, "Computer", 12);
	newTeacher.display();
}