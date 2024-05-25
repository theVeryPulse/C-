#include <iostream>
#include <string>

/// @brief sadfasdf
class MyClass // The class
{
  public:                   // Access specifier
    int         my_num_;    // Attribute (int variable)
    std::string my_string_; // Attribute (string variable)

    MyClass(int num, std::string string) // constructor: a function with the
    {                                    // same name as class
        my_num_    = num;
        my_string_ = string;
        std::cout << "Hello!";
    }
    ~MyClass()
    {
        std::cout << "Goodbye!";
    }
    void printMessage();
    void myNum(int num);
    void setPrivateNum(int num);
    int  getPrivateNum();

  private:
    int PrivateNum;
};

void MyClass::printMessage()
{
    std::cout << "A message from my class\n";
}

void MyClass::myNum(int num)
{
    my_num_ = num;
}
void MyClass::setPrivateNum(int num)
{
    PrivateNum = num;
}
int MyClass::getPrivateNum()
{
    return PrivateNum;
}

int main(int argc, char const* argv[])
{
    MyClass my_object_(12, "Hello Class\n");

    std::cout << my_object_.my_num_ << " " << my_object_.my_string_;
    my_object_.printMessage();

    my_object_.setPrivateNum(10);
    std::cout << "Private number of my class is now "
              << my_object_.getPrivateNum() << '\n';

    return 0;
}
