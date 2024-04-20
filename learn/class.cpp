#include <string>
#include <iostream>

/// @brief sadfasdf
class MyClass            // The class 
{
public:                  // Access specifier
    int MyNum;             // Attribute (int variable)
    std::string MyString;  // Attribute (string variable)
    MyClass(int Num, std::string String)              // constructor: a function with the same name
    {
        MyNum = Num;
        MyString = String;
    }
    void printMessage(void);

    void setNum(int Num)
    {
        PrivateNum = Num;
    }
    int getNum(void)
    {
       return PrivateNum;
    }
private:
    int PrivateNum;
};

void MyClass::printMessage(void)
{
    std::cout << "A message from my class\n";
}

int main(int argc, char const *argv[])
{
    MyClass MyObject(12, "Hello Class\n");

    std::cout << MyObject.MyNum << " " << MyObject.MyString;
    MyObject.printMessage();
    
    MyObject.setNum(10);
    std::cout << "Private number of my class is now " << MyObject.getNum()
        << '\n';
    
    return 0;
}
