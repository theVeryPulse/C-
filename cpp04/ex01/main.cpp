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
    Dog tmp = basic;
    tmp.changeIdea(0, "I am a temp.\n");
    std::cout << "Original: " << basic.sayIdea(0) << ".\n";
    std::cout << "Temp: " << tmp.sayIdea(0) << ".\n";

    Cat origin;
    Cat copy;
    copy = origin;

    Animal* animals[10];
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    std::cout << "\nAnimals created.\n\n";
    for (int i = 0; i < 10; ++i)
    {
        delete animals[i];
        animals[i] = NULL;
    }
    
    return 0;
}