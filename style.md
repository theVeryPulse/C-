## [Con: Constants and immutability](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con-constants-and-immutability)
### Con.1: By default, make objects immutable
Function parameters passed by value are rarely mutated, but also rarely declared const. To avoid confusion and lots of false positives, don’t enforce this rule for function parameters.

```c++
void g(const int i) { ... }  // pedantic
```

### Con.2: By default, make member functions `const`
### Con.3: By default, pass pointers and references to `const`s
### Con.4: Use `const` to define objects with values that do not change after construction


### NL.16: Use a conventional class member declaration order
Reason

A conventional order of members improves readability.

When declaring a class use the following order
- types: classes, enums, and aliases (using)
- constructors, assignments, destructor
- functions
- data
