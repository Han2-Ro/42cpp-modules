#include <iostream>
#include <cctype>
#include <locale>
#include <string>
#include <vector>


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        std::wstring input(argv[1]);
        for (int i = 1; i < argc; i++)
        {
            for (const char *p = argv[i]; *p; ++p) {
                std::wcout << static_cast<char>(std::toupper(*p));
            }
        }
    }
    std::cout << std::endl;
    return 0;
}
