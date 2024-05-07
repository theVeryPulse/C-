#include <iostream>
#include <string>

struct Vector2
{
    Vector2(double x, double y) : x_(x), y_(y)
    {
    }

    Vector2 add(const Vector2& addend) const
    {
        return Vector2(x_ + addend.x_, y_ + addend.y_);
    }

    Vector2 multiply(const Vector2& multiplicand) const
    {
        return Vector2(x_ * multiplicand.x_, y_ * multiplicand.y_);
    }

    // Overload `+` with `add` function.
    Vector2 operator+(const Vector2& addend) const
    {
        return this->add(addend);
    }

    // Overload `*` with `multiply` function.
    Vector2 operator*(const Vector2& multiplicand) const
    {
        return this->multiply(multiplicand);
    }

    // Overload `==`
    bool operator==(const Vector2& other) const
    {
        return x_ == other.x_ && y_ == other.y_;
    }

    // Overload `!=`
    bool operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    double x_;
    double y_;
};

// Overload stream `<<` for Vector2 class: prints "x y"
std::ostream& operator<<(std::ostream& stream, const Vector2& vector)
{
    stream << vector.x_ << " " << vector.y_;
    return stream;
}

int main(int argc, char const *argv[])
{
    Vector2 position(4.0, 4.0);
    Vector2 speed(0.5, 1.5);
    Vector2 power_up(1.1, 1.1);

    Vector2 result1 = position.add(speed.multiply(power_up));
    Vector2 result2 = position + speed * power_up;

    std::cout << "Result 1: " << result1.x_ << " " << result1.y_ << "\n";
    std::cout << "Result 2: " << result2 << "\n";

    if (result1 == result2)
        std::cout << "Results are the same.\n";

    return 0;
}
