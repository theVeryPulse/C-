#include "Fixed.hpp"
#include <cassert>
#include <iostream>

static void test_comparisons();
static void test_arithmetic();

int main()
{
    {
        Fixed       a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << "a is " << a << "\n";
        std::cout << "++a is " << ++a << "\n";
        std::cout << "a is now " << a << "\n";
        std::cout << "a++ is " << a++ << "\n";
        std::cout << "a is now " << a << "\n";
        std::cout << "b is " << b << "\n";
        std::cout << "b / Fixed(2) is " << (b / Fixed(2)) << "\n";
        std::cout << "Fixed(5.05)/Fixed(2) is " << (Fixed(5.05f) / Fixed(2))
                  << "\n";
        std::cout << "max(a,b) is " << Fixed::max(a, b) << "\n";
    }
    test_comparisons();
    test_arithmetic();
    return 0;
}

static void test_comparisons()
{
    Fixed a(5.75F);
    Fixed b(3.25F);
    Fixed c(5.75F);
    Fixed d(7.0F);

    // > operator
    assert(a > b);
    assert(d > a);

    // < operator
    assert(b < a);
    assert(a < d);

    // >= operator
    assert(a >= b);
    assert(a >= c);
    assert(d >= a);

    // <= operator
    assert(b <= a);
    assert(a <= c);
    assert(a <= d);

    // == operator
    assert(a == c);
    assert(!(a == b));
    assert(!(a == d));

    // != operator
    assert(a != b);
    assert(!(a != c));
    assert(a != d);
}

static void test_arithmetic()
{
    Fixed a(5.5F);
    Fixed b(3.25F);
    Fixed c(-2.5F);
    Fixed d(4.0F);
    Fixed e(2.25F);

    // + operator
    assert((a + b) == Fixed(8.75F));
    assert((a + c) == Fixed(3));
    assert((b + e) == Fixed(5.5F));

    // - operator
    assert((a - b) == Fixed(2.25F));
    assert((a - c) == Fixed(8));
    assert((b - e) == Fixed(1));

    // * operator
    assert((a * b) == Fixed(17.875F));
    assert((a * c) == Fixed(-13.75F));
    assert((d * e) == Fixed(9));

    // / operator
    assert((a / b) == Fixed(1.692307692307692F));
    assert((a / d) == Fixed(1.375F));

    // Edge cases (e.g., division by zero)
    try
    {
        Fixed f(0);
        Fixed result = a / f;
        assert(false); // Should not reach here
    }
    catch (std::exception& e)
    {
        // Expected behavior
        std::cout << "Catch exception: " << e.what() << "\n";
    }
}
