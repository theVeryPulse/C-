#include <fstream>
#include <iostream>

int main()
{
    // Create and open a text file
    std::ofstream MyFile("file.txt");

    // Write to the file
    MyFile << "Writing into file\n";
    MyFile << "Content test\n";

    // Close the file
    MyFile.close();

    // Create a text string, which is used to output the text file
    std::string MyText;

    // Read from the text file
    std::ifstream MyReadFile("file.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline(MyReadFile, MyText))
    {
        // Output the text from the file
        std::cout << MyText + '\n';
    }

    // Close the file
    MyReadFile.close();
}
