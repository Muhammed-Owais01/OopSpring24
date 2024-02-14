#include <iostream>

using namespace std;

class Test{
public:
	int myFunc();
};

class User {
	string name;
	int age;
public:
	User(string name, int age) : name(name), age(age) {}

	void printInfo();
};

void User::printInfo() {
	cout << name << endl << age << endl;
}

int Test::myFunc() {return 1;}

int main(int argc, char const *argv[])
{
	Test obj = Test();

	cout << obj.myFunc() << endl;

	User obj1("Fasih", 18);

	obj1.printInfo();

	return 0;
}