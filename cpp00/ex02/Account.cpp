#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0)
{
    ++(Account::_nbAccounts);
    Account::_totalAmount += initial_deposit;
    _displayTimestamp();
    // clang-format off
    std::cout << "index:"  << _accountIndex  << ";"
              << "amount:" << _amount        << ";created\n";
    // clang-format on
}

Account::~Account()
{
    _displayTimestamp();
    // clang-format off
    std::cout << "index:"  << _accountIndex << ";"
              << "amount:" << _amount       << ";closed\n";
    // clang-format on
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    // clang-format off
    std::cout << "index:"       << _accountIndex  << ";"
              << "p_amount:"    << _amount        << ";"
              << "deposit:"     << deposit        << ";";
    // clang-format on
    _amount += deposit;
    Account::_totalAmount += deposit;
    ++(Account::_totalNbDeposits);
    ++(_nbDeposits);
    // clang-format off
    std::cout << "amount:"      << _amount      << ";"
              << "nb_deposits:" << _nbDeposits  << "\n";
    // clang-format on
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    // clang-format off
    std::cout << "index:"    << _accountIndex << ";"
              << "p_amount:" << _amount       << ";";
    // clang-format on
    if (_amount < withdrawal)
    {
        std::cout << "withdrawal:refused\n";
        return false;
    }
    else
    {
        _amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        ++(_nbWithdrawals);
        ++(Account::_totalNbWithdrawals);
        // clang-format off
        std::cout << "withdrawal:"     << withdrawal     << ";"
                  << "amount:"         << _amount        << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << "\n";
        // clang-format on
        return true;
    }
}

int Account::checkAmount() const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    // clang-format off
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex  << ";"
              << "amount:"      << _amount        << ";"
              << "deposits:"    << _nbDeposits    << ";"
              << "withdrawals:" << _nbWithdrawals << "\n";
    // clang-format on
}

// Static functions

int Account::getNbAccounts()
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
    return Account::_totalAmount;
}

int Account::getNbDeposits()
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return Account::_totalNbWithdrawals;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos()
{
    _displayTimestamp();
    // clang-format off
    std::cout << "accounts:"    << Account::_nbAccounts         << ";"
              << "total:"       << Account::_totalAmount        << ";"
              << "deposits:"    << Account::_totalNbDeposits    << ";"
              << "withdrawals:" << Account::_totalNbWithdrawals << "\n";
    // clang-format on
}

void Account::_displayTimestamp(void)
{
    time_t current_time = time(NULL);
    tm*    local_time   = localtime(&current_time);
    // clang-format off
    std::cout << "["
              << local_time->tm_year + 1900
              << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1
              << std::setfill('0') << std::setw(2) << local_time->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << local_time->tm_hour
              << std::setfill('0') << std::setw(2) << local_time->tm_min
              << std::setfill('0') << std::setw(2) << local_time->tm_sec
              << "] ";
    // clang-format on
}
