#include <iostream>

struct studentSbjcts
{
    int maths;
    int english;
    int science;
    int total;
    int avg;
};

int main()
{
    int num;
    std::cout << "No Of Students: ";
    std::cin >> num;
    studentSbjcts students[num];
    for (int i = 0; i < num; i++)
    {
        std::cout << "Student " + std::to_string(i + 1) << std::endl;
        std::cout << "Maths: ";
        std::cin >> students[i].maths;
        std::cout << "English: ";
        std::cin >> students[i].english;
        std::cout << "Science: ";
        std::cin >> students[i].science;
        students[i].total = students[i].maths + students[i].english + students[i].science;
        students[i].avg = students[i].total / 3;
    }

    std::cout << "\n\n Student Data: \n";

    for (int i = 0; i < num; i++)
    {
        std::cout << "Student " + std::to_string(i + 1) << std::endl;
        std::cout << "Maths: " + std::to_string(students[i].maths) << "\nEnglish: " + std::to_string(students[i].english)
         << "\nScience: " + std::to_string(students[i].science) << std::endl;
        std::cout << "Total: " + std::to_string(students[i].total) << "\nAverage: " + std::to_string(students[i].avg) << std::endl;
        if (students[i].avg >= 90)
            std::cout << "A";
        else if (students[i].avg >= 80)
            std::cout << "B";
        else if (students[i].avg >= 70)
            std::cout << "C";
        else if (students[i].avg >= 60)
            std::cout << "D";
        else
            std::cout << "F";
        std::cout << std::endl;
    }
    
}