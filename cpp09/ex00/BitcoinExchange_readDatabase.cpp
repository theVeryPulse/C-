#include "BitcoinExchange.hpp"

static bool headerOk(const std::string& line, const std::string& filename);
static bool fileOk(const std::ifstream& data_file, const char* filename);

void BitcoinExchange::readDatabase(const char* filename)
{
    std::ifstream data_file(filename);
    if (!fileOk(data_file, filename))
        exit(1);
    std::string line;
    std::getline(data_file, line);
    if (!headerOk(line, filename))
        exit(1);
    while (!data_file.eof())
    {
        line.clear();
        std::getline(data_file, line);
        if (line.empty())
            continue;
        if (!dataLineFormatOk(line, filename))
            std::exit(1);
        std::string date = line.substr(0, 10);
        if (date_to_price_.find(date) != date_to_price_.end())
            handleError(Exit, date + " appeared twice.");
        double            price;
        std::stringstream ss;
        ss << line.substr(line.find(',') + 1, line.length());
        ss >> price;
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
bool BitcoinExchange::dataLineFormatOk(const std::string& line,
                                       const std::string& filename)
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
    if (!format_ok)
        handleError(NoExit, "incorrect line format in " + filename + " -> "
                                + line);
    return format_ok;
}

static bool headerOk(const std::string& line, const std::string& filename)
{
    if (line != "date,exchange_rate")
    {
        std::cerr << "error: " << filename << " doesn't have expected header: "
                  << "\"date,exchange_rate\"\n";
        return false;
    }
    return true;
}

static bool fileOk(const std::ifstream& data_file, const char* filename)
{
    if (!data_file.is_open())
    {
        std::cerr << "error: cannot open " << filename << "\n";
        return false;
    }
    return true;
}
