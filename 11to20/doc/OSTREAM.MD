
# C++ Extraction (`>>`) and Insertion (`<<`) Operators

## Introduction

In C++, the operators `>>` and `<<` are used with streams for **input** and **output**.

- `>>` → **Extraction Operator** (Input)
- `<<` → **Insertion Operator** (Output)

These operators work with the standard stream objects:

- `cin` → Standard Input Stream
- `cout` → Standard Output Stream

---

# 1. Extraction Operator (`>>`)

The extraction operator is used to **read data from an input stream**.

### Syntax

```cpp
cin >> variable;
```

### Example

```cpp
#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Age = " << age;

    return 0;
}
```

### Output

```
Enter your age: 21
Age = 21
```

### Why is it called "Extraction"?

The operator **extracts** data from the input stream (`cin`) and stores it in a variable.

```
Keyboard
    │
    ▼
+---------+
|   cin   |
+---------+
    │
   >>
    │
    ▼
Variable
```

---

# Multiple Inputs

```cpp
int a, b;

cin >> a >> b;
```

Input

```
10 20
```

Internally, the compiler reads it as:

```cpp
operator>>(cin, a);
operator>>(cin, b);
```

---

# 2. Insertion Operator (`<<`)

The insertion operator is used to **send data to an output stream**.

### Syntax

```cpp
cout << variable;
```

### Example

```cpp
#include <iostream>
using namespace std;

int main()
{
    int marks = 95;

    cout << "Marks = " << marks;

    return 0;
}
```

### Output

```
Marks = 95
```

### Why is it called "Insertion"?

The operator **inserts** data into the output stream (`cout`) so it can be displayed on the screen.

```
Variable
    │
    ▼
   <<
    │
+---------+
|  cout   |
+---------+
    │
    ▼
Screen
```

---

# Multiple Outputs

```cpp
cout << "A = " << a << " B = " << b;
```

Internally, it behaves like:

```cpp
operator<<(cout, "A = ");
operator<<(cout, a);
operator<<(cout, " B = ");
operator<<(cout, b);
```

---

# Why Can We Chain Operators?

This works:

```cpp
cout << a << b << c;
```

because each call returns the stream object.

Conceptually:

```cpp
((cout << a) << b) << c;
```

Similarly,

```cpp
cin >> a >> b >> c;
```

is interpreted as

```cpp
((cin >> a) >> b) >> c;
```

Each operator returns the same stream, allowing another operation to follow.

---

# Stream Classes

```cpp
cin  -> istream  (Input Stream)

cout -> ostream  (Output Stream)
```

`istream` supports extraction (`>>`).

`ostream` supports insertion (`<<`).

---

# Operator Overloading

The `>>` and `<<` operators are overloaded for many data types.

Example:

```cpp
int x;
double y;
char ch;
string name;

cin >> x;
cin >> y;
cin >> ch;
cin >> name;
```

The compiler automatically chooses the correct overloaded operator.

---

# User-Defined Classes

You can overload these operators for your own classes.

Example:

```cpp
friend ostream& operator<<(ostream&, Student&);
friend istream& operator>>(istream&, Student&);
```

This allows:

```cpp
Student s;

cin >> s;
cout << s;
```

just like built-in data types.

---

# Summary

| Operator | Name       | Stream                 | Purpose                          |
| -------- | ---------- | ---------------------- | -------------------------------- |
| `>>`   | Extraction | `istream` (`cin`)  | Reads data from the input stream |
| `<<`   | Insertion  | `ostream` (`cout`) | Sends data to the output stream  |

---

# Interview Questions

### Why is `>>` called the extraction operator?

Because it extracts data from an input stream (`cin`) and stores it in a variable.

### Why is `<<` called the insertion operator?

Because it inserts data into an output stream (`cout`) so it can be displayed.

### Why does `cout << a << b` work?

Because `operator<<` returns the `ostream` object, enabling operator chaining.

### Can we overload `<<` and `>>`?

Yes. They are commonly overloaded as friend functions for user-defined classes.
