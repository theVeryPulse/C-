#include "BitcoinExchange.hpp"

static bool dateValueOk(const std::string& date)
{
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    else
        return true;
}

void BitcoinExchange::calculateBitcoinValue(const char* input_filename)
{
    std::ifstream input_file(input_filename);
    if (!input_file.is_open())
        handleError(Exit, "cannot open " + std::string(input_filename));
    std::string line;
    std::getline(input_file, line);
    if (line != "date | value")
        handleError(Exit, std::string(input_filename) + " has header: \"" +
                              line + "\". Expected header: \"date | value\".");
    while (!input_file.eof())
    {
        line.clear();
        std::getline(input_file, line);
        if (line.empty())
            continue;
        if (!inputLineFormatOk(line))
        {
            handleError(NoExit, "incorrect line format in " +
                                    std::string(input_filename) + " -> " +
                                    line);
            continue;
        }

        // Parses and checks date
        std::string date = line.substr(0, 10);
        if (!dateValueOk(date))
        {
            handleError(NoExit, "invalid date in line -> " + line);
            continue;
        }

        // Parses and checks coin amount
        double            coin_amount;
        std::stringstream ss;
        ss << line.substr(line.find('|') + 2, line.length());
        ss >> coin_amount;
        if (coin_amount == 0)
            continue;
        else if (coin_amount < 0 ||
                 coin_amount > std::numeric_limits<int>::max())
        {
            handleError(NoExit, "invalid coin amount in line -> " + line);
            continue;
        }

        // Finds price in map
        double        price;
        Map::iterator date_price = date_to_price_.find(date);
        if (date_price != date_to_price_.end())
            price = date_to_price_[date];
        else
            price = findPriceOnNearestDate(date);

        std::cout << date << " => " << coin_amount << " = "
                  << coin_amount * price << "\n";
    }
}

/**
 * @brief
 *
 * @param line
 * @return true
 * @return false
 * @note
 * 2011-01-03 | 1.2
 * 0123 56 89       -> indexes of digits
 *     4  7         -> indexes of dashes
 *           a c    -> indexes of spaces
 *            b     -> index of '|'
 *              d   -> index of begin of coin amount (int)
 * Shortest possible line has 14 characters:
 * "YYYY-MM-DD | 1"
 */
bool BitcoinExchange::inputLineFormatOk(const std::string& line)
{
    if (line.length() < 14)
        return false;
    if (!dateFormatOk(line))
        return false;
    std::string to_check = line.substr(0xa, 3);
    if (line.substr(0xa, 3) != " | ")
        return false;
    std::istringstream iss(line.substr(0xd, line.length()));
    double             amount;
    if (!(iss >> amount >> std::ws).eof())
        return false;
    return true;
}

static struct tm formatYearMonthDay(int year, int month, int day)
{
    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw std::logic_error("invalid date");
    struct tm time;
    time.tm_year   = year - 1900;
    time.tm_mon    = month - 1;
    time.tm_mday   = day - 1;
    time.tm_hour   = 0;
    time.tm_min    = 0;
    time.tm_sec    = 0;
    time.tm_gmtoff = 0;
    time.tm_isdst  = 0;
    return time;
}

static struct tm stringToDate(const std::string& str)
{
    int year  = atoi(str.substr(0, 4).c_str());
    int month = atoi(str.substr(5, 2).c_str());
    int day   = atoi(str.substr(8, 2).c_str());
    return formatYearMonthDay(year, month, day);
}

/**
 * @brief
 *
 * @param date
 * @return std::string
 * @note
 * YYYY-MM-DD
 * 0123456789
 * 0    5  8
 */
double BitcoinExchange::findPriceOnNearestDate(const std::string& date)
{
    struct tm tm_date = formatYearMonthDay(atoi(date.substr(0, 4).c_str()),
                                           atoi(date.substr(5, 2).c_str()),
                                           atoi(date.substr(8, 2).c_str()));

    time_t      time1                 = std::mktime(&tm_date);
    std::string nearest_date          = date_to_price_.begin()->first;
    double      price_of_nearest_date = date_to_price_.begin()->second;
    double      min_diff              = std::numeric_limits<double>::infinity();

    for (Map::const_iterator date_price = date_to_price_.begin();
         date_price != date_to_price_.end(); ++date_price)
    {
        struct tm date_item = stringToDate(date_price->first);
        double    time_diff = fabs(difftime(time1, mktime(&date_item)));
        if (time_diff < min_diff)
        {
            min_diff              = time_diff;
            price_of_nearest_date = date_price->second;
        }
        // When item is going away from the nearest date, break loop
        else if (time_diff > min_diff)
            break;
    }
    return price_of_nearest_date;
}
