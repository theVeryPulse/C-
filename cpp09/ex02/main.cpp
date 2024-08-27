#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <limits>
#include <stdexcept>

void printErrMsg(const std::string& msg, bool newline = true)
{
    std::cerr << "error: " << msg;
    if (newline)
        std::cerr << "\n";
}

void checkPositiveInt(const char** argv)
{
    for (const char** arg = argv; *arg != NULL; ++arg)
    {
        for (const char* c = *arg; *c != '\0'; ++c)
        {
            if (!isdigit(*c))
                throw std::invalid_argument(
                    "Arguments must be positive integers.");

            double             value;
            std::istringstream iss(*arg);
            iss >> value;
            if (value > std::numeric_limits<int>::max())
                throw std::invalid_argument("Argument outside integer range: "
                                            + std::string(*arg));
        }
    }
}

template<typename T>
void addIntegersToContainer(T& container, const char** argv)
{
    for (const char** arg = argv; *arg != NULL; ++arg)
        container.push_back(std::atoi(*arg));
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    os << "{";
    for (std::vector<int>::const_iterator num = vec.begin(); num != vec.end();
         ++num)
    {
        if (num != vec.begin())
            os << ", ";
        os << *num;
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& lst)
{
    os << "{";
    for (std::list<int>::const_iterator num = lst.begin(); num != lst.end();
         ++num)
    {
        if (num != lst.begin())
            os << ", ";
        os << *num;
    }
    os << "}";
    return os;
}

void checkDuplicates(const std::vector<int>& vec)
{
    std::vector<int> copy(vec);
    std::sort(copy.begin(), copy.end());
    for (std::vector<int>::const_iterator a = copy.begin(), b = copy.begin() + 1;
         b != copy.end(); ++a, ++b)
    {
        if (*a == *b)
            throw std::invalid_argument("Arguments contain duplicates.");
    }
}

int main(int argc, const char* argv[])
{
    if (argc == 1)
        return 0;
    const char** nums = argv + 1;
    try
    {
        checkPositiveInt(nums);
    }
    catch (const std::exception& e)
    {
        printErrMsg(e.what());
    }
    if (argc == 2)
        return 0;

    std::vector<int> arg_vec;
    addIntegersToContainer(arg_vec, nums);
    try
    {
        checkDuplicates(arg_vec);
    }
    catch (const std::exception& e)
    {
        printErrMsg(e.what());
    }

    std::list<int> arg_lst;
    addIntegersToContainer(arg_lst, nums);
    std::cout << "Original vector: " << arg_vec << "\n";
    std::cout << "Original list: " << arg_lst << "\n";

    PmergeMe pm;
    pm.sort(arg_vec);
    std::cout << "Sorted vector: " << arg_vec << "\n";
    pm.sort(arg_lst);
    std::cout << "Sorted list: " << arg_lst << "\n";
}
