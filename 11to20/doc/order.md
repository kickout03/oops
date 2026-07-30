
# Constructor and Destructor Order in Inheritance

## Rule 1: Constructor Order

When an object of a derived class is created:

1. Base class constructor executes first.
2. Then derived class constructor executes.

**Reason:** Before building the child part of an object, the parent part must already exist.

---

## Rule 2: Destructor Order

When an object is destroyed:

1. Derived class destructor executes first.
2. Then base class destructor executes.

**Reason:** The child part is destroyed first, and finally the parent part is destroyed.

---

# Example

```cpp
#include <iostream>
using namespace std;

//=========================
// Base Class
//=========================
class Animal
{
public:
    Animal()
    {
        cout << "Animal Constructor" << endl;
    }

    ~Animal()
    {
        cout << "Animal Destructor" << endl;
    }
};

//=========================
// Derived Class
//=========================
class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog Constructor" << endl;
    }

    ~Dog()
    {
        cout << "Dog Destructor" << endl;
    }
};

int main()
{
    cout << "Creating Object...\n\n";

    Dog d;

    cout << "\nMain Function Ends...\n";

    return 0;
}
```

---

# Output

```text
Creating Object...

Animal Constructor
Dog Constructor

Main Function Ends...

Dog Destructor
Animal Destructor
```

---

# Execution Flow

## Object Creation

When the compiler sees:

```cpp
Dog d;
```

It internally performs:

```text
Step 1
Construct Animal Part

↓

Step 2
Construct Dog Part

↓

Object Ready
```

So the output is:

```text
Animal Constructor
Dog Constructor
```

---

# Object Memory Layout

```
Dog Object

+-----------------------+
|      Animal Part      |
+-----------------------+
|        Dog Part       |
+-----------------------+
```

The **Animal** portion is created first because the **Dog** object contains an **Animal** object inside it.

---

# Object Destruction

When `main()` ends:

```text
Step 1
Destroy Dog Part

↓

Step 2
Destroy Animal Part

↓

Memory Released
```

Therefore the output becomes:

```text
Dog Destructor
Animal Destructor
```

---

# Why Does This Happen?

Imagine you're building a house.

```
Foundation
      ↓
Walls
      ↓
Roof
```

You **cannot build the roof before the foundation**.

Similarly:

```
Animal
      ↓
Dog
```

The base class must exist before the derived class can be constructed.

---

When demolishing the house:

```
Roof
      ↓
Walls
      ↓
Foundation
```

You remove the roof first and the foundation last.

The same happens with destructors:

```
Dog Destructor
      ↓
Animal Destructor
```

---

# Interview Rule ⭐

**Constructors execute from Base → Derived.**

```
Base
  ↓
Derived
```

**Destructors execute from Derived → Base.**

```
Derived
  ↓
Base
```

---

# Memory Trick

Think of inheritance as building a building.

```
Construction

Foundation
     ↓
First Floor
     ↓
Second Floor
```

```
Destruction

Second Floor
     ↓
First Floor
     ↓
Foundation
```

The same rule applies to inheritance:

```
Constructor  : Base → Derived
Destructor   : Derived → Base
```
