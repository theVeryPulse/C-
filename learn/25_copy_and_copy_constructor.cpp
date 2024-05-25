#include <cstring>
#include <iostream>
#include <string>

class String
{
  public:
    String(const char* string)
    {
        size_   = strlen(string);
        buffer_ = new char[size_ + 1];
        memcpy(buffer_, string, size_ + 1);
    }
    ~String()
    {
        delete[] buffer_;
    }
    String(const String& other) : size_(other.size_)// Copy constructor
    {
        buffer_ = new char[size_ + 1];
        memcpy(buffer_, other.buffer_, size_ + 1);
    }

    const char* getBuffer() const
    {
        return buffer_;
    }
    char& operator[](size_t index)
    {
        return buffer_[index];
    }

  private:
    char*  buffer_;
    size_t size_;
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.getBuffer();
    return stream;
}

int main(int argc, char const* argv[])
{
    String string("Hello");
    String string2(string);

    string[2] = 'i';

    std::cout << string << "\n";
    std::cout << string2 << "\n";
    return 0;
}
