#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
  public:
    // - types: classes, enums, and aliases (using)

    typedef void (Harl::*function_ptr)() const;

    // - constructors, assignments, destructor

    Harl();

    // - functions

    void complain(const std::string& level) const;

  private:
    // - functions

    void         debug() const;
    void         info() const;
    void         warning() const;
    void         error() const;
    function_ptr findFunction(const std::string& level) const;

    // - data

    function_ptr member_functions_[26];
};

#endif /* HARL_HPP */
