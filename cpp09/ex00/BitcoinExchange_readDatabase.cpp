#include "BitcoinExchange.hpp"

static void checkHeader(const std::string& line, const std::string& filename);
static void checkFile(const std::ifstream& file, const std::string& filename);

void BitcoinExchange::readDatabase(const std::string& filename)
{
    std::ifstream data_file(filename.c_str());
    checkFile(data_file, filename);

    std::string line;
    std::getline(data_file, line);
    checkHeader(line, filename);

    while (!data_file.eof())
    {
        line.clear();
        std::getline(data_file, line);
        if (line.empty())
            continue;
        if (!dataLineFormatOk(line))
        {
            throw std::runtime_error("Incorrect line format in " + filename
                                     + " -> " + line);
        }
        std::string date = line.substr(0, 10); // YYYY-MM-DD -> 10 chars
        if (date_to_price_.find(date) != date_to_price_.end())
            throw std::runtime_error(date + " appeared twice.");

        double            price;
        std::stringstream ss(line.substr(line.find(',') + 1));
        ss >> price;
        if (price < 0)
            throw std::runtime_error("Invalid value in: " + line);
        date_to_price_[date] = price;
    }
}

/**
 * @brief
 *
 * @param line
 * @return true
 * @return false
 * @note
 * 2014-04-01,457.49
 * 0123 56 89       -> indexes of digits
 *     4  7         -> indexes of dashes
 *           a      -> index of comma
 *            b     -> index of begin of price (double)
 *  Shortest possible line has 12 characters:
 * "YYYY-MM-DD,1"
 */
bool BitcoinExchange::dataLineFormatOk(const std::string& line)
{
    bool format_ok = true;
    if (line.length() < 12)
        format_ok = false;
    else if (!dateFormatOk(line))
        format_ok = false;
    else if (line[0xa] != ',')
        format_ok = false;

    std::istringstream iss(line.substr(0xb, line.length()));
    double             price;
    if (!(iss >> price >> std::ws).eof())
        format_ok = false;
    return format_ok;
}

static void checkHeader(const std::string& line, const std::string& filename)
{
    if (line != "date,exchange_rate")
    {
        throw std::runtime_error(
            filename + " doesn't have expected header: \"date,exchange_rate\"");
    }
}

static void checkFile(const std::ifstream& file, const std::string& filename)
{
    if (!file.is_open())
        throw std::runtime_error("Cannot open " + filename);
}
