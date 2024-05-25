#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc, char const *argv[])
{
    time_t current_time = time(NULL);
    tm*    local_time   = localtime(&current_time);

    std::cout << "[" << local_time->tm_year + 1900
              << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1
              << std::setfill('0') << std::setw(2) << local_time->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << local_time->tm_hour
              << std::setfill('0') << std::setw(2) << local_time->tm_min
              << std::setfill('0') << std::setw(2)  << local_time->tm_sec
              << "] "; 
}
