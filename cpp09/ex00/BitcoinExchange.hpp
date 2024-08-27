#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>

class BitcoinExchange
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------

    typedef std::map<std::string, double> Map;

    //----------------- Constructors, Assignments, Destructor ------------------

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    //------------------------------- Functions --------------------------------

    void readDatabase(const std::string& input_filename);
    void calculateBitcoinValue(const std::string& input_filename);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------

    double findPriceOnNearestDate(const std::string& date);

    static void printErrMsg(const std::string& err_msg);
    static bool dataLineFormatOk(const std::string& line);
    static bool inputLineFormatOk(const std::string& line);
    static bool dateFormatOk(const std::string& line);

    //---------------------------------- Data ----------------------------------

    Map date_to_price_;
};

#endif /* BITCOIN_EXCHANGE_HPP */

#if 0

bool operator<(const struct tm& left, const struct tm& right)
{
// clang-format off
    return (left.tm_year < right.tm_year) ? true :
           (left.tm_mon  < right.tm_mon)  ? true :
           (left.tm_mday < right.tm_mday) ? true :
           (left.tm_hour < right.tm_hour) ? true :
           (left.tm_min  < right.tm_min)  ? true :
           (left.tm_sec  < right.tm_sec)  ? true : false;
// clang-format on
}

bool operator>(const struct tm& left, const struct tm& right)
{
// clang-format off
    return (left.tm_year > right.tm_year) ? true :
           (left.tm_mon  > right.tm_mon)  ? true :
           (left.tm_mday > right.tm_mday) ? true :
           (left.tm_hour > right.tm_hour) ? true :
           (left.tm_min  > right.tm_min)  ? true :
           (left.tm_sec  > right.tm_sec)  ? true : false;
// clang-format on
}

bool operator==(const struct tm& left, const struct tm& right)
{
// clang-format off
    return left.tm_year == right.tm_year &&
           left.tm_mon  == right.tm_mon  &&
           left.tm_mday == right.tm_mday &&
           left.tm_hour == right.tm_hour &&
           left.tm_min  == right.tm_min  &&
           left.tm_sec  == right.tm_sec;
// clang-format on
}

std::ostream& operator<<(std::ostream& os, const struct tm& time)
{
// clang-format off
    os << time.tm_year + 1900 << '/'
       << time.tm_mon + 1 << '/'
       << time.tm_mday + 1 << " "
       << time.tm_hour << ":"
       << time.tm_min << ":"
       << time.tm_sec;
    return os;
// clang-format on
}

#endif