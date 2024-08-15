# C++ Practice Repository

This repository contains various C++ practice exercises. Each directory (`CPP00` to `CPP09`) corresponds to a set of exercises focusing on different fundamental aspects of C++ programming. Below is an overview of the topics covered in each of these directories.

## Directory Overview

### CPP00: Basics of C++ Class
This module contains exercises about C++ class:

- **Class basics**: private and public scope, methods and member variables.
- **Constructor**: initialize object.
- **Stream Manipulation**: Baisc I/O. Using manipulators for formatting output, handling binary files.

### CPP01: Memory Allocation and Pointers
This module dives into the concepts of memory management in C++:

- **Pointers**: Understanding pointers, pointer arithmetic, and dereferencing.
- **Dynamic Memory Allocation**: `new` and `delete`, `new []` and `delete[]`.
- **References**: Introduction to references and their differences from pointers.
- **Pointer to Pointer**: Working with multi-level pointers.
- **File I/O Basics**: Opening, reading, writing, and closing files using file streams.

### CPP02: Object-Oriented Programming (OOP) Basics
Here, the focus is on the foundational concepts of Object-Oriented Programming:

- **Constructors and Destructors**: Understanding their roles in object lifecycle management.
- **Encapsulation**: The concept of data hiding using classes.
- **The `this` Pointer**: Introduction to the `this` pointer in class methods.
- **Operator Overload**: customize operators for class through overloading: `+` `-` `*` `/` `++` `--` `+=` `-=` `\=` `*=`.
- **File Steam Overload**: customize output for `<<` with file stream such as `std::cout`.

### CPP03: Inheritance and Polymorphism
This module expands on OOP concepts by introducing inheritance and polymorphism:

- **Inheritance**: Implementing base and derived classes, understanding `public`, `protected`, and `private` inheritance.
- **Multiple Inheritance**: Understanding the complexities of multiple inheritance and the diamond problem using virtual inheritance.


### CPP04: Inheritance and Polymorphism Practice
- **Inheritance**: Practice using abstract classes, inheritance, and virtual functions:
- **Abstract Classes and Interfaces**: Understanding pure virtual functions and abstract classes.


### CPP05: Exception Handling
This module covers exception handling and advances some OOP concepts:

- **Exception Handling**: `try`, `catch`, and `throw` keywords, creating custom exceptions with `std::exception`.


### CPP06: Type Cast
In this module, the focus is on type cast C++:

- `static_cast`: Basic cast between built-in types.
- `reinterpret_cast`: mostly used for casting between integer types and pointers.
- `dynamic_cast`: Used to cast pointer of base class to pointer of derived class. This cast could also be used check the type of target object.
