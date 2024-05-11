#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

Harl::Harl()
{
    member_functions_['D' - 'A'] = &Harl::debug;
    member_functions_['I' - 'A'] = &Harl::info;
    member_functions_['W' - 'A'] = &Harl::warning;
    member_functions_['E' - 'A'] = &Harl::error;
}

void Harl::debug() const
{
    std::clog << "DEBUG: I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!\n";
}

void Harl::info() const
{
    std::clog
        << "INFO: I cannot believe adding extra bacon costs more money. You "
           "didn't put enough bacon in my burger! If you did, I wouldn't "
           "be asking for more!\n";
}

void Harl::warning() const
{
    std::cerr
        << "WARNING: I think I deserve to have some extra bacon for free. I've "
           "been coming for years whereas you started working here since "
           "last month.\n";
}

void Harl::error() const
{
    std::cerr
        << "ERROR: This is unacceptable! I want to speak to the manager now.\n";
}

Harl::function_ptr Harl::findFunction(const std::string& level) const
{
    if (level[0] - 'A' < 0 || level[0] - 'A' > 25)
        exit(1);
    return (member_functions_[level[0] - 'A']);
}

void Harl::complain(const std::string& level) const
{
    function_ptr function = findFunction(level);
    (this->*function)();
}
