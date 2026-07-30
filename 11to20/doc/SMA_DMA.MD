
# Object Creation in C++: Compile Time vs Run Time (Stack vs Heap)

One of the biggest misconceptions among beginners is:

> **"If I use a pointer, does the object always get created at runtime?"**

**Answer:** ❌ No.

A **pointer** is just a variable that stores an address.

It is the **`new` operator**, not the pointer itself, that causes **dynamic (runtime) memory allocation**.

---

# Two Ways to Create Objects

There are two common ways to create objects.

## 1. Normal Object (Stack Allocation)

```cpp
Student s;
```

## 2. Dynamic Object (Heap Allocation)

```cpp
Student *ptr = new Student;
```

Although both create a `Student` object, they behave very differently.

---

# Case 1 : Normal Object (Non-Pointer Object)

```cpp
#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "Constructor Called\n";
    }

    ~Student()
    {
        cout << "Destructor Called\n";
    }
};

int main()
{
    Student s;

    return 0;
}
```

Output

```text
Constructor Called
Destructor Called
```

---

# What Happens at Compile Time?

When the compiler sees

```cpp
Student s;
```

it already knows

- The class `Student`
- Size of the object
- Constructor
- Destructor

Suppose

```cpp
sizeof(Student) = 24 bytes
```

#### The compiler reserves **24 bytes** inside the **stack** frame of

 `main()`.

Conceptually,

```text
main()

↓

Reserve 24 bytes on stack

↓

Object name = s
```

No operating system request is needed.

Everything is already known.

---

# What Happens at Run Time?

When execution reaches

```cpp
Student s;
```

the runtime performs:

```
Step 1

Reserve stack memory

↓

Step 2

Call Student Constructor

↓

Object Ready
```

Memory

```text
STACK

+------------------------+
| Student Object (s)     |
| rollNo                 |
| name                   |
| marks                  |
+------------------------+
```

When `main()` ends

```
Destructor

↓

Stack memory released automatically
```

No need to write

```cpp
delete
```

because the stack automatically manages memory.

---

# Case 2 : Pointer to Existing Object

```cpp
Student s;

Student *ptr = &s;
```

Many beginners think this creates another object.

It does **NOT**.

There is still only **one Student object**.

---

# Compile Time

Compiler reserves memory for

```
Student object

+

Pointer variable
```

Memory

```text
STACK

+--------------------+
| Student s          |
+--------------------+

+--------------------+
| ptr                |
+--------------------+
```

---

# Run Time

Execution

```cpp
ptr = &s;
```

means

```
Store address of s inside ptr
```

Suppose

```
Address of s = 1000
```

Memory

```text
STACK

Student s
Address = 1000

ptr

+--------+
| 1000   |
+--------+
```

No new object is created.

No heap memory is used.

No runtime allocation happens.

---

# Case 3 : Dynamic Object Using new

```cpp
Student *ptr = new Student;
```

This is completely different.

---

# What Happens at Compile Time?

Compiler knows

- Pointer type
- Constructor
- Destructor

Compiler only reserves memory for

```cpp
Student *ptr;
```

Memory

```text
STACK

+-----------+
| ptr        |
+-----------+
```

Notice

The Student object does **NOT** exist yet.

---

# What Happens at Run Time?

When execution reaches

```cpp
new Student
```

the following steps occur.

---

## Step 1

The `new` operator requests memory from the operating system.

```
Operating System

↓

Heap Manager

↓

Allocate Memory
```

---

## Step 2

Heap memory is allocated.

Suppose

```
Address = 5000
```

Memory

```text
HEAP

+----------------------+
| Student Object       |
+----------------------+
```

---

## Step 3

Constructor is automatically called.

```
Student Constructor
```

---

## Step 4

The address of the object is returned.

```
5000
```

---

## Step 5

Pointer stores that address.

```text
STACK

+---------+
| ptr      |
| 5000     |
+---------+
      |
      |
      V

HEAP

+----------------------+
| Student Object       |
+----------------------+
Address = 5000
```

Object is now ready.

---

# Complete Runtime Flow

```cpp
Student *ptr = new Student;
```

Conceptually

```
Declare Pointer

↓

Request Heap Memory

↓

Allocate Heap Memory

↓

Call Constructor

↓

Return Address

↓

Store Address in ptr
```

---

# Accessing the Object

```cpp
ptr->display();
```

Compiler interprets

```cpp
(*ptr).display();
```

Both are exactly the same.

---

# What Happens During delete?

```cpp
delete ptr;
```

Runtime performs

```
Call Destructor

↓

Free Heap Memory

↓

Object Destroyed
```

Memory

```text
STACK

ptr

+---------+
| 5000    |
+---------+

HEAP

Memory Freed
```

Notice

The pointer still contains

```
5000
```

but that memory no longer belongs to your program.

This is called a

> **Dangling Pointer**

Good practice

```cpp
delete ptr;

ptr = nullptr;
```

---

# Complete Memory Comparison

## Normal Object

```cpp
Student s;
```

Memory

```text
STACK

+----------------------+
| Student Object       |
+----------------------+
```

---

## Pointer to Existing Object

```cpp
Student s;

Student *ptr = &s;
```

Memory

```text
STACK

Student Object

+

Pointer

↓

Address of Student
```

Only one object exists.

---

## Dynamic Object

```cpp
Student *ptr = new Student;
```

Memory

```text
STACK

Pointer

↓

HEAP

Student Object
```

---

# Stack vs Heap

| Feature            | Stack       | Heap             |
| ------------------ | ----------- | ---------------- |
| Managed By         | Compiler    | Programmer       |
| Allocation         | Automatic   | Manual (`new`) |
| Deallocation       | Automatic   | `delete`       |
| Speed              | Fast        | Slower           |
| Lifetime           | Scope-based | Until`delete`  |
| Runtime Allocation | ❌ No       | ✅ Yes           |

---

# Summary Table

| Code                                | Object Created?              | Object Location | Pointer Location | Runtime Allocation? |
| ----------------------------------- | ---------------------------- | --------------- | ---------------- | ------------------- |
| `Student s;`                      | ✅ Yes                       | Stack           | —               | ❌ No               |
| `Student *ptr;`                   | ❌ No                        | —              | Stack            | ❌ No               |
| `Student *ptr = &s;`              | ❌ No (uses existing object) | Stack           | Stack            | ❌ No               |
| `Student *ptr = new Student;`     | ✅ Yes                       | Heap            | Stack            | ✅ Yes              |
| `Student *ptr = new Student[10];` | ✅ Yes (10 Objects)          | Heap            | Stack            | ✅ Yes              |

---

# Interview Questions

## Q1. Does a pointer always allocate memory dynamically?

**Answer:** No.

A pointer is just a variable that stores an address.

Only the `new` operator performs dynamic memory allocation.

---

## Q2. Where is the pointer stored?

Local pointers are stored on the **stack**, just like any other local variable.

---

## Q3. Where is the object created by `new` stored?

On the **heap**.

---

## Q4. Why do we need `delete`?

Objects created using `new` are **not destroyed automatically**.

The programmer must explicitly free the memory using

```cpp
delete ptr;
```

Otherwise, a **memory leak** occurs.

---

# Memory Trick

Remember this sentence:

> **Pointer ≠ Heap**

A pointer is **just an address holder**.

It is **`new`** that creates objects on the heap.

```
Student s;

↓

Object on Stack


Student *ptr = &s;

↓

Pointer to Stack Object


Student *ptr = new Student;

↓

Pointer to Heap Object
```

---

# Final Conclusion

Many beginners think:

```
Pointer

↓

Heap
```

This is **wrong**.

The correct relationship is:

```
Pointer

↓

Stores Address

↓

Address can point to

• Stack Object
• Heap Object
• Global Object
• Static Object
```

The **pointer never decides where the object is stored**.

The **way the object is created (`new` or normal declaration)** determines whether it lives on the **stack** or the **heap**.
