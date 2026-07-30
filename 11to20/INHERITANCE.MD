
# Chapter 6 - Inheritance in C++

## 1. What is Inheritance?

- Real-life analogy
- Parent → Child relationship
- Why inheritance is used
- Code reusability
- IS-A relationship

Example

```cpp
class Animal
{
public:
    void eat()
    {
        cout << "Eating";
    }
};

class Dog : public Animal
{
};

int main()
{
    Dog d;

    d.eat();
}
```

Memory Diagram

```
Animal
---------
eat()

      ▲

Dog
---------
eat()
```

---

## 2. Why Do We Need Inheritance?

Without inheritance

- Duplicate code
- Hard to maintain

Example without inheritance

Example with inheritance

Comparison

---

## 3. Syntax of Inheritance

```cpp
class Derived : accessSpecifier Base
{

};
```

Meaning of

- Derived
- Base
- Access Specifier

---

## 4. Access Specifiers

### public

### private

### protected

Difference between them

```
              Same Class   Derived   Outside

public            ✔          ✔          ✔

protected         ✔          ✔          ✖

private           ✔          ✖          ✖
```

Examples of each.

---

## 5. Access Modes in Inheritance

### Public Inheritance

```
class Child : public Parent
```

Table

Parent Member      Child Becomes

public             public

protected          protected

private            Not Accessible

Example

```cpp
class Parent
{
public:
    int a=10;

protected:
    int b=20;

private:
    int c=30;
};

class Child : public Parent
{
public:

    void display()
    {
        cout<<a<<endl;
        cout<<b<<endl;

        // cout<<c; // Error
    }
};
```

---

### Protected Inheritance

```
class Child : protected Parent
```

Table

Parent Member      Child Becomes

public             protected

protected          protected

private            Not Accessible

Complete Example

---

### Private Inheritance

```
class Child : private Parent
```

Table

Parent Member      Child Becomes

public             private

protected          private

private            Not Accessible

Complete Example

---

## 6. Access Specifier vs Inheritance Mode

Most confusing topic.

Large comparison table.

Examples.

Interview trick questions.

---

## 7. Types of Inheritance

### Single

Diagram

```
A
|
B
```

Code

---

### Multilevel

```
A
|
B
|
C
```

Code

---

### Multiple

```
A      B
 \    /
   C
```

Code

---

### Hierarchical

```
      A
    / | \
   B  C  D
```

Code

---

### Hybrid

Diagram

Code

---

## 8. Constructor Calling Order

Example

```cpp
class A
{
public:
    A()
    {
        cout<<"A"<<endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout<<"B"<<endl;
    }
};

int main()
{
    B obj;
}
```

Output

```
A
B
```

Explanation

---

## 9. Destructor Calling Order

Example

Output

```Shell
B Destructor

A Destructor
```

Why reverse order?

---

## 10. Constructor with Parameters

Using initialization list

Example

---

## 11. Calling Base Class Constructor

Example

---

## 12. Function Overriding

Example

---

## 13. Hiding Base Class Members

Example

---

## 14. Base Class Pointer

```cpp
Parent *ptr;

Child obj;

ptr=&obj;
```

Explanation

---

## 15. Virtual Functions (Introduction)

Preview before polymorphism chapter.

---

## 16. Diamond Problem

Diagram

```
      A
     / \
    B   C
     \ /
      D
```

Problem

Solution using

```cpp
virtual public A
```

Memory diagram.

---

## 17. Virtual Base Class

Complete explanation

Examples

---

## 18. Important Interview Questions

- Difference between IS-A and HAS-A
- Why constructors aren't inherited
- Can private members be inherited?
- Why use protected?
- Constructor order?
- Destructor order?
- Diamond problem?
- Virtual inheritance?
- Multiple inheritance?
- Ambiguity?
- Which constructor executes first?
- Can derived class access private members?
- Why do we use `protected` instead of `private`?

---

## 19. Common Mistakes

Mistake 1

```cpp
class Child : private Parent
```

Expected

Public inheritance

Reality

Everything becomes private.

---

Mistake 2

Trying to access

```cpp
private
```

member.

---

Mistake 3

Confusing

Access Specifier

with

Inheritance Mode.

---

## 20. Practice Problems

10 Easy

10 Medium

5 Interview Level

---

## 21. Summary

Complete comparison tables

Cheat Sheet

Memory diagrams

Interview revision notes
