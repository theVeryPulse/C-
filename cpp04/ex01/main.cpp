#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    Animal* dog1 = new Dog();
    Animal* cat1 = new Cat();
    delete dog1; // should not create a leak
    delete cat1;

    Dog basic;
    {
        Dog tmp = basic;
    }

    Cat origin;
    Cat copy;
    copy = origin;
    return 0;
}