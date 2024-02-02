#include <iostream>

int main()
{
	int n, ans;
	std::cout << "Enter Length: ";
	std::cin >> n;
	int height[n];
	for (int i = 0; i < n; ++i)
	{
		std::cout << "height[" << i <<"]: ";
		std::cin >> height[i];
	}
	int largest = height[0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (height[i] < height[j])
				ans = height[i] * (j - i);
			else if (height[j] < height[i])
				ans = height[j] * (j - i);
			else
				ans = height[i] * (j - i);

			if (ans > largest)
				largest = ans;
		}
	}
	std::cout << largest;
}