#include <iostream>
using namespace std;

class Parent
{
public:
    int publicVar = 10;

protected:
    int protectedVar = 20;

private:
    int privateVar = 30;
};

// Public Inheritance
class PublicChild : public Parent
{
public:
    void show()
    {
        cout << "public: " << publicVar << endl;
        cout << "protected: " << protectedVar << endl;
        // cout << privateVar; // Error
    }
};

// Protected Inheritance
class ProtectedChild : protected Parent
{
public:
    void show()
    {
        cout << "public: " << publicVar << endl;
        cout << "protected: " << protectedVar << endl;
    }
};

// Private Inheritance
class PrivateChild : private Parent
{
public:
    void show()
    {
        cout << "public: " << publicVar << endl;
        cout << "protected: " << protectedVar << endl;
    }
};

class ProtectedChild2 : protected ProtectedChild
{
    public:
    void show()
    {
        cout << "public: " << publicVar << endl;
        cout << "protected: " << protectedVar << endl;
    }
};

int main()
{
    PublicChild p1;
    ProtectedChild p2;
    PrivateChild p3;
    ProtectedChild2 p4;

    cout << "Public Child\n";
    p1.show();

    cout << "\nProtected Child\n";
    p2.show();

    cout << "\nPrivate Child\n";
    p3.show();

    cout << "\nProtected Child 2\n";
    p4.show();
    // cout << "public: " << p4.publicVar << endl;
    // cout << "protected: " << p4.protectedVar << endl;

    cout << "\nOutside Class Access\n";
    cout << p1.publicVar << endl; // OK

    // cout << p2.publicVar; // Error
    // cout << p3.publicVar; // Error
}