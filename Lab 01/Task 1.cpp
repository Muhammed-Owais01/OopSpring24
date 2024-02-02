#include <iostream>

void prime(int num);

int main()
{
    int num;
    std::cout << "Number: ";
    std::cin >> num;
    prime(num);
}

void prime(int num)
{
    if (num == 1)
    {
        std::cout << "Prime!";
        return;
    }
    if (num == 2)
    {
        std::cout << "Prime!";
        return;
    }
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
        {
            std::cout << "Not Prime!";
            return;
        }
    std::cout << "Prime!";
}