#include <iostream>
using namespace std;

//========================
// Base Class : Array
//========================
class Array
{
protected:
    int arr[10];
    int size;

public:
    Array()
    {
        size = 0;
    }

    // General insert function
    void insert(int index, int value)
    {
        if(size == 10)
        {
            cout << "Array Overflow!\n";
            return;
        }

        if(index < 0 || index > size)
        {
            cout << "Invalid Index!\n";
            return;
        }

        // Shift elements to the right
        for(int i = size; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = value;
        size++;
    }

    void display()
    {
        cout << "Array : ";

        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

//========================
// Derived Class : Stack
//========================
class Stack : protected Array
{
public:

    // Stack only allows insertion at the TOP
    void push(int value)
    {
        // Always insert at the end
        insert(size, value);

        cout << value << " pushed.\n";
    }

    void pop()
    {
        if(size == 0)
        {
            cout << "Stack Underflow!\n";
            return;
        }

        cout << arr[size - 1] << " popped.\n";
        size--;
    }

    void top()
    {
        if(size == 0)
        {
            cout << "Stack Empty!\n";
            return;
        }

        cout << "Top = " << arr[size - 1] << endl;
    }

    void show()
    {
        display();
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << endl;

    s.show();

    s.top();

    cout << endl;

    s.pop();

    s.show();

    // ❌ Not Allowed
    // s.insert(1, 100);

    // ❌ Not Allowed
    // s.display();

    return 0;
}