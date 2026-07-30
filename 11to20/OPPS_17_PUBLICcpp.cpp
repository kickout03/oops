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

class Child : public Parent
{
public:
    void display()
    {
        cout << "Public = " << a << endl;

        cout << "Protected = " << b << endl;

        // cout << c; // Error
    }
};

int main()
{
    Child obj;

    obj.display();

    cout << obj.a << endl;
// THE PROTECTED AND PRIVATE MEMBERS OF THE PARENT CLASS ARE NOT ACCESSIBLE IN THE MAIN FUNCTION
    // cout<<obj.b; // Error
}