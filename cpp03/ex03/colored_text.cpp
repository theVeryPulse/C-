#include "colored_text.hpp"
#include <string>

static std::string colorCode(Color color)
{
    switch (color)
    {
    case Black:
        return "\033[30m";
    case Red:
        return "\033[31m";
    case Green:
        return "\033[32m";
    case Yellow:
        return "\033[33m";
    case Blue:
        return "\033[34m";
    case Magenta:
        return "\033[35m";
    case Cyan:
        return "\033[36m";
    case White:
        return "\033[37m";
    default:
        return "\033[0m";
    }
}

/// @brief Returns text wrapped around in color notions for terminal. Supports
///        Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
/// @param color Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
/// @param text
/// @return
std::string coloredText(Color color, const std::string& text)
{
    return colorCode(color) + text + std::string("\033[0m");
}
