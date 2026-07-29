# C++ Friend Functions and Operator Overloading

## What is a Friend Function?

A **friend function** is **not** a member of a class, but it is allowed to access the class's **private** and **protected** members.

Normally, private members cannot be accessed from outside a class.

```cpp
class A{
private:
    int a;
};

int main() {
    A obj;
    // cout << obj.a; // ❌ Error
}
```

A friend function is declared with the `friend` keyword inside the class.

---

## Why Use a Friend Function?

If two classes contain private data and one external function needs access to both, a friend function is a clean solution.

---

## Example 1: Simple Friend Function

```cpp
#include <iostream>
using namespace std;

class B;

class A {
private:
    int a;
public:
    A(int x){ a = x; }
    friend void showSum(A,B);
};

class B {
private:
    int b;
public:
    B(int y){ b = y; }
    friend void showSum(A,B);
};

void showSum(A x,B y){
    cout << "A = " << x.a << endl;
    cout << "B = " << y.b << endl;
    cout << "Sum = " << x.a + y.b << endl;
}

int main(){
    A a(10);
    B b(20);
    showSum(a,b);
}
```

---

## Friend Function + Operator Overloading

```cpp
#include <iostream>
using namespace std;

class B;

class A{
private:
    int a;
public:
    A(int x){ a=x; }
    friend int operator+(A,B);
};

class B{
private:
    int b;
public:
    B(int x){ b=x; }
    friend int operator+(A,B);
};

int operator+(A x,B y){
    cout<<"Adding objects...\n";
    cout<<"A = "<<x.a<<endl;
    cout<<"B = "<<y.b<<endl;
    return x.a+y.b;
}

int main(){
    A a(50);
    B b(5);

    int ans = a + b;
    cout<<"Answer = "<<ans<<endl;
}
```

### How it works

`a + b`

becomes internally:

```cpp
operator+(a,b);
```

Since it is a friend function, it can access:

```cpp
x.a
y.b
```

even though they are private.

---

## Why Forward Declaration?

```cpp
class B;
```

This tells the compiler that a class named `B` will be defined later.

Without it, the declaration

```cpp
friend int operator+(A,B);
```

would fail because `B` is still unknown.

---

## Important Rules

- Friend functions are **not member functions**.
- They can access **private** and **protected** members.
- Declare them inside the class using `friend`.
- Define them outside the class.
- Friendship is **not inherited**.
- Friendship is **not mutual**.
- Friendship is **not transitive**.

---

## Friend Function vs Friend Class

Friend function:

```cpp
friend void display();
```

Friend class:

```cpp
friend class Teacher;
```

A friend class gives **all** of its member functions access.

---

## Interview Questions

1. Why use friend functions?
2. Can they be inherited? → **No**
3. Can they be virtual? → **No**
4. Can they access private members? → **Yes**
5. Are they member functions? → **No**

---

# Can You Run C++ Code in a Markdown (.md) File?

**No.**

Markdown is a **documentation format**, not an executable program.

A fenced code block like:

```cpp
int main(){}
```

is only displayed with syntax highlighting.

### To run the code:

1. Copy it into a `.cpp` file.
2. Compile with:

```bash
g++ main.cpp -o main
```

3. Run:

```bash
./main
```

Or use an online compiler such as Compiler Explorer, OnlineGDB, or Programiz.

> VS Code can preview Markdown and let you copy code blocks, but it does not execute C++ directly from the `.md` file.
