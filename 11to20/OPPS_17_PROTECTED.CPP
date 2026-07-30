#include <iostream>
using namespace std;

class Parent
{
public:
    int a = 10;

protected:
    int b = 20;

private:
    int c = 30;
};

class Child : protected Parent
{
public:
    void display()
    {
        cout << a << endl;

        cout << b << endl;

        // cout << c; // Error
    }
};

int main()
{
    Child obj;

    obj.display();
    //public members of the parent class are not accessible in the main function by protected inheritance
    // cout << obj.a; // Error
    // protected members of the parent class are not accessible in the main function
    // cout << obj.a; // Error
}