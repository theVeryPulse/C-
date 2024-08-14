#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

Base* Base::generate()
{
    srand(time(0));
    int randomChoice = rand() % 3;
    switch (randomChoice)
    {
    case 0:
        std::cout << "Base: Generated A\n";
        return new A();
        break;
    case 1:
        std::cout << "Base: Generated B\n";
        return new B();
        break;
    case 2:
        std::cout << "Base: Generated C\n";
        return new C();
        break;
    default:
        throw std::runtime_error("Base: cannot generate random number\n");
        break;
    }
    return NULL;
}

void  Base::identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr))
        std::cout <<"Base: " << ptr << " is of type A\n";
    else if (dynamic_cast<B*>(ptr))
        std::cout <<"Base: " << ptr << " is of type B\n";
    else if (dynamic_cast<C*>(ptr))
        std::cout <<"Base: " << ptr << " is of type C\n";
    else
        throw std::runtime_error("Unknown type\n");
}

void  Base::identify(Base& ref)
{
    try
    {
        (void)dynamic_cast<A&>(ref);
        std::cout <<"Base: " << &ref << " is of type A\n";
        return;
    }
    catch (std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(ref);
        std::cout <<"Base: " << &ref << " is of type B\n";
        return;
    }
    catch (std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(ref);
        std::cout <<"Base: " << &ref << " is of type C\n";
        return;
    }
    catch (std::exception& e)
    {
    }
}

Base::Type Base::type()
{
    return BaseType;
}