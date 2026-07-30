#include <iostream>
using namespace std;

// Base Class
class Animal
{
public:
    void eat()
    {
        cout << "Animal can eat." << endl;
    }
};

// Derived Class
class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog can bark." << endl;
    }
};

int main()
{
    Dog d;

    d.eat();    // Inherited
    d.bark();   // Own function

    return 0;
}