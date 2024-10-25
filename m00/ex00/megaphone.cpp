#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (const char *p = argv[i]; *p; ++p) {
                std::cout << static_cast<char>(std::toupper(*p));
            }
        }
    }
    std::cout << std::endl;
    return 0;
}