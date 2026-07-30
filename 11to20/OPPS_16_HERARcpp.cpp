#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog Barking" << endl;
    }
};

class Cat : public Animal
{
public:
    void meow()
    {
        cout << "Cat Meowing" << endl;
    }
};

int main()
{
    Dog d;
    Cat c;

    d.eat();
    d.bark();

    c.eat();
    c.meow();
}