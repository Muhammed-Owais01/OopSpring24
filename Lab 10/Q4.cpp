#include <iostream>

class printClass;
class Perimeter {
private:
	float length, breadth;
	
	friend class printClass;
public:
	Perimeter(float l, float b) : length(l), breadth(b) {}
};

class printClass {
public:
	static void display(Perimeter& obj) {
		std::cout << 2*obj.length + 2*obj.breadth << std::endl;
	}
};

int main() {
	Perimeter p1(1, 2);
	printClass::display(p1);
	
	return 0;
}