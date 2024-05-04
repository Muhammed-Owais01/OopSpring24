#include <iostream>

template <typename T>
class Pet
{
private:
    std::string name;
    T age;
public:
    Pet(std::string name, T age) : name(name), age(age) {}

    virtual void makeSound() = 0;
    void display() {std::cout << name << ", " << age << std::endl;}
};

class Cat : public Pet<int>
{
public:
    Cat(std::string name, int age) : Pet(name, age) {}

    void makeSound() {std::cout << "Meow" << std::endl;}
};

class Dog : public Pet<int>
{
public:
    Dog(std::string name, int age) : Pet(name, age) {}

    void makeSound() {std::cout << "Woof" << std::endl;}
};

class Bird : public Pet<int>
{
public:
    Bird(std::string name, int age) : Pet(name, age) {}

    void makeSound() {std::cout << "Chirp" << std::endl;}
};

int main()
{
    Cat mittens("Mittens", 3);
    Dog buddy("Buddy", 5);
    Bird chirpy("Chirpy", 2);

    mittens.makeSound();
    mittens.display();
    buddy.makeSound();
    buddy.display();
    chirpy.makeSound();
    chirpy.display();
}