#pragma once
#ifndef COLORED_TEXT_HPP
#define COLORED_TEXT_HPP

enum Color
{
    Reset   = 0,
    Black   = 30,
    Red     = 31,
    Green   = 32,
    Yellow  = 33,
    Blue    = 34,
    Magenta = 35,
    Cyan    = 36,
    White   = 37,
};

std::string coloredText(Color color, const std::string& text);

#endif /* COLORED_TEXT_HPP */