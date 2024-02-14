/**
 * Programmer: Muhammed Owais 
 * Desc: Finding subset through recursion
 * Date: 07/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

bool hasSubsetSum(int arr[], int size, int targetSum);
int main()
{
	int arr[5] = {2,1,3,5,4};

	(hasSubsetSum(arr, 5, 5)) ? "True" : "False";
}


bool hasSubsetSum(int arr[], int size, int targetSum)
{
	if (targetSum == 0)
		return true;

	if (size == 0 || targetSum < 0)
		return false;

	if (arr[size] > targetSum)
	{
		return hasSubsetSum(arr, size - 1, targetSum);
	}
	else
	{
		return hasSubsetSum(arr, size - 1, targetSum - arr[size]);
	}
}