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
    void fun(A &a, B &b);
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
    friend void A::fun(A&, B&);
};

void A::fun(A &x, B &y)
{
    // Can access private data
    cout << "A = " << x.a << endl;
    cout << "B = " << y.b << endl;

    cout << "Sum = " << x.a + y.b << endl;
}



int main()
{
    A obj1(10);
    B obj2(20);

    obj1.fun(obj1, obj2);

    return 0;
}

