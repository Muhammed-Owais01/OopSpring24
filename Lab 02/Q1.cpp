/**
 * Programmer: Muhammed Owais 
 * Desc: Recursive swap
 * Date: 07/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;
void recursiveSwap(int &a, int &b, int swap);
int main()
{
	int a = 3;
	int b = 4;
	cout << "Before--- a: " << a << " b: " << b << endl;
	recursiveSwap(a, b, 1);
	cout << "After--- a: " << a << " b: " << b << endl;
}

void recursiveSwap(int &a, int &b, int swap)
{
	if (swap == 0)
		return;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	recursiveSwap(a, b, swap - 1);
}