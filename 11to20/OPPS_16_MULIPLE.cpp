#include <iostream>
using namespace std;

class Father
{
public:
    void car()
    {
        cout << "Father's Car" << endl;
    }
};

class Mother
{
public:
    void jewellery()
    {
        cout << "Mother's Jewellery" << endl;
    }
};

class Child : public Father, public Mother
{
public:
    void house()
    {
        cout << "Child's House" << endl;
    }
};

int main()
{
    Child c;

    c.car();
    c.jewellery();
    c.house();
}