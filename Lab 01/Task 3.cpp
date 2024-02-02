#include <iostream>


int* indexAdd(int nums[], int size, int target);
int main()
{
	int size, target;
	std::cout << "Enter Array Size: ";
	std::cin >> size;
	int nums[size];
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Array[" << i << "]: ";
		std::cin >> nums[i];
	}
	std::cout << "Enter The Target: ";
	std::cin >> target;
	int* returnArray = new int[2];
	returnArray = indexAdd(nums, size, target);

	std::cout << "[" << returnArray[0] << ", " << returnArray[1] << "]";
}

int* indexAdd(int nums[], int size, int target)
{
	int add;
	int* tempArray = new int[2];
	for (int i = 0; i < size; ++i)
	{
		tempArray[0] = i;
		for (int j = i + 1; j < size; ++j)
		{
			add = nums[i];
			add += nums[j];
			if (add == target)
			{
				tempArray[1] = j;
				return tempArray;
			}
		}
	}
	tempArray[0] = -1;
	tempArray[1] = -1;
	return tempArray;
}