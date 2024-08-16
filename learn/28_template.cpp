#include <iostream>

template <typename T> void print(T value)
{
    std::cout << value << "\n";
}

template <typename T, size_t N> class Array
{
  private:
    T array_[N];

  public:
    size_t getSize() const
    {
        return N * sizeof(T);
    }
};

int main()
{
    print(123);
    print(5.5);
    print("A String");

    Array<int, 3> int_array;
    print(int_array.getSize());
    return 0;
}
