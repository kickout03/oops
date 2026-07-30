#include <iostream>
using namespace std;

//=========================================================
// BASE CLASS
//=========================================================
class Parent
{
public:

    // ---------- OVERLOADING ----------
    // Same function name, different parameters
    void show()
    {
        cout << "Parent :: show()" << endl;
    }

    void show(int x)
    {
        cout << "Parent :: show(int) = " << x << endl;
    }

    // Function to demonstrate overriding
    virtual void display()
    {
        cout << "Parent :: display()" << endl;
    }
};

//=========================================================
// DERIVED CLASS
//=========================================================
class Child : public Parent
{
public:

    //=====================================================
    // METHOD HIDING
    //=====================================================
    // This function hides ALL Parent::show() functions.
    void show(double x)
    {
        cout << "Child :: show(double) = " << x << endl;
    }

    //=====================================================
    // METHOD OVERRIDING
    //=====================================================
    // Same name + Same parameters + Same return type
    void display() 
    {
        cout << "Child :: display()" << endl;
    }
};

int main()
{
    cout << "==============================\n";
    cout << "1. METHOD OVERLOADING\n";
    cout << "==============================\n";

    Parent p;

    // Compiler chooses correct function
    p.show();

    p.show(100);



    cout << "\n==============================\n";
    cout << "2. METHOD HIDING\n";
    cout << "==============================\n";

    Child c;

    // Calls Child version
    c.show(5.5);

    /*
        These are hidden because Child has its own
        function named show().

        Uncomment to see compile-time error.

        c.show();

        c.show(10);
    */




    cout << "\n==============================\n";
    cout << "3. METHOD OVERRIDING\n";
    cout << "==============================\n";

    Parent *ptr;
    // Parent obj;
    c.display();
    ptr = &c;

    // Runtime Polymorphism
    ptr->display();

    return 0;
}