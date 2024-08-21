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
	for (size_t i = 0; i < sizeof(number_indexes) / sizeof(number_indexes[0]);
	     ++i)
	{
		if (!std::isdigit(line[number_indexes[i]]))
			return false;
	}
	if (line[4] != '-' || line[7] != '-')
		return false;
	return true;
}
