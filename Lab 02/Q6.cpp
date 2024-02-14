/**
 * Programmer: Muhammed Owais 
 * Desc: GCD LCM by recursion
 * Date: 07/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b, int count);
int main()
{
	int a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "GCD: " << GCD(a, b) << endl;
	cout << "LCM: " << LCM(a, b, 1);
}

int GCD(int a, int b)
{
	// Euclids Division Algorithm
	if (b == 0)
		return a;
	if (a == 0)
		return b;

	return GCD(b, a % b);
}

int LCM(int a, int b, int count)
{
	// if count is completely divided by both then its the LCM number
	if (count % a == 0 && count % b == 0)
		return count;
	// else increase this number
	return LCM(a,b,count+1);
}