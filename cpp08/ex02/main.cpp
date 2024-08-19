#include "MutantStack.hpp"
#include <list>
#include <iostream>

void printnl()
{
    std::cout << "\n";
}

int main()
{
    {
        std::cout << "Simple iteration test:\n";
        MutantStack<int> ms;
        ms.push(1);
        ms.push(2);
        ms.push(3);
        ms.push(4);
        MutantStack<int>::iterator iter = ms.begin();
        for (int i = 0; i < 3; ++i)
        {
            std::cout << *iter << "\n";
            ++iter;
        }
    }
    printnl();
    {
        std::cout << "Comparison with std::list\n";
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        std::list<int>::iterator lst_iter = lst.begin();
        for (int i = 0; i < 3; ++i)
        {
            std::cout << *lst_iter << "\n";
            ++lst_iter;
        }
    }
    printnl();
    {
        MutantStack<int> ms;
        ms.push(5);
        ms.push(17);
        // std::cout << ms.top() << "\n";
        ms.pop();
        // std::cout << ms.size() << "\n";
        ms.push(3);
        ms.push(5);
        ms.push(737);
        // [...]
        ms.push(0);
        MutantStack<int>::iterator it = ms.begin();
        MutantStack<int>::iterator ite = ms.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << "\n";
            ++it;
        }
        std::cout << "Copy construct test: \n";
        MutantStack<int> ms1(ms);
        for (MutantStack<int>::iterator it = ms1.begin(); it != ms1.end(); ++it)
            std::cout << *it << "\n";
        std::cout << "Copy assignment test: \n";
        MutantStack<int> ms2;
        ms2 = ms;
        for (MutantStack<int>::iterator it = ms2.begin(); it != ms2.end(); ++it)
            std::cout << *it << "\n";
    }
    return 0;
}

