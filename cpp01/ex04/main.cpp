#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum ExitStatus
{
    Success = 0,
    IncorrectArgc,
    InfileError,
    OutfileError
};

static void checkArgc(int argc);
static void openInfile(std::fstream& infile, const char* infile_name);
static void openOutfile(std::fstream& outfile, std::string& outfile_name,
                        std::fstream& infile);
static void writeNewContentToOutfile(const char*   old_string,
                                     const char*   new_string,
                                     std::fstream& infile,
                                     std::fstream& outfile);

int main(int argc, char const* argv[])
{
    checkArgc(argc);

    std::fstream infile;
    openInfile(infile, argv[1]);

    std::string  outfile_name(std::string(argv[1]).append(".replace"));
    std::fstream outfile;
    openOutfile(outfile, outfile_name, infile);

    writeNewContentToOutfile(argv[2], argv[3], infile, outfile);

    infile.close();
    outfile.close();

    return 0;
}

static void checkArgc(int argc)
{
    if (argc != 4)
    {
        std::cerr << "ERROR: there should be three parameters: filename, old "
                     "string, new string.\n";
        std::exit(IncorrectArgc);
    }
}

static void openInfile(std::fstream& infile, const char* infile_name)
{
    infile.open(infile_name, std::fstream::in);
    if (infile.good() == false)
    {
        std::cerr << "ERROR: cannot open file " << infile_name << "\n";
        std::exit(InfileError);
    }
}

static void openOutfile(std::fstream& outfile, std::string& outfile_name,
                        std::fstream& infile)
{
    outfile.open(outfile_name.c_str(), std::fstream::out | std::fstream::trunc);
    if (outfile.good() == false)
    {
        infile.close();
        std::cerr << "ERROR: cannot open file " << outfile_name << "\n";
        std::exit(OutfileError);
    }
}

static void writeNewContentToOutfile(const char*   old_string,
                                     const char*   new_string,
                                     std::fstream& infile,
                                     std::fstream& outfile)
{
    std::string line;
    std::string old_s(old_string);
    std::string new_s(new_string);

    std::getline(infile, line);
    while (!(line.empty()))
    {
        size_t to_replace = line.find(old_s);
        while (to_replace != std::string::npos)
        {
            line.erase(to_replace, old_s.length());
            line.insert(to_replace, new_s);
            to_replace = line.find(old_s);
        }
        outfile << line << "\n";
        if (infile.eof())
            break;
        std::getline(infile, line);
    }
}
