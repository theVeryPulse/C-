#include "Span.hpp"

Span::Span() : size_(0)
{
}

Span::Span(unsigned int size) : size_(size)
{
}

Span::~Span()
{
}

Span::Span(const Span& other) : numbers_(other.numbers_), size_(other.size_)
{
}

Span& Span::operator=(const Span& other)
{
    size_ = other.size_;
    numbers_ = other.numbers_;
    return *this;
}

void Span::addNumber(int n)
{
    if (numbers_.size() == size_)
        throw std::length_error("Span: cannot add more number");
    numbers_.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if (numbers_.size() <= 1)
        throw std::logic_error("Span: not enough numbers to calculate span");
    std::vector<int> sorted(numbers_);
    std::sort(sorted.begin(), sorted.end());
#if SPAN_TEST
    for (unsigned int i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << "\n";
#endif
    long shortest_span = LONG_MAX;
    for (unsigned int i = 1; i < sorted.size(); ++i)
    {
        long difference = abs(sorted[i] - sorted[i - 1]);
#if SPAN_TEST
        std::cout << "diff: " << difference << "\n";
#endif
        if (difference < shortest_span)
            shortest_span = difference;
    }
    return static_cast<unsigned int>(shortest_span);
}

unsigned int Span::longestSpan()
{
    if (numbers_.size() <= 1)
        throw std::logic_error("Span: not enough numbers to calculate span");
    long max = *(std::max_element(numbers_.begin(), numbers_.end()));
    long min = *(std::min_element(numbers_.begin(), numbers_.end()));
    return static_cast<unsigned int>(max - min);
}
