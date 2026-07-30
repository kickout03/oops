#include <iostream>
using namespace std;

//=========================
// Base Class
//=========================
class Animal
{
public:
    Animal()
    {
        cout << "Animal Constructor" << endl;
    }

    ~Animal()
    {
        cout << "Animal Destructor" << endl;
    }
};

//=========================
// Derived Class
//=========================
class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog Constructor" << endl;
    }

    ~Dog()
    {
        cout << "Dog Destructor" << endl;
    }
};

int main()
{
    cout << "Creating Object...\n\n";

    Dog d;

    cout << "\nMain Function Ends...\n";

    return 0;
}