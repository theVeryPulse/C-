#include "Span.hpp"
#include <vector>
#include <iostream>

int main()
{
    Span sp = Span(15);

    // std::cout << sp.longestSpan() << "\n";

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(2147483647);
    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan() << "\n";

    int arr[] = {23, 5, 19, 9, -2147483648};
    sp.addNumber(arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Shortest Span after adding more: " << sp.shortestSpan()
              << "\n"
              << "Longest Span after adding more: " << sp.longestSpan() << "\n";
    return 0;
}