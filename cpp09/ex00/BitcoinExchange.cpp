#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : date_to_price_(other.date_to_price_)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        date_to_price_ = other.date_to_price_;
    return *this;
}

/**
 * @brief Checks if the beginning part of a string is correctly formatted
 *        string. YYYY-MM-DD
 *
 * @param line
 * @return true
 * @return false
 * @note
 * 2014-04-01
 * 0123 56 89 -> indexes of digits
 *     4  7   -> indexes of dashes
 */
bool BitcoinExchange::dateFormatOk(const std::string& line)
{
    const int number_indexes[] = {0, 1, 2, 3, 5, 6, 8, 9};
    const int dash_indexes[]   = {4, 7};

    for (size_t i = 0; i < sizeof(number_indexes) / sizeof(number_indexes[0]);
         ++i)
    {
        if (!std::isdigit(line[number_indexes[i]]))
            return false;
    }

    for (size_t i = 0; i < sizeof(dash_indexes) / sizeof(dash_indexes[0]); ++i)
    {
        if (line[dash_indexes[i] != '-'])
            return false;
    }

    return true;
}

void BitcoinExchange::printErrMsg(const std::string& err_msg)
{
    std::cerr << "error: " << err_msg << "\n";
}
