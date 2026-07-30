#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int marks;

public:

    // Default Constructor
    Student()
    {
        cout << "Default Constructor Called\n";
    }

    // Parameterized Constructor
    Student(int rollNo, string name, int marks)
    {
        cout << "Parameterized Constructor Called\n";

        // 'this' pointer removes ambiguity
        this->rollNo = rollNo;
        this->name = name;
        this->marks = marks;
    }

    // Setter using this pointer
    Student& setData(int rollNo, string name, int marks)
    {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = marks;

        // Returning current object
        return *this;
    }

    // Display Function
    void display()
    {
        cout << "\n----- Student Details -----\n";

        cout << "Object Address (this) : " << this << endl;

        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << marks << endl;
    }

    // Show object's address
    void showAddress()
    {
        cout << "Address stored in this = " << this << endl;
    }

    ~Student()
    {
        cout << "Destructor Called for object at "
             << this << endl;
    }
};

int main()
{
    cout << "=============================\n";
    cout << "1. Normal Object\n";
    cout << "=============================\n";

    Student s1(101, "Dhruv", 95);

    s1.display();

    cout << "\nAddress using & operator : "
         << &s1 << endl;

    cout << endl;

    cout << "=============================\n";
    cout << "2. Object Pointer\n";
    cout << "=============================\n";

    Student *ptr = &s1;

    cout << "Pointer stores address : "
         << ptr << endl;

    cout << "\nUsing Pointer\n";

    ptr->display();

    cout << endl;

    cout << "Accessing Members Using Pointer\n";

    cout << "(*ptr).display()\n";

    (*ptr).display();

    cout << endl;

    cout << "ptr->display()\n";

    ptr->display();

    cout << endl;

    cout << "=============================\n";
    cout << "3. Dynamic Object\n";
    cout << "=============================\n";

    Student *p = new Student(102, "Rahul", 88);

    p->display();

    cout << endl;

    cout << "Deleting Dynamic Object\n";
    //IF you don't delete the dynamic object, then destructor will not be called and memory will not be freed.

    delete p;

    cout << endl;

    cout << "=============================\n";
    cout << "4. Method Chaining\n";
    cout << "=============================\n";

    Student s2;

    s2.setData(103, "Amit", 91)
      .display();

    cout << endl;

    cout << "=============================\n";
    cout << "5. this Pointer\n";
    cout << "=============================\n";

    s1.showAddress();

    s2.showAddress();

    cout << endl;

    cout << "Address of s1 : " << &s1 << endl;

    cout << "Address of s2 : " << &s2 << endl;

    return 0;
}