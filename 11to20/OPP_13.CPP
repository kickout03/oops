#include <iostream>
using namespace std;

// Forward declaration
class B;

class A
{
private:
    int a;

public:
    A(int x)
    {
        a = x;
    }

    // Friend function declaration
    friend void showSum(A, B);
};

class B
{
private:
    int b;

public:
    B(int y)
    {
        b = y;
    }

    // Friend function declaration
    friend void showSum(A, B);
};

// Friend function definition
void showSum(A x, B y)
{
    // Can access private data
    cout << "A = " << x.a << endl;
    cout << "B = " << y.b << endl;

    cout << "Sum = " << x.a + y.b << endl;
}
/*
A friend function is NOT a member of the class, but it is allowed to access the private and protected members of the class.

*/
int main()
{
    A obj1(10);
    B obj2(20);

    showSum(obj1, obj2);

    return 0;
}

